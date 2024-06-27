#include "mainwindow.h"
#include "menu.h"
#include "pkumap.h"
#include "config.h"
#include "selection.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu; // 作为我们入口的界面
    MainWindow mainwindow; // 入口界面不作为我们的真正主界面的父窗口,因为父窗口关闭了子窗口就会关闭

    menu.mainwindow() = &mainwindow;
    Selection::mainwindow = &mainwindow;

    menu.show();

    return a.exec();
}
