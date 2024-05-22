/********************************************************************************
** Form generated from reading UI file 'introduction.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTRODUCTION_H
#define UI_INTRODUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Introduction
{
public:
    QWidget *centralwidget;
    QPushButton *_exit;
    QTextBrowser *_browser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Introduction)
    {
        if (Introduction->objectName().isEmpty())
            Introduction->setObjectName(QStringLiteral("Introduction"));
        Introduction->resize(640, 480);
        Introduction->setMinimumSize(QSize(640, 480));
        centralwidget = new QWidget(Introduction);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _exit = new QPushButton(centralwidget);
        _exit->setObjectName(QStringLiteral("_exit"));
        _exit->setGeometry(QRect(470, 320, 160, 48));
        _browser = new QTextBrowser(centralwidget);
        _browser->setObjectName(QStringLiteral("_browser"));
        _browser->setGeometry(QRect(150, 230, 256, 192));
        Introduction->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Introduction);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 21));
        Introduction->setMenuBar(menubar);
        statusbar = new QStatusBar(Introduction);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Introduction->setStatusBar(statusbar);

        retranslateUi(Introduction);

        QMetaObject::connectSlotsByName(Introduction);
    } // setupUi

    void retranslateUi(QMainWindow *Introduction)
    {
        Introduction->setWindowTitle(QApplication::translate("Introduction", "MainWindow", 0));
        _exit->setText(QApplication::translate("Introduction", "\346\210\221\347\237\245\351\201\223\344\272\206", 0));
        _browser->setHtml(QApplication::translate("Introduction", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI';\">\350\277\231\346\230\257\350\277\231\344\270\252\351\241\271\347\233\256\347\232\204\344\273\213\347\273\215</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Introduction: public Ui_Introduction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRODUCTION_H
