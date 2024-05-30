/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <countdowntimer.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *_table;
    QCalendarWidget *_calendar;
    QPushButton *_buttonInport;
    QPushButton *_buttonPersonalize;
    QPushButton *_buttonModify;
    QPushButton *_buttonConfirm;
    QLineEdit *timeDisplay;
    QPushButton *_event;
    CountDownTimer *_countdowntimer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1620, 1080);
        MainWindow->setMinimumSize(QSize(1000, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _table = new QTableWidget(centralwidget);
        _table->setObjectName(QStringLiteral("_table"));
        _table->setGeometry(QRect(870, 0, 811, 791));
        _calendar = new QCalendarWidget(centralwidget);
        _calendar->setObjectName(QStringLiteral("_calendar"));
        _calendar->setGeometry(QRect(0, 0, 861, 501));
        _calendar->setGridVisible(false);
        _calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        _calendar->setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);
        _calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        _buttonInport = new QPushButton(centralwidget);
        _buttonInport->setObjectName(QStringLiteral("_buttonInport"));
        _buttonInport->setGeometry(QRect(20, 580, 160, 48));
        _buttonPersonalize = new QPushButton(centralwidget);
        _buttonPersonalize->setObjectName(QStringLiteral("_buttonPersonalize"));
        _buttonPersonalize->setGeometry(QRect(450, 580, 160, 48));
        _buttonModify = new QPushButton(centralwidget);
        _buttonModify->setObjectName(QStringLiteral("_buttonModify"));
        _buttonModify->setGeometry(QRect(230, 580, 160, 48));
        _buttonConfirm = new QPushButton(centralwidget);
        _buttonConfirm->setObjectName(QStringLiteral("_buttonConfirm"));
        _buttonConfirm->setGeometry(QRect(670, 580, 160, 48));
        timeDisplay = new QLineEdit(centralwidget);
        timeDisplay->setObjectName(QStringLiteral("timeDisplay"));
        timeDisplay->setGeometry(QRect(1200, 900, 201, 51));
        _event = new QPushButton(centralwidget);
        _event->setObjectName(QStringLiteral("_event"));
        _event->setGeometry(QRect(340, 690, 160, 48));
        _countdowntimer = new CountDownTimer(centralwidget);
        _countdowntimer->setObjectName(QStringLiteral("_countdowntimer"));
        _countdowntimer->setGeometry(QRect(300, 780, 240, 240));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1620, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\216\242\347\264\242\346\250\241\345\274\217", 0));
        _buttonInport->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\350\257\276\350\241\250", 0));
        _buttonPersonalize->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226\350\256\276\347\275\256", 0));
        _buttonModify->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\256\211\346\216\222", 0));
        _buttonConfirm->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\234\260\345\233\276", 0));
        _event->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226\346\216\250\350\215\220", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
