#include "mainwindow.h"
#include "menu.h"
#include "introduction.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu; // 作为我们入口的界面
    MainWindow w; // 入口界面不作为我们的真正主界面的父窗口,因为父窗口关闭了子窗口就会关闭
    Introduction intro(&menu); // 介绍窗口以我们的入口窗口为父窗口
    menu.mainwindow() = &w;
    menu.introwindow() = &intro;

    menu.show();
    // w.show();
    return a.exec();
}
