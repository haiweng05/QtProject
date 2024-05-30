#include "menu.h"
#include "ui_menu.h"
#include <QIcon>
Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    connect(ui->_launch,&QPushButton::clicked,this,&Menu::ShowLaunch);

    connect(ui->_intro,&QPushButton::clicked,this,&Menu::ShowIntro);
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
QMainWindow*& Menu::introwindow(){
    return _introwindow;
}

void Menu::ShowLaunch(){
    mainwindow()->show();
    close();
}

void Menu::ShowIntro(){
    introwindow()->show();
}
