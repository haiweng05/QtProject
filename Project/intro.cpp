#include "intro.h"
#include "ui_intro.h"
#include <QIcon>
Intro::Intro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Intro)
{
    ui->setupUi(this);
    setWindowTitle("Time Tracker");
    this->setWindowIcon(QIcon(":/icon.jpg"));
    connect(ui->_exit,&QPushButton::clicked,this,&Intro::Exit);

}

Intro::~Intro()
{
    delete ui;
}

void Intro::Exit(){
    close();
}
