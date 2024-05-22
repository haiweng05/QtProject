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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTableWidget *_table;
    QLabel *_picture;
    QPushButton *pushButton_2;
    QCalendarWidget *_calendar;
    QPushButton *_buttonInport;
    QPushButton *_buttonPersonalize;
    QTimeEdit *_timeEdit;
    QPushButton *_buttonModify;
    QPushButton *pushButton_3;
    QPushButton *_buttonConfirm;
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(760, 860, 51, 51));
        _table = new QTableWidget(centralwidget);
        _table->setObjectName(QStringLiteral("_table"));
        _table->setGeometry(QRect(690, -20, 811, 791));
        _picture = new QLabel(centralwidget);
        _picture->setObjectName(QStringLiteral("_picture"));
        _picture->setGeometry(QRect(-10, 630, 601, 401));
        _picture->setTextFormat(Qt::AutoText);
        _picture->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(830, 860, 51, 51));
        _calendar = new QCalendarWidget(centralwidget);
        _calendar->setObjectName(QStringLiteral("_calendar"));
        _calendar->setGeometry(QRect(0, 0, 691, 371));
        _calendar->setGridVisible(false);
        _calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        _buttonInport = new QPushButton(centralwidget);
        _buttonInport->setObjectName(QStringLiteral("_buttonInport"));
        _buttonInport->setGeometry(QRect(70, 400, 80, 24));
        _buttonPersonalize = new QPushButton(centralwidget);
        _buttonPersonalize->setObjectName(QStringLiteral("_buttonPersonalize"));
        _buttonPersonalize->setGeometry(QRect(390, 400, 80, 24));
        _timeEdit = new QTimeEdit(centralwidget);
        _timeEdit->setObjectName(QStringLiteral("_timeEdit"));
        _timeEdit->setGeometry(QRect(760, 780, 191, 51));
        _buttonModify = new QPushButton(centralwidget);
        _buttonModify->setObjectName(QStringLiteral("_buttonModify"));
        _buttonModify->setGeometry(QRect(240, 400, 80, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(900, 860, 51, 51));
        _buttonConfirm = new QPushButton(centralwidget);
        _buttonConfirm->setObjectName(QStringLiteral("_buttonConfirm"));
        _buttonConfirm->setGeometry(QRect(530, 400, 80, 24));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        _picture->setText(QApplication::translate("MainWindow", "\345\234\260\345\233\276\345\257\274\345\274\225(\350\257\267\345\205\210\351\200\211\346\213\251\346\227\245\346\234\237)", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        _buttonInport->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\350\257\276\350\241\250", 0));
        _buttonPersonalize->setText(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226\350\256\276\347\275\256", 0));
        _buttonModify->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\257\276\350\241\250", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", 0));
        _buttonConfirm->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
