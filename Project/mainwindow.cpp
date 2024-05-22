#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

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

    AddRow(0);
    for(int i = 0; i < 4; ++ i){
        AddColumn(i);
    }
    AddItem(0,0,"");
    AddItem(0,1,"时间");
    AddItem(0,2,"事件");
    AddItem(0,3,"地点");
    FileIO f;
    f.getNodes(QString("C:\\code\\C++\\temp\\QT_Modules\\CSVReader\\nodes.csv"));
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
        QChar ch1 = '教',ch2='楼';
        std::wstring wideStr1 = std::wstring(1, ch1.unicode());
        std::string utf8Char1 = std::string(wideStr1.begin(), wideStr1.end());
        std::wstring wideStr2 = std::wstring(1, ch2.unicode());
        std::string utf8Char2 = std::string(wideStr2.begin(), wideStr2.end());
        int row_count = rows->property("Count").toInt();  //获取行数
        for(int i=2;i<=8;i++){
            int j=2;
            while(j<=13){
                QString txtt = work_sheet->querySubObject("Cells(int,int)",j,i)->dynamicCall("Value2()").toString(); //获取单元格内容
                std::string txt=txtt.toLatin1().data();
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
                t.begin=classstart[j-2];
                t.end=classend[j-2];
                t.dayidx=i-1;
                while(j<=13 and work_sheet->querySubObject("Cells(int,int)",j,i)->dynamicCall("Value2()").toString()==txtt){
                    t.end=classend[j-2];
                    j++;
                }
                classschedule.week[i-2].push_back(t);
                //qDebug()<<t.Sname<<' '<<t.begin<<' '<<t.end<<endl;
            }
        }


        work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
        excel.dynamicCall("Quit(void)");  //退出
        return ;
    }

}
void MainWindow::oneday(const QDate&date){
    int dayidx=(date.dayOfWeek()-2)%7+1;
    MainWindow::tableclear();
    for(Event x:classschedule.week[dayidx]){
        AddEvent(x);
    }

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

void MainWindow::ClassModify(){

}

void MainWindow::Personalize(){

}

void MainWindow::Submit(){
    QDate date = QDate();
    date = ui->_calendar->selectedDate();
    int d = date.day();
    int weekday = date.dayOfWeek();
    _pkumap = new PKUMap(this,classschedule.week[weekday]);
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
