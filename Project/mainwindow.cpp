#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include<QAction>
#include<QAbstractItemView>
#include<QMenu>
#include<QTime>
#include<QLineEdit>
#include<vector>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->_calendar, &QCalendarWidget::selectionChanged, this, &MainWindow::handleSelectionChanged);
    connect(ui->_buttonConfirm,&QPushButton::clicked,this,&MainWindow::Submit);
    connect(ui->_buttonInport,&QPushButton::clicked,this,&MainWindow::ClassImport);
    connect(ui->_buttonModify,&QPushButton::clicked,this,&MainWindow::ClassModify);
    connect(ui->_buttonPersonalize,&QPushButton::clicked,this,&MainWindow::Personalize);
    connect(ui->_calendar,&QCalendarWidget::activated,this,&MainWindow::oneday);
    ui->_table->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->_table, &QTableWidget::customContextMenuRequested, this, &MainWindow::onItemContextMenuRequested);
    AddRow(0);
    for(int i = 0; i < 4; ++ i){
        AddColumn(i);
    }
    AddItem(0,0,"");
    AddItem(0,1,"时间");
    AddItem(0,2,"事件");
    AddItem(0,3,"地点");

    files.getNodes(QString("../Project/nodes.csv"));

    qDebug() << "修改之前";
    qDebug() << files.readUserInfo(0);
    qDebug() << files.readUserInfo(1);
    files.saveUserInfo(1);
    files.saveUserInfo(1);
    qDebug() << "修改之后";
    qDebug() << files.readUserInfo(0);
    qDebug() << files.readUserInfo(1);


    configs = new Config(this);

}

MainWindow::~MainWindow()
{
}


void MainWindow::ClassImport(){
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("打开文件"), "", tr("Excel 文件 (*.xls *.xlsx)")); // 只允许选择 .xls 或 .xlsx 文件
    if (fileName.isEmpty()) { // 如果没有选择文件，直接返回
            return;
    }
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);

    QAxObject *work_books = excel.querySubObject("WorkBooks");
    work_books->dynamicCall("Open (const QString&)", fileName);
    QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
    QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets
    int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
    if(sheet_count > 0)
    {
        QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);
        QAxObject *used_range = work_sheet->querySubObject("UsedRange");
        QAxObject *rows = used_range->querySubObject("Rows");
        int row_count = rows->property("Count").toInt();  //获取行数
        for(int i=2;i<=8;i++){
            int j=2;
            while(j<=13){
                QString txtt = work_sheet->querySubObject("Cells(int,int)",j,i)->dynamicCall("Value2()").toString(); //获取单元格内容
                if(txtt=="" ){
                    j++;
                    continue;
                }
                int leftbracket=0,rightbracket=0;
                int len=txtt.length();
                int f=0;
                for(int k=0;k<len;k++){
                    if(txtt[k]=='(') leftbracket=k;
                    if(leftbracket!=0 && txtt[k].isDigit()){
                        f=1;
                    }

                    if(txtt[k]==')') {
                        if(f==0){
                            leftbracket=0;
                            continue;
                        }
                        rightbracket=k;
                        break;
                    }
                }
                //qDebug()<<leftbracket<<' '<<rightbracket<<endl;
                Event t;
                t.Sname=txtt.left(leftbracket);
                t.Sposition=txtt.mid(leftbracket+1,rightbracket-leftbracket-1);

//                qDebug() << t.Sposition;
//                qDebug() << (files.nameTint.find(t.Sposition.mid(0,2)) == files.nameTint.end());
                qDebug() << t.Sposition;
//                qDebug() << files.nameTint.size();
                for(auto u = files.nameTint.begin();u!=files.nameTint.end();u++){
//                    qDebug() << u.key() << u.value();
                    if(t.Sposition.contains(u.key())){
                        qDebug() << u.key();
                        t.iposition=u.value();
                        break;
                    }
                }
                t.begin=classstart[j-2];
                t.end=classend[j-2];
                t.dayidx=i-1;
                while(j<=13 and work_sheet->querySubObject("Cells(int,int)",j,i)->dynamicCall("Value2()").toString()==txtt){
                    t.end=classend[j-2];
                    j++;
                }
                classschedule.week[i-2].push_back(t);
            }
        }


        work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
        excel.dynamicCall("Quit(void)");  //退出
        return ;
    }

}
void MainWindow::oneday(const QDate&date){
    int dayidx=(date.dayOfWeek()-2)%7+1;
    dayindex=(date.dayOfWeek()-2)%7+1;

    MainWindow::tableclear();

    activities.clear();
    for(Event x:classschedule.week[dayidx]){
        InsertEvent(x);;
    }
    GetFood();
    GetActivity();
}
void MainWindow::tableclear(){
    int t=ui->_table->rowCount();
    for(int i=t-1;i>0;i--){
        ui->_table->removeRow(i);
    }
}



QWidget*& MainWindow::pkumap(){
    return _pkumap;
}

void MainWindow::ShowMap(){
    _pkumap->show();
}
void MainWindow::handleSelectionChanged(){}

void MainWindow::ClassModify() {
    //QTableWidgetItem* selectedItem = ui->_table->currentItem();
    //if (selectedItem) {
       // int selectedRow = selectedItem->row();

        // 在这里连接 customContextMenuRequested 信号
       // connect(ui->_table, &QTableWidget::customContextMenuRequested, this, &MainWindow::onItemContextMenuRequested);
    //}
}

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
        // 添加更多菜单项...

        // 显示右键菜单
        menu->exec(QCursor::pos());
    }
}

void MainWindow::onActiondeleteTriggered(QTableWidgetItem *item) {
    int row = item->row();
    ui->_table->removeRow(row);
    activities.erase(activities.begin()+row);
    // 处理 Action 1 被触发的逻辑
    //qDebug() << "Action 1 triggered";
}
void MainWindow::onActionaddTriggered(){
    int rowcount=ui->_table->rowCount();
    ui->_table->insertRow(rowcount);
    QDialog *dialogadd=new QDialog(this);
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
            InsertEvent(h);

            dialogadd->close();
        });
    dialogadd->exec();
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
}
void MainWindow::Personalize(){
    configs->show();
}

void MainWindow::Submit(){
//    QDate date = QDate();
//    date = ui->_calendar->selectedDate();
//    int d = date.day();
//    int weekday = date.dayOfWeek();
    _pkumap = new PKUMap(this,activities,files.intTpos,files.intTpos[files.nameTint[configs->Origin()]]);
    ShowMap();
}

void MainWindow::AddRow(int row){
    ui->_table->insertRow(row);
}
void MainWindow::AddColumn(int column){
    ui->_table->insertColumn(column);
}
template<typename T>
void MainWindow::AddItem(int row,int column,T item){
    QTableWidgetItem *it = new QTableWidgetItem(item);
    ui->_table->setItem(row, column, it);
}

void MainWindow::AddEvent(Event& event){

    int nrow = ui->_table->rowCount();
    AddRow(nrow);
    AddItem(nrow,1,event.begin.toString());
    AddItem(nrow,2,event.Sname);
    AddItem(nrow,3,event.Sposition);
}

// 以下是直接操作储存事件的vector的接口
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

int MainWindow::FirstBefore(QTime t){
//    bool find = 0;
    int idx = -1;
    for(int i = activities.size() - 1; i >= 0; -- i){
        if(activities[i].end < t){
            idx = i;
            break;
        }
    }

    return idx;
}

void MainWindow::InsertEvent(Event& event){
    activities.push_back(event);
    SortEvent();
}

// 提供两个版本的删除课程接口
void MainWindow::DeleteEvent(Event& event){

}

void MainWindow::DeleteEvent(const QString& Sname){

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

        QPair<int,int> curpos;
        QPair<int,int> nextpos;

        int idx = FirstBefore(beg);
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
            iposition = Selection::PreferenceSelection(2);
        }
        else if(configs->Mode() == 0 && configs->Store() == 0){
            iposition = Selection::RandomSelection(2);
        }
        else{
            iposition = Selection::NearestSelection(2,curpos,nextpos);
        }
        QString Sposition = files.intTname[iposition];
        QString name = "早餐";
        Event e(name,Sposition,iposition,beg,ed);
        InsertEvent(e);

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


        QPair<int,int> curpos;
        QPair<int,int> nextpos;

        int idx = FirstBefore(beg);
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
            iposition = Selection::PreferenceSelection(2);
        }
        else if(configs->Mode() == 0 && configs->Store() == 0){
            iposition = Selection::RandomSelection(2);
        }
        else{
            iposition = Selection::NearestSelection(2,curpos,nextpos);
        }
        QString Sposition = files.intTname[iposition];
        QString name = "中餐";
        Event e(name,Sposition,iposition,beg,ed);
        InsertEvent(e);

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


        QPair<int,int> curpos;
        QPair<int,int> nextpos;

        int idx = FirstBefore(beg);
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
            iposition = Selection::PreferenceSelection(2);
        }
        else if(configs->Mode() == 0 && configs->Store() == 0){
            iposition = Selection::RandomSelection(2);
        }
        else{
            iposition = Selection::NearestSelection(2,curpos,nextpos);
        }
        QString Sposition = files.intTname[iposition];
        QString name = "晚餐";
        Event e(name,Sposition,iposition,beg,ed);
        InsertEvent(e);

    }


}

void MainWindow::GetActivity(){

}

// 这是是一个获取private变量的接口，之后整理代码的时候注意！
FileIO MainWindow::GetFile(){
    return files;
}
