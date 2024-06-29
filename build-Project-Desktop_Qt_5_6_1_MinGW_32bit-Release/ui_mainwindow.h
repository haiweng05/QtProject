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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <countdowntimer.h>
#include <pkumap.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *_table;
    QCalendarWidget *_calendar;
    QPushButton *_buttonPersonalize;
    QPushButton *_buttonModify;
    QLineEdit *timeDisplay;
    QPushButton *_event;
    CountDownTimer *_countdowntimer;
    QPushButton *_save;
    PKUMap *_pkumap;
    QPushButton *_buttonInport;
    QPushButton *_lecture;
    QFrame *line;
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
        _table->setGeometry(QRect(1260, 0, 900, 1080));
        _table->setBaseSize(QSize(200, 0));
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        font.setPointSize(12);
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
        _table->horizontalHeader()->setDefaultSectionSize(216);
        _table->horizontalHeader()->setHighlightSections(true);
        _table->horizontalHeader()->setMinimumSectionSize(216);
        _table->verticalHeader()->setDefaultSectionSize(72);
        _table->verticalHeader()->setMinimumSectionSize(20);
        _calendar = new QCalendarWidget(centralwidget);
        _calendar->setObjectName(QStringLiteral("_calendar"));
        _calendar->setGeometry(QRect(0, 0, 1260, 780));
        QFont font1;
        font1.setPointSize(12);
        _calendar->setFont(font1);
        _calendar->setGridVisible(true);
        _calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        _calendar->setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);
        _calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        _calendar->setNavigationBarVisible(true);
        _calendar->setDateEditEnabled(true);
        _buttonPersonalize = new QPushButton(centralwidget);
        _buttonPersonalize->setObjectName(QStringLiteral("_buttonPersonalize"));
        _buttonPersonalize->setGeometry(QRect(650, 850, 200, 60));
        QFont font2;
        font2.setPointSize(10);
        font2.setKerning(true);
        _buttonPersonalize->setFont(font2);
        _buttonModify = new QPushButton(centralwidget);
        _buttonModify->setObjectName(QStringLiteral("_buttonModify"));
        _buttonModify->setGeometry(QRect(50, 850, 200, 60));
        _buttonModify->setFont(font2);
        timeDisplay = new QLineEdit(centralwidget);
        timeDisplay->setObjectName(QStringLiteral("timeDisplay"));
        timeDisplay->setGeometry(QRect(1450, 1220, 521, 161));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setWeight(50);
        timeDisplay->setFont(font3);
        timeDisplay->setCursor(QCursor(Qt::WhatsThisCursor));
        _event = new QPushButton(centralwidget);
        _event->setObjectName(QStringLiteral("_event"));
        _event->setGeometry(QRect(950, 850, 200, 60));
        _event->setFont(font2);
        _countdowntimer = new CountDownTimer(centralwidget);
        _countdowntimer->setObjectName(QStringLiteral("_countdowntimer"));
        _countdowntimer->setGeometry(QRect(420, 1100, 360, 350));
        _save = new QPushButton(centralwidget);
        _save->setObjectName(QStringLiteral("_save"));
        _save->setGeometry(QRect(350, 850, 200, 60));
        _save->setFont(font2);
        _pkumap = new PKUMap(centralwidget);
        _pkumap->setObjectName(QStringLiteral("_pkumap"));
        _pkumap->setGeometry(QRect(0, 60, 20, 1540));
        _buttonInport = new QPushButton(centralwidget);
        _buttonInport->setObjectName(QStringLiteral("_buttonInport"));
        _buttonInport->setGeometry(QRect(350, 990, 200, 60));
        _buttonInport->setFont(font2);
        _lecture = new QPushButton(centralwidget);
        _lecture->setObjectName(QStringLiteral("_lecture"));
        _lecture->setGeometry(QRect(650, 990, 200, 60));
        _lecture->setFont(font2);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1254, 1080, 16, 500));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
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
        _buttonPersonalize->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226\350\256\276\347\275\256", 0));
        _buttonModify->setText(QApplication::translate("MainWindow", "\351\207\215\346\226\260\345\256\211\346\216\222", 0));
#ifndef QT_NO_WHATSTHIS
        timeDisplay->setWhatsThis(QApplication::translate("MainWindow", "\350\256\241\346\227\266\345\231\250", 0));
#endif // QT_NO_WHATSTHIS
        _event->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226\346\216\250\350\215\220", 0));
        _save->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245\345\210\260\346\234\254\345\234\260", 0));
        _buttonInport->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\350\257\276\350\241\250", 0));
        _lecture->setText(QApplication::translate("MainWindow", "\350\256\262\345\272\247\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
