#include "menu.h"
#include "ui_menu.h"
#include <QIcon>
Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    connect(ui->_launch,&QPushButton::clicked,this,&Menu::ShowLaunch);

    this->setWindowIcon(QIcon(":/icon.jpg"));
    setWindowTitle("Time Tracker");
}

Menu::~Menu()
{
    delete ui;
}


QMainWindow*& Menu::mainwindow(){
    return _mainwindow;
}
void Menu::ShowLaunch(){
    mainwindow()->show();
    close();
}
