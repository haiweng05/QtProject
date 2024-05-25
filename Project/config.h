#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include "mainwindow.h"

namespace Ui {
class Config;
}

class Config : public QMainWindow
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0);
    ~Config();
    bool Mode();
    bool Breakfast();
    bool Lunch();
    bool Dinner();
    bool CrazyThursday();
    bool Coffee();
    bool Exercise();
    bool Store();
    bool Clock();
    QString Origin();

    // 用于同步化设置至显示
    void Synchronize();
private slots:
    void Accept();
    void Refuse();

private:
    Ui::Config *ui;
    // 0表示探索模式,1表示内卷模式
    bool mode;
    bool breakfast;
    bool lunch;
    bool dinner;
    bool crazythursday;
    bool coffee;
    bool exercise;
    // 记录
    bool store;
    // 倒计时
    bool clock;
    // 用于修改模式后改变主窗口名称
    QWidget* mainwindow;
    QString origin;
};

#endif // CONFIG_H
