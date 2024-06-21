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
#include <introduction.h>
#include <pkumap.h>

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
    QPushButton *_save;
    PKUMap *_pkumap;
    Introduction *_info;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2160, 1600);
        MainWindow->setMinimumSize(QSize(1000, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _table = new QTableWidget(centralwidget);
        _table->setObjectName(QStringLiteral("_table"));
        _table->setGeometry(QRect(1280, 0, 881, 1011));
        _table->setBaseSize(QSize(200, 0));
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        _table->setFont(font);
        _table->setMouseTracking(false);
        _table->setAutoFillBackground(true);
        _table->setStyleSheet(QStringLiteral("alternate-background-color: rgb(234, 251, 255)"));
        _table->setAlternatingRowColors(true);
        _table->setIconSize(QSize(0, 3));
        _table->setTextElideMode(Qt::ElideMiddle);
        _table->setRowCount(0);
        _table->horizontalHeader()->setDefaultSectionSize(180);
        _table->verticalHeader()->setDefaultSectionSize(60);
        _calendar = new QCalendarWidget(centralwidget);
        _calendar->setObjectName(QStringLiteral("_calendar"));
        _calendar->setGeometry(QRect(0, 0, 1281, 1011));
        QFont font1;
        font1.setPointSize(10);
        _calendar->setFont(font1);
        _calendar->setGridVisible(true);
        _calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        _calendar->setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);
        _calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        _calendar->setNavigationBarVisible(true);
        _calendar->setDateEditEnabled(true);
        _buttonInport = new QPushButton(centralwidget);
        _buttonInport->setObjectName(QStringLiteral("_buttonInport"));
        _buttonInport->setGeometry(QRect(20, 1030, 160, 48));
        QFont font2;
        font2.setPointSize(10);
        font2.setKerning(true);
        _buttonInport->setFont(font2);
        _buttonPersonalize = new QPushButton(centralwidget);
        _buttonPersonalize->setObjectName(QStringLiteral("_buttonPersonalize"));
        _buttonPersonalize->setGeometry(QRect(450, 1030, 160, 48));
        _buttonPersonalize->setFont(font2);
        _buttonModify = new QPushButton(centralwidget);
        _buttonModify->setObjectName(QStringLiteral("_buttonModify"));
        _buttonModify->setGeometry(QRect(230, 1030, 160, 48));
        _buttonModify->setFont(font2);
        _buttonConfirm = new QPushButton(centralwidget);
        _buttonConfirm->setObjectName(QStringLiteral("_buttonConfirm"));
        _buttonConfirm->setGeometry(QRect(670, 1030, 160, 48));
        _buttonConfirm->setFont(font2);
        timeDisplay = new QLineEdit(centralwidget);
        timeDisplay->setObjectName(QStringLiteral("timeDisplay"));
        timeDisplay->setGeometry(QRect(1480, 1270, 240, 72));
        timeDisplay->setFont(font1);
        timeDisplay->setCursor(QCursor(Qt::WhatsThisCursor));
        _event = new QPushButton(centralwidget);
        _event->setObjectName(QStringLiteral("_event"));
        _event->setGeometry(QRect(450, 1130, 160, 48));
        _event->setFont(font2);
        _countdowntimer = new CountDownTimer(centralwidget);
        _countdowntimer->setObjectName(QStringLiteral("_countdowntimer"));
        _countdowntimer->setGeometry(QRect(300, 1230, 240, 240));
        _save = new QPushButton(centralwidget);
        _save->setObjectName(QStringLiteral("_save"));
        _save->setGeometry(QRect(230, 1130, 160, 48));
        _save->setFont(font2);
        _pkumap = new PKUMap(centralwidget);
        _pkumap->setObjectName(QStringLiteral("_pkumap"));
        _pkumap->setGeometry(QRect(0, 60, 20, 1540));
        _info = new Introduction(centralwidget);
        _info->setObjectName(QStringLiteral("_info"));
        _info->setGeometry(QRect(0, 60, 20, 1540));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2160, 60));
        menubar->setMinimumSize(QSize(0, 60));
        menubar->setSizeIncrement(QSize(0, 0));
        MainWindow->setMenuBar(menubar);

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
#ifndef QT_NO_WHATSTHIS
        timeDisplay->setWhatsThis(QApplication::translate("MainWindow", "\350\256\241\346\227\266\345\231\250", 0));
#endif // QT_NO_WHATSTHIS
        _event->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226\346\216\250\350\215\220", 0));
        _save->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\345\210\260\346\234\254\345\234\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
