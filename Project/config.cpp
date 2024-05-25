#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config),
    mode(0),
    breakfast(1),
    lunch(1),
    dinner(1),
    crazythursday(1),
    coffee(1),
    exercise(1),
    store(0),
    clock(1),
    mainwindow(parent)
{
    ui->setupUi(this);
    connect(ui->_accept,&QPushButton::clicked,this,&Config::Accept);
    connect(ui->_refuse,&QPushButton::clicked,this,&Config::Refuse);

    Synchronize();
}

Config::~Config()
{
    delete ui;
}

bool Config::Mode(){
    return mode;
}

bool Config::Breakfast(){
    return breakfast;
}

bool Config::Lunch(){
    return lunch;
}

bool Config::Dinner(){
    return dinner;
}

bool Config::CrazyThursday(){
    return crazythursday;
}

bool Config::Coffee(){
    return coffee;
}

bool Config::Exercise(){
    return exercise;
}

bool Config::Store(){
    return store;
}

bool Config::Clock(){
    return clock;
}

void Config::Accept(){

    mode = ui->_mode->currentIndex();
    breakfast = ui->_breakfast->isChecked();
    lunch = ui->_lunch->isChecked();
    dinner = ui->_dinner->isChecked();
    crazythursday = ui->_crazythursday->isChecked();
    coffee = ui->_coffee->isChecked();
    store = ui->_store->isChecked();
    exercise = ui->_exercise->isChecked();
    clock = ui->_clock->isChecked();

    Synchronize();
    close();
}

void Config::Refuse(){


    Synchronize();
    close();
}

void Config::Synchronize(){
    ui->_mode->setCurrentIndex(mode);
    ui->_breakfast->setChecked(breakfast);
    ui->_lunch->setChecked(lunch);
    ui->_dinner->setChecked(dinner);
    ui->_crazythursday->setChecked(crazythursday);
    ui->_coffee->setChecked(coffee);
    ui->_store->setChecked(store);
    ui->_exercise->setChecked(exercise);
    ui->_clock->setChecked(clock);

    if(!mode)
    mainwindow->setWindowTitle("探索模式");
    else
    mainwindow->setWindowTitle("内卷模式");
}