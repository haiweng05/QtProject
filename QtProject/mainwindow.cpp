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
}


MainWindow::~MainWindow()
{
}

void MainWindow::handleSelectionChanged(){}

void MainWindow::ClassImport(){
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("打开文件"), "", tr("所有文件 (*)"));
}

void MainWindow::ClassModify(){

}

void MainWindow::Personalize(){

}

void MainWindow::Submit(){
    QDate date = QDate();
    date = ui->_calendar->selectedDate();
    int d = date.day();
    int weekday = date.dayOfWeek();
    ui->_picture->setPixmap(QPixmap("C:\\Users\\徐海翁\\Downloads\\1.bmp"));
}
