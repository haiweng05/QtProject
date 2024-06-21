#include "introduction.h"
#include "ui_introduction.h"
#include <QIcon>
Introduction::Introduction(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Introduction)
{
    ui->setupUi(this);
//    setWindowTitle("Time Tracker");
//    this->setWindowIcon(QIcon(":/icon.jpg"));
    connect(ui->_exit,&QPushButton::clicked,this,&Introduction::Exit);

}

Introduction::~Introduction()
{
    delete ui;
}

void Introduction::Exit(){
    close();
}
