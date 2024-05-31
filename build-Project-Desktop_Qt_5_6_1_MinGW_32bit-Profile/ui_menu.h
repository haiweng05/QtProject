/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *_intro;
    QPushButton *_launch;
    QFrame *frame;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(1600, 900);
        Menu->setMinimumSize(QSize(640, 480));
        Menu->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _intro = new QPushButton(centralwidget);
        _intro->setObjectName(QStringLiteral("_intro"));
        _intro->setGeometry(QRect(750, 750, 160, 48));
        QFont font;
        font.setPointSize(10);
        _intro->setFont(font);
        _intro->setText(QString::fromUtf8("\350\257\264\346\230\216"));
        _launch = new QPushButton(centralwidget);
        _launch->setObjectName(QStringLiteral("_launch"));
        _launch->setGeometry(QRect(750, 660, 160, 48));
        _launch->setFont(font);
        _launch->setText(QString::fromUtf8("\345\220\257\345\212\250"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-1, -21, 1611, 901));
        frame->setFont(font);
        frame->setStyleSheet(QLatin1String("#frame{\n"
"border-image:url(:/image.jpg)\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 230, 711, 101));
        QFont font1;
        font1.setFamily(QStringLiteral("Harrington"));
        font1.setPointSize(44);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color:rgb(255, 0, 0)"));
        Menu->setCentralWidget(centralwidget);
        frame->raise();
        _intro->raise();
        _launch->raise();
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 21));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        _launch->setDefault(false);


        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", 0));
        label->setText(QApplication::translate("Menu", "Time Tracker", 0));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
