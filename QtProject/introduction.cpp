#include "introduction.h"
#include "ui_introduction.h"

Introduction::Introduction(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Introduction)
{
    ui->setupUi(this);

    connect(ui->_exit,&QPushButton::clicked,this,&Introduction::Exit);

}

Introduction::~Introduction()
{
    delete ui;
}

void Introduction::Exit(){
    close();
}
