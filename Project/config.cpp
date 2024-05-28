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
    store(1),
    clock(1),
    answer(0),
    origin("37楼"),
    mainwindow(parent)
{
    ui->setupUi(this);
    connect(ui->_accept,&QPushButton::clicked,this,&Config::Accept);
    connect(ui->_refuse,&QPushButton::clicked,this,&Config::Refuse);
    connect(ui->_clear,&QPushButton::clicked,this,&Config::Clear);

    for(auto nm : ((MainWindow*)mainwindow)->GetFile().TypePos[3]){
        ui->_origin->addItem(((MainWindow*)mainwindow)->GetFile().intTname[nm]);
    }

    Synchronize();
}

Config::~Config()
{
    delete ui;
}

int Config::Mode(){
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

bool Config::Answer(){
    return answer;
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
    origin = ui->_origin->currentText();
    answer = ui->_answer->isChecked();

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
    ui->_origin->setCurrentText(origin);
    ui->_answer->setChecked(answer);

    if(mode == 0)
    mainwindow->setWindowTitle("探索模式");
    else if(mode == 1)
    mainwindow->setWindowTitle("内卷模式");
    else
        mainwindow->setWindowTitle("摆烂模式");
}

QString Config::Origin(){
    return origin;
}

void Config::Clear(){
    ((MainWindow*)mainwindow)->GetFile().initUserInfo();
}
