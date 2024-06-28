#include "config.h"
#include "ui_config.h"
#include <QIcon>
Config::Config(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config),
    mode(0),
    breakfast(1),
    lunch(1),
    dinner(1),
    store(1),
    clock(1),
    answer(0),
    origin("39楼"),
    dest("../Project/1.bmp"),
    tempdest("../Project/1.bmp"),
    mainwindow(parent)
{
    ui->setupUi(this);
    this->setWindowTitle("Time Tracker");
    this->setWindowIcon(QIcon(":/icon.jpg"));
    connect(ui->_accept,&QPushButton::clicked,this,&Config::Accept);
    connect(ui->_refuse,&QPushButton::clicked,this,&Config::Refuse);
    connect(ui->_clear,&QPushButton::clicked,this,&Config::Clear);
    connect(ui->_dest,&QPushButton::clicked,this,&Config::ChangeDirection);

    for(auto nm : ((MainWindow*)mainwindow)->GetFile().TypePos[3]){
        ui->_origin->addItem(((MainWindow*)mainwindow)->GetFile().intTname[nm]);
    }

    ui->_direction->setText("当前地址: 默认地址");
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

bool Config::Store(){
    return store;
}

bool Config::Clock(){
    return clock;
}

bool Config::Answer(){
    return answer;
}

QString Config::Dest(){
    return dest;
}

void Config::Accept(){

    mode = ui->_mode->currentIndex();
    breakfast = ui->_breakfast->isChecked();
    lunch = ui->_lunch->isChecked();
    dinner = ui->_dinner->isChecked();
    store = ui->_store->isChecked();
    clock = ui->_clock->isChecked();
    origin = ui->_origin->currentText();
    answer = ui->_answer->isChecked();
    dest = tempdest;

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
    ui->_store->setChecked(store);
    ui->_clock->setChecked(clock);
    ui->_origin->setCurrentText(origin);
    ui->_answer->setChecked(answer);
    tempdest = dest;

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
    for(int i = 0; i <= 2; ++ i){
        ((MainWindow*)mainwindow)->GetFile().initUserInfo(i);
        qDebug() << i;
    }
    auto ptr = ((MainWindow*)mainwindow)->ClassSchedule();
    for(int i = 0; i < 8; ++ i){
        ptr[i].clear();
    }
}

void Config::ChangeDirection(){
    tempdest = QFileDialog::getOpenFileName(this,
                                                    tr("打开文件"), "", tr("图片文件 (*.jpg *.jpeg *.png *.bmp *.gif *.tiff *.ico *.svg *.webp);;所有文件 (*)"));
    ui->_direction->setText("当前地址: " + tempdest);
}
