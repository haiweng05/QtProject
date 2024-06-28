#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QProcess>
#include <QFont>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::MainWindow),timer(new QTimer(this)),mycountdown(new CountDownTimer(this))
{
    // 窗口设计部分
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow { background-color: #add8e6; }");
    this->setWindowIcon(QIcon(":/icon.jpg"));
    setWindowTitle("Time Tracker");
    ui->_countdowntimer->show();
    ui->_pkumap->hide();

    // 日程倒计时提醒器的初始化
    connect(timer,&QTimer::timeout,this,&MainWindow::updateTimeDisplay);
    timer->start(1000);
    ui->timeDisplay->setReadOnly(true);
    updateTimeDisplay();

    // 菜单栏初始化

    // 日历选项
    menu_calendar = new QAction("日历",this);
    ui->menubar->addAction(menu_calendar);
    connect(menu_calendar,&QAction::triggered,this,&MainWindow::ShowCalendar);

    // 地图选项
    menu_map = new QAction("地图",this);
    ui->menubar->addAction(menu_map);
    connect(menu_map,&QAction::triggered,this,&MainWindow::ShowMap);

    // 说明选项
    menu_info = new QAction("说明",this);
    ui->menubar->addAction(menu_info);
    connect(menu_info,&QAction::triggered,this,&MainWindow::ShowInfo);

    // 表格内容的初始化
    ui->_table->setContextMenuPolicy(Qt::CustomContextMenu);
    AddRow(0);
    for(int i = 0; i < 4; ++ i){
        AddColumn(i);
    }
    AddItem(0,0,"起始时间");
    AddItem(0,1,"终止时间");
    AddItem(0,2,"事件");
    AddItem(0,3,"地点");

    // 打开并处理本地的节点,事件,保存的日程信息
    files.getNodes(QString("../Project/nodes.csv"));
    files.getActivities(QString("../Project/events.csv"));

    for(int i = 0; i < 7; ++ i){
        QString Set = files.readUserInfo(QString::number(i),"../Project/course.json",2);
        QStringList list = Set.split(';');
        for(auto Info:list){
            if(Info != ""){
                Event e(Info);
                classschedule.week[i].push_back(e);
            }

        }
    }

    // 初始化设置模块
    configs = new Config(this);

    // 推荐模块使用的辅助值
    adder = NULL;

    // 界面上的交互按钮

    // 选择新的一天时
    connect(ui->_calendar,&QCalendarWidget::activated,this,&MainWindow::oneday);

    // 导入课表
    connect(ui->_buttonInport,&QPushButton::clicked,this,&MainWindow::ClassImport);

    // 重新安排某一天
    connect(ui->_buttonModify,&QPushButton::clicked,this,&MainWindow::ActModify);

    // 个性化设置
    connect(ui->_buttonPersonalize,&QPushButton::clicked,this,&MainWindow::Personalize);

    // 表格交互设置
    connect(ui->_table, &QTableWidget::customContextMenuRequested, this, &MainWindow::onItemContextMenuRequested);

    // 个性化推荐
    connect(ui->_event,&QPushButton::clicked,this,&MainWindow::AddActivities);

    // 保存某一天
    connect(ui->_save,&QPushButton::clicked,this,&MainWindow::saveToJson);

    // 讲座信息
    connect(ui->_lecture,&QPushButton::clicked,this,&MainWindow::GetLecture);
}

MainWindow::~MainWindow()
{
    // 释放动态分配的内存
    delete menu_calendar;
    delete menu_map;
    delete menu_info;
}

std::vector<Event>* MainWindow::ClassSchedule(){
    return classschedule.week;
}

// 课表导入
void MainWindow::ClassImport(){
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("打开文件"), "", tr("Excel 文件 (*.xls *.xlsx)")); // 只允许选择 .xls 或 .xlsx 文件
    if (fileName.isEmpty()) { // 如果没有选择文件，直接返回
            return;
    }
    files.getClass(fileName,classschedule.week);
}
// 日历相关交互
void MainWindow::onedayHelper(QDate date,int ignore){
    if(Memo.find(date) != Memo.end()){
        tableclear();
        activities.clear();
        for(Event x: Memo[date]){
            activities.push_back(x);
            AddEvent(x);
        }
        return;
    }

    QString Set = files.readUserInfo(date.toString(),"../Project/activities.json",1);
    qDebug() << Set;
    QStringList list = Set.split(';');

    if(Set == "" || ignore == 1){
        int dayidx=(date.dayOfWeek()-2)%7+1;
        dayindex=(date.dayOfWeek()-2)%7+1;

        MainWindow::tableclear();

        activities.clear();
        for(Event x:classschedule.week[dayidx]){
            InsertEvent(x);;
        }

        if(configs->Mode() == 2){
            Bailan();
            return;
        }
        GetStudy();

        GetFood();
    }

    else{
        activities.clear();
        for(auto Info:list){
            if(Info != ""){

                Event e(Info);
                qDebug() << Info;
                InsertEvent(e);
            }
        }
    }

    Memo.insert(date,activities);
}

void MainWindow::oneday(const QDate&date){
    onedayHelper(date,0);
}

void MainWindow::ActModify() {
    QDate d = ui->_calendar->selectedDate();
    Memo.erase(Memo.find(d));
    onedayHelper(d,1);
}


// 日程表基础接口

void MainWindow::AddRow(int row){
    ui->_table->insertRow(row);
}
void MainWindow::AddColumn(int column){
    ui->_table->insertColumn(column);
}
template<typename T>
void MainWindow::AddItem(int row,int column,T item){
    QTableWidgetItem *it = new QTableWidgetItem(item);
    it->setTextAlignment(Qt::AlignCenter);
    ui->_table->setItem(row, column, it);
}

void MainWindow::AddEvent(Event& event){

    int nrow = ui->_table->rowCount();
    AddRow(nrow);
    AddItem(nrow,0,event.begin.toString());
    AddItem(nrow,1,event.end.toString());
    AddItem(nrow,2,event.Sname);
    AddItem(nrow,3,event.Sposition);
}

void MainWindow::tableclear(){
    int t=ui->_table->rowCount();
    for(int i=t-1;i>0;i--){
        ui->_table->removeRow(i);
    }
}

FileIO MainWindow::GetFile(){
    return files;
}

// 日历表高级接口
void MainWindow::InsertEvent(Event& event){
    activities.push_back(event);
    SortEvent();
    QString s = QString::number(event.iposition);
    files.saveUserInfo(s,"../Project/UserInfo.json",0,"");
}

// 不论是删除还是插入课程后都需要重新排序,如果我们只使用InsertEvent这个接口保证有序性，那这个函数不用实现
void MainWindow::SortEvent(){
    qDebug()<<activities.size()<<' '<<"kk"<<endl;
    std::sort(activities.begin(),activities.end());
    tableclear();
    for(Event u:activities){
        AddEvent(u);
    }
}

// 日程表交互接口
void MainWindow::onItemContextMenuRequested(const QPoint& pos) {
    QTableWidgetItem* selectedItem = ui->_table->itemAt(pos);
    if (selectedItem) {
        QMenu* menu = new QMenu(ui->_table);
        QAction* actiondelete = new QAction(tr("删除"), this);
        actiondelete->setData(1);
        menu->addAction(actiondelete);
        connect(actiondelete, &QAction::triggered, [this, selectedItem]() {
            onActiondeleteTriggered(selectedItem);
        });
        QAction* actionadd = menu->addAction("添加");
        connect(actionadd, &QAction::triggered, this,
            onActionaddTriggered);
        QAction* actioncancel = menu->addAction("取消");
        connect(actioncancel, &QAction::triggered, [this, selectedItem]() {
            onActioncancelTriggered(selectedItem);
        });
        QAction* actionrevise = menu->addAction("修改");
        connect(actionrevise, &QAction::triggered, [this, selectedItem,pos]() {
            onActionreviseTriggered(selectedItem);
        });
        // 添加更多菜单项...

        // 显示右键菜单
        menu->exec(QCursor::pos());
    }
}


void MainWindow::onActionreviseTriggered(QTableWidgetItem *item){
    int row=item->row();
    int col=item->column();
    if(col==0){
        QDialog *dialogrevise=new QDialog(this);
        QHBoxLayout* layout = new QHBoxLayout(dialogrevise);
        QPushButton* saveButton=new QPushButton("Save");
        layout->addWidget(saveButton);
        QTimeEdit* timeEdit=new QTimeEdit;
        layout->addWidget(timeEdit);
        connect(saveButton, &QPushButton::clicked, this, [=]() {
            (activities.begin()+row-1)->begin=timeEdit->time();
            dialogrevise->close();
        });
        dialogrevise->exec();
        SortEvent();
        }
    if(col==1){
        QDialog *dialogrevise=new QDialog(this);
        QHBoxLayout* layout = new QHBoxLayout(dialogrevise);
        QPushButton* saveButton=new QPushButton("Save");
        QTimeEdit* timeEdit=new QTimeEdit;
        layout->addWidget(saveButton);
        layout->addWidget(timeEdit);
        connect(saveButton, &QPushButton::clicked, this, [=]() {
            (activities.begin()+row-1)->end=timeEdit->time();
            dialogrevise->close();
        });
        dialogrevise->exec();
        SortEvent();
        }
    if(col==2){
        bool ok;
        QString text = QInputDialog::getText(nullptr, "Enter Text", "Please enter some text:", QLineEdit::Normal, "", &ok);

            if (ok && !text.isEmpty()) {
                activities[row-1].Sname=text;
                SortEvent();
            }
    }
    if(col==3){
        QComboBox* locationEdit = new QComboBox(ui->_table);
        for(auto nm:files.nameTint.keys()){
            locationEdit->addItem(nm);
        }
        QDialog *dialogrevise=new QDialog(this);
        QVBoxLayout* layout = new QVBoxLayout(dialogrevise);
        QPushButton* saveButton=new QPushButton("Save");
        layout->addWidget(saveButton);
        layout->addWidget(locationEdit);
        connect(saveButton, &QPushButton::clicked, this, [=]() {
            (activities.begin()+row-1)->Sposition=locationEdit->currentText();
            dialogrevise->close();
        });
        dialogrevise->exec();
        activities[row-1].iposition=files.nameTint[activities[row-1].Sposition];
        SortEvent();
    }
}


void MainWindow::onActiondeleteTriggered(QTableWidgetItem *item) {
    QDate d = ui->_calendar->selectedDate();
    int row = item->row();
    // 防止表头被删
    if(row == 0){
        return;
    }
//    ui->_table->removeRow(row);
    Memo[d].erase(Memo[d].begin()+row - 1);
    activities.erase(activities.begin()+row - 1);
    // 处理 Action 1 被触发的逻辑
    //qDebug() << "Action 1 triggered";
    SortEvent();
}


void MainWindow::onActioncancelTriggered(QTableWidgetItem *item){
    int row=item->row();
    activities[row].activate=0;
    for (int i = 0; i < ui->_table->columnCount(); i++) {
        QTableWidgetItem* item = ui->_table->item(row, i);
        if (item) {
            item->setBackground(QBrush(Qt::red));
        }
    }
    SortEvent();
}

void MainWindow::onActionaddTriggered(){
    AddHelper();
}


// 添加事件使用的辅助函数
void MainWindow::AddHelper(int idx){

    int rowcount=ui->_table->rowCount();
    // 把插入行放在我们实际确定添加后
    QDialog *dialogadd=new QDialog(this);

    dialogadd->setMinimumSize(480,640);
    dialogadd->setWindowTitle("Event Information");
    QVBoxLayout* layout = new QVBoxLayout(dialogadd);
    layout->addWidget(new QLabel("Start Time:"));
    QTimeEdit* stimeEdit = new QTimeEdit;
    stimeEdit->setDisplayFormat("hh:mm");
    layout->addWidget(stimeEdit);
    layout->addWidget(new QLabel("End Time:"));
    QTimeEdit* etimeEdit = new QTimeEdit;
    etimeEdit->setDisplayFormat("hh:mm");
    layout->addWidget(etimeEdit);
    layout->addWidget(new QLabel("Location:"));
    QComboBox* locationEdit = new QComboBox;
    for(auto nm:files.nameTint.keys()){
        locationEdit->addItem(nm);
    }

//    QLineEdit* locationEdit = new QLineEdit;
    layout->addWidget(locationEdit);
    layout->addWidget(new QLabel("Event:"));
    QLineEdit* eventEdit = new QLineEdit;
    layout->addWidget(eventEdit);
    QPushButton* saveButton = new QPushButton("Save");
    layout->addWidget(saveButton);

    if(idx != 3){
        if(event[idx].begin != QTime::fromString("00:00:05","hh:mm:ss")){
            stimeEdit->setTime(event[idx].begin);
            etimeEdit->setTime(event[idx].end);
        }
        locationEdit->setCurrentText(event[idx].Sposition);
        eventEdit->setText(event[idx].Sname);
    }

    connect(saveButton, &QPushButton::clicked, [=](){
            QTime stime = stimeEdit->time();
            QTime etime = etimeEdit->time();
            QString location = locationEdit->currentText();
            QString event = eventEdit->text();

            Event h;
            h.Sname=event;
            h.Sposition=location;
            h.begin=stime;
            h.end=etime;
            h.iposition=files.nameTint[location];
            if(Whetherclash(h.begin,h.end)){
                // 移动到这里
                  ui->_table->insertRow(rowcount);
                  InsertEvent(h);
            }

            else{

            }
            dialogadd->close();
        });
    dialogadd->exec();
}

bool MainWindow::Available(QTime t){
    for(auto event:activities){
        if(event.begin <= t && event.end >= t){
            qDebug() << "not available";
            return 0;
        }
    }
    qDebug() << "available";
    return 1;
}

bool MainWindow::Whetherclash(QTime begin,QTime end){
    if(configs->Answer()){
        return 1;
    }
    for(auto it=activities.begin();it!=activities.end();it++){
        if((it->end > begin and it->begin < begin) or (it->begin < end and it->end > end) or (it->begin <= begin && end <= it->end) or (begin <= it->begin && it->end <= end)){
            QMessageBox msgBox(QMessageBox::Warning, "事件时间冲突", "该事件时间发生冲突,暂时不能给你明确的答复,请你自己衡量。", QMessageBox::NoButton, this);
             msgBox.setIcon(QMessageBox::Warning);
            QPushButton* continueButton = msgBox.addButton("继续添加", QMessageBox::AcceptRole);
            QPushButton* discardButton = msgBox.addButton("放弃", QMessageBox::RejectRole);
            msgBox.exec();

                if (msgBox.clickedButton() == continueButton) {
                    return 1; // 继续添加
                } else if (msgBox.clickedButton() == discardButton) {
                    return 0; // 放弃
                }

                return 0; // 未点击任何按钮
            break;
        }
    }
    return 1;
}

// 日程表倒计时
void MainWindow::updateTimeDisplay(){
    QTime currentTime=QTime::currentTime();
    QString timeString;
    int idx = -1;
    for(int i = activities.size() - 1; i >= 0; -- i){
        if(activities[i].begin < currentTime){
            idx = i;
            break;
        }
    }
    if(idx!=-1&&idx!=activities.size()-1){
        QTime next=activities[idx+1].begin;
        qint64 msecs = currentTime.msecsTo(next);
        // 将毫秒转换为小时、分钟和秒
        int hours = msecs / (1000 * 60 * 60);
        int minutes = (msecs % (1000 * 60 * 60)) / (1000 * 60);
        int seconds = (msecs % (1000 * 60)) / 1000;
        // 格式化时间差
        timeString = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    }
    else if(activities.size()==0){
        timeString="日程未规划";
    }
    else{
        timeString="今日任务已完成";
    }
    // 设置 QLineEdit 的文本
    ui->timeDisplay->setText(timeString);
    ui->timeDisplay->setAlignment(Qt::AlignCenter);

    if(timeString=="00:10:00"){
       QMediaPlaylist* musicList=new QMediaPlaylist;
       musicList->addMedia(QMediaContent(QUrl("qrc:/sounds/bell.wav")));
       mediaPlayer.setPlaylist(musicList);
       qDebug() << "Played!";
       mediaPlayer.setVolume(80);
       mediaPlayer.play(); // 播放声音

       QWidget* jump = new QWidget();

       QLabel* pic = new QLabel(jump);
       QPixmap pixmap(configs->Dest());
       int h = pixmap.height();
       int w = pixmap.width();

       jump->setMinimumSize(w,h);
       pic->setPixmap(pixmap);

       jump->show();
    }
}

// 个性化设置
void MainWindow::Personalize(){
    configs->show();
}

// 获取单个自动推荐事件的封装函数
void MainWindow::GetSingle(QString name,QTime begin,QTime end,int type){
    QPair<int,int> curpos;
    QPair<int,int> nextpos;

    int idx = FirstBefore(begin);
    if(idx == -1){
        curpos = files.intTpos[files.nameTint[configs->Origin()]];
        if(activities.empty()){
            nextpos = files.intTpos[files.nameTint[configs->Origin()]];
        }
        else
        nextpos = files.intTpos[activities[0].iposition];
    }
    else if(idx != activities.size() - 1){
        curpos = files.intTpos[activities[idx].iposition];
        nextpos = files.intTpos[activities[idx + 1].iposition];
    }
    else{
        curpos = files.intTpos[activities[idx].iposition];
        nextpos = files.intTpos[files.nameTint[configs->Origin()]];
    }
    int iposition = 0;
    if(configs->Mode() == 0 && configs->Store()){
        iposition = Selection::PreferenceSelection(type);
    }
    else if(configs->Mode() == 0 && configs->Store() == 0){
        iposition = Selection::RandomSelection(type);
    }
    else{
        iposition = Selection::NearestSelection(type,curpos,nextpos);
    }
    QString Sposition = files.intTname[iposition];
    Event e(name,Sposition,iposition,begin,end);
    InsertEvent(e);

}

int MainWindow::FirstBefore(QTime t){
    int idx = -1;
    for(int i = activities.size() - 1; i >= 0; -- i){
        if(activities[i].end < t){
            idx = i;
            break;
        }
    }

    return idx;
}

void MainWindow::GetStudy(){
    qDebug() << "Now add Study";

    int Study = Selection::RandomInt(0,7);
    if(configs->Mode() == 1){
        Study = 7;
    }

    if(Study & 1){
        QTime time = QTime::fromString("09:00:00","hh:mm:ss");
        QTime from = time;
        QTime limit = QTime::fromString("11:35:00","hh:mm:ss");
        while(!Available(from) && from <= limit){
            from = from.addSecs(1800);
        }
        QTime to = from;
        while(Available(to) && to <= limit){
            to = to.addSecs(1800);
        }
        to = to.addSecs(-1800);
        if(from < to){
            GetSingle("自习",from,to,1);
        }
    }

    if(Study & 2){
        QTime time = QTime::fromString("12:30:00","hh:mm:ss");
        QTime j = QTime::fromString("11:35:00","hh:mm::ss");
        if(Available(j)){
            time = time.addSecs(-1800);
        }
        QTime from = time;
        QTime limit = QTime::fromString("17:35:00","hh:mm:ss");
        while(!Available(from) && from <= limit){
            from = from.addSecs(1800);
        }
        QTime to = from;
        while(Available(to) && to <= limit){
            to = to.addSecs(1800);
        }
        to = to.addSecs(-1800);
        if(from < to){
            GetSingle("自习",from,to,1);
        }
    }

    if(Study & 4){
        QTime time = QTime::fromString("18:30:00","hh:mm:ss");
        QTime j = QTime::fromString("17:35:00","hh:mm::ss");
        if(Available(j)){
            time = time.addSecs(-1800);
        }
        QTime from = time;
        QTime limit = QTime::fromString("21:35:00","hh:mm:ss");
        if(configs->Mode() == 1){
            limit = limit.addSecs(3600);
        }
        while(!Available(from) && from <= limit){
            from = from.addSecs(1800);
        }
        QTime to = from;
        while(Available(to) && to <= limit){
           to = to.addSecs(1800);
        }
        to = to.addSecs(-1800);
        if(from < to){
            GetSingle("自习",from,to,1);
        }
    }
}

void MainWindow::GetFood(){
    qDebug() << "Now add Food";
    // 处理早餐
    if(configs->Breakfast()){
        // 考虑错时优化，例如有早八可以是7：30，没有早八可以是8：30
        QString timeStr = "08:00:01";
        QTime time = QTime::fromString(timeStr, "hh:mm:ss");
        if(Available(time)){
            timeStr = "08:30:00";
        }
        else{
            timeStr = "07:30:00";
        }
        QTime beg = QTime::fromString(timeStr,"hh:mm:ss");
        QTime ed = beg.addSecs(1200);

        GetSingle("早餐",beg,ed,2);

    }
    // 处理中餐
    if(configs->Lunch()){
        // 考虑错时优化，例如上午最后没有课可以是11：30，有课可以是12：00
        QString timeStr = "11:59:59";
        QTime time = QTime::fromString(timeStr, "hh:mm:ss");
        if(Available(time)){
            timeStr = "11:30:00";
        }
        else{
            timeStr = "12:00:00";
        }
        QTime beg = QTime::fromString(timeStr,"hh:mm:ss");
        QTime ed = beg.addSecs(1200);
        GetSingle("中餐",beg,ed,2);
    }



    // 处理晚餐
    if(configs->Dinner()){
        // 考虑错时优化，例如下午最后没有课可以是17：30，有课可以是17：00 / 18：00
        QString timeStr = "17:59:59";
        QTime time = QTime::fromString(timeStr, "hh:mm:ss");
        if(Available(time)){
            timeStr = "17:30:00";
        }
        else{
            timeStr = "18:00:00";
        }
        QTime beg = QTime::fromString(timeStr,"hh:mm:ss");
        QTime ed = beg.addSecs(1200);
        GetSingle("晚餐",beg,ed,2);

    }


}

void MainWindow::Bailan(){
    tableclear();
    int nrow = ui->_table->rowCount();
    AddRow(nrow);

    AddItem(nrow,0,"00:00:00");
    AddItem(nrow,1,"24:00:00");
    AddItem(nrow,2,"摆烂");
    AddItem(nrow,3,configs->Origin());
}

void MainWindow::AddActivities(){
    if(adder != NULL){
        adder->close();
    }
    QDate d = ui->_calendar->selectedDate();
    int idx = d.dayOfWeek();
    std::vector<Event> events = files.events[idx];
    std::vector<int> random_choice;
    while(random_choice.size() < 3 && !events.empty()){
        int temp = Selection::RandomInt(0,events.size() - 1);
        random_choice.push_back(temp);
    }

    for(int i = 0; i < 3; ++ i){
        event[i] = events[random_choice[i]];
        if(event[i].Sposition == "origin"){
            event[i].Sposition = configs->Origin();
            event[i].iposition = files.nameTint[event[i].Sposition];
        }
    }

    QString line[3];
    for(int i = 0; i < 3; ++ i){
        line[i] = "事件: " + QString(event[i].Sname) + " , " + "地点: " + QString(event[i].Sposition) + " , 时间: ";
        if(event[i].begin == QTime::fromString("00:00:05","hh:mm:ss")){
                line[i] += "任意";
        }
        else{
            line[i] += event[i].begin.toString() + '-' + event[i].end.toString();
            qDebug() << event[i].begin.toString() << event[i].end.toString();
        }
    }
    QWidget* window = new QWidget();
    window->setWindowTitle("选择事件");
    window->setMinimumSize(960,720);
    adder = window;

    QPushButton *button1 = new QPushButton();

    QPushButton *button2 = new QPushButton();
    QPushButton *button3 = new QPushButton();
    QPushButton *remake = new QPushButton();

    button1->setMinimumSize(320,64);
    button2->setMinimumSize(320,64);
    button3->setMinimumSize(320,64);
    remake->setMinimumSize(320,64);

    button1->setText(line[0]);
    button2->setText(line[1]);
    button3->setText(line[2]);
    remake->setText("重开");

    connect(button1, &QPushButton::clicked, this, &MainWindow::onButton1Clicked);
    connect(button2, &QPushButton::clicked, this, &MainWindow::onButton2Clicked);
    connect(button3, &QPushButton::clicked, this, &MainWindow::onButton3Clicked);
    connect(remake,&QPushButton::clicked,this,&MainWindow::AddActivities);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(remake);

    window->setLayout(layout);
    window->show();

}

void MainWindow::onButton1Clicked() {
    AddHelper(0);
    adder->close();
}

void MainWindow::onButton2Clicked() {
    AddHelper(1);
    adder->close();
}

void MainWindow::onButton3Clicked() {
    AddHelper(2);
    adder->close();
}

void MainWindow::saveToJson(){
    QDate d = ui->_calendar->selectedDate();
    QString idx = d.toString();
    QString Info;
    for(auto ele:activities){
        Info += ele.ToInfo();
    }
    files.saveUserInfo(idx,"../Project/activities.json.",1,Info);
}

// 关于菜单栏的交互部分

// 每次切换时我们需要将所有上层的页面都关闭
void MainWindow::HideAll(){
    HideMap();
    HideCalendar();
}

// 关于地图的交互

QWidget*& MainWindow::pkumap(){
    return _pkumap;
}

void MainWindow::ShowMap(){
    HideAll();
    ui->_pkumap = new PKUMap(this,activities,files.intTpos,files.intTpos[files.nameTint[configs->Origin()]]);
    ui->_pkumap->move(0,60);
    ui->_pkumap->show();
}

void MainWindow::HideMap(){
    ui->_pkumap->hide();
}

// 关于说明的交互
void MainWindow::ShowInfo(){
    QDesktopServices::openUrl(QUrl("https://github.com/haiweng05/QtProject"));
}

// 关于日历的交互
void MainWindow::ShowCalendar(){
    HideAll();
}
void MainWindow::HideCalendar(){}

// 获取讲座信息
void MainWindow::GetLecture(){
        QDate d = ui->_calendar->selectedDate();
        QString date = d.toString("yyyy-M-d");
        QDialog* dialog=new QDialog(this);
        dialog->setWindowTitle("讲座信息");
        dialog->setMinimumSize(640,120);

        QVBoxLayout* layout=new QVBoxLayout(dialog);
        QComboBox* lectures=new QComboBox(this);
        lectures->setMinimumSize(640,100);
        layout->addWidget(lectures);

        qDebug() << date;
        QDir currentDir = QDir::current();
            qDebug() << "Current directory:" << currentDir.absolutePath();

            // 获取父目录
            QDir parentDir = currentDir;
            if (parentDir.cdUp()) {
                qDebug() << "Parent directory:" << parentDir.absolutePath();
            } else {
                qDebug() << "The current directory does not have a parent directory.";
            }
        QString dir = parentDir.absolutePath();
        QProcess *process = new QProcess();
        QString program = dir + "\\Python\\env\\Scripts\\python";
        QStringList arguments;
        arguments << dir + "\\Project\\lecture_info.py" << date;

        process->start(program, arguments);

        // 等待进程结束
        process->waitForFinished();

        // 读取标准输出
        QString outputString = QString::fromUtf8(process->readAllStandardOutput());
        qDebug() << "Standard Output:" << outputString;

        QStringList lines = outputString.split("\r\n", QString::SkipEmptyParts);

        QString title;
        QString speaker;

        for (const QString &line : lines) {
                lectures->addItem(line);
            }
        QFont font;
            font.setPointSize(11); // 设置字体大小为20

            for(int i = 0; i < lectures->count(); i++)
            {
                lectures->setItemData(i, font, Qt::FontRole); // 设置每个项的字体
            }
        dialog->exec();
}

