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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Introduction
{
public:
    QWidget *centralwidget;
    QPushButton *_exit;
    QTextBrowser *_browser;

    void setupUi(QWidget *Introduction)
    {
        if (Introduction->objectName().isEmpty())
            Introduction->setObjectName(QStringLiteral("Introduction"));
        Introduction->resize(2160, 1540);
        Introduction->setMinimumSize(QSize(640, 480));
        centralwidget = new QWidget(Introduction);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _exit = new QPushButton(centralwidget);
        _exit->setObjectName(QStringLiteral("_exit"));
        _exit->setGeometry(QRect(1950, 1460, 160, 48));
        _browser = new QTextBrowser(centralwidget);
        _browser->setObjectName(QStringLiteral("_browser"));
        _browser->setGeometry(QRect(20, 0, 1911, 1511));
        _browser->setLineWidth(0);
        _browser->setOpenExternalLinks(true);
//        Introduction->setCentralWidget(centralwidget);

        retranslateUi(Introduction);

        QMetaObject::connectSlotsByName(Introduction);
    } // setupUi

    void retranslateUi(QWidget *Introduction)
    {
        Introduction->setWindowTitle(QApplication::translate("Introduction", "MainWindow", 0));
        _exit->setText(QApplication::translate("Introduction", "\346\210\221\347\237\245\351\201\223\344\272\206", 0));
        _browser->setHtml(QApplication::translate("Introduction", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:14pt;\">\351\241\271\347\233\256GitHub\345\234\260\345\235\200\357\274\232</span><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" text-decoration: underline; color:#0000ff;\">https://github.com/haiweng05/QtProject</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\344\275\277\347\224\250\350\257\264\346\230\216\357\274\232</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">1.\346\214\211\345\220\257\345\212\250\346\214\211\351\222\256\350\277\233\345\205\245\344\270\273\347\225\214\351\235\242\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">2.\350\277\233\345\205\245\344\270\273\347\225\214\351\235\242\345\220\216\357\274\214\345\217\257\344\275\277\347\224\250\342\200\234\345\257\274\345"
                        "\205\245\350\257\276\350\241\250\342\200\235\346\214\211\351\222\256\345\257\274\345\205\245\344\273\216\351\200\211\350\257\276\347\275\221\347\255\211\345\234\260\346\226\271\344\270\213\350\275\275\347\232\204\345\214\227\344\272\254\345\244\247\345\255\246\350\257\276\350\241\250\357\274\210xls\346\240\274\345\274\217\357\274\211\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">3.\347\202\271\345\207\273\346\227\245\345\216\206\344\270\255\347\232\204\344\273\273\344\275\225\344\270\200\345\244\251\357\274\214\347\250\213\345\272\217\345\260\206\344\274\232\350\207\252\345\212\250\346\240\271\346\215\256\351\200\211\346\213\251\347\232\204\346\250\241\345\274\217\344\270\216\345\257\274\345\205\245\347\232\204\350\257\276\350\241\250\347\224\237\346\210\220\345\275\223\345\244\251"
                        "\347\232\204\346\227\245\347\250\213\345\256\211\346\216\222\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">4.\346\227\245\347\250\213\345\256\211\346\216\222\345\205\267\346\234\211\350\256\260\345\277\206\345\212\237\350\203\275\357\274\214\345\275\223\347\202\271\345\207\273\346\233\276\347\273\217\345\267\262\347\273\217\347\224\237\346\210\220\350\277\207\350\247\204\345\210\222\347\232\204\344\270\200\345\244\251\357\274\214\345\260\206\344\270\215\344\274\232\350\207\252\345\212\250\351\207\215\346\226\260\347\224\237\346\210\220\357\274\214\350\200\214\346\230\257\351\207\215\346\226\260\346\230\276\347\244\272\345\275\223\345\244\251\347\232\204\350\247\204\345\210\222\357\274\214\345\246\202\346\236\234\345\257\271\347\224\237\346\210\220\347\232\204\346\227\245\347\250\213"
                        "\345\256\211\346\216\222\344\270\215\346\273\241\346\204\217\346\210\226\350\200\205\346\224\271\345\217\230\344\272\206\350\256\276\347\275\256\357\274\214\345\217\257\344\273\245\345\234\250\342\200\234\351\200\211\345\256\232\345\275\223\345\244\251\342\200\235\347\232\204\346\203\205\345\206\265\344\270\213\347\202\271\345\207\273\351\207\215\346\226\260\347\224\237\346\210\220\346\214\211\351\222\256\357\274\214\345\217\257\344\273\245\346\214\211\347\205\247\345\275\223\345\211\215\350\256\276\347\275\256\351\207\215\346\226\260\347\224\237\346\210\220\345\275\223\345\244\251\346\227\245\347\250\213\345\256\211\346\216\222\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">5.\345\234\250\347\224\237\346\210\220\344\272\206\344\273\273\344\275\225\344\270\200\345\244\251\347\232\204"
                        "\346\227\245\347\250\213\345\256\211\346\216\222\345\220\216\357\274\214\345\217\257\344\273\245\347\202\271\345\207\273\342\200\234\346\211\223\345\274\200\345\234\260\345\233\276\342\200\235\346\214\211\351\222\256\357\274\214\345\260\206\344\274\232\346\234\211\344\270\200\345\274\240\347\207\225\345\233\255\345\234\260\345\233\276\346\211\223\345\274\200\357\274\214\345\220\214\346\227\266\346\240\271\346\215\256\345\275\223\345\244\251\347\232\204\346\227\245\347\250\213\345\256\211\346\216\222\357\274\214\344\275\240\345\217\257\344\273\245\345\215\225\346\255\245\346\210\226\350\200\205\345\244\232\346\255\245\346\230\276\347\244\272\350\267\257\345\276\204\357\274\214\346\217\220\344\276\233\347\251\272\351\227\264\344\270\212\347\232\204\345\257\274\350\210\252\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decor"
                        "ation: underline; color:#000000;\">6.\345\256\232\346\227\266\346\217\220\351\206\222\346\250\241\345\235\227\357\274\214\346\240\271\346\215\256\347\224\250\346\210\267\345\275\223\345\211\215\346\211\200\351\200\211\347\232\204\346\227\245\346\234\237\357\274\214\345\234\250\346\257\217\344\270\200\346\227\245\347\250\213\344\272\213\344\273\266\345\274\200\345\247\213\345\211\215\344\270\200\345\256\232\346\227\266\351\227\264\357\274\214\347\250\213\345\272\217\345\260\206\344\274\232\350\207\252\345\212\250\346\217\220\351\206\222\347\224\250\346\210\267\357\274\214\345\220\214\346\227\266\347\224\250\346\210\267\344\271\237\345\217\257\344\273\245\345\210\251\347\224\250\344\270\273\347\225\214\351\235\242\344\270\212\347\232\204\345\256\232\346\227\266\345\231\250\350\256\276\347\275\256\345\256\232\346\227\266\345\231\250\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/ha"
                        "iweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">7.\344\270\252\346\200\247\345\214\226\350\256\276\347\275\256\357\274\232\347\250\213\345\272\217\346\217\220\344\276\233\344\272\206\345\244\232\344\270\252\346\250\241\345\274\217\345\222\214\345\244\232\347\247\215\344\270\252\346\200\247\345\214\226\351\200\211\351\241\271</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\344\270\273\350\246\201\346\250\241\345\274\217\345\246\202\344\270\213\357\274\232</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\357\274\2101\357\274\211\346\216"
                        "\242\347\264\242\346\250\241\345\274\217\343\200\220\351\273\230\350\256\244\343\200\221</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">    \347\250\213\345\272\217\345\260\206\344\274\232\346\231\272\350\203\275\345\234\260\344\270\272\347\224\250\346\210\267\346\217\220\344\276\233\351\232\217\346\234\272\347\224\237\346\210\220\347\232\204\345\260\261\351\244\220\357\274\214\350\207\252\344\271\240\357\274\214\346\264\273\345\212\250\345\256\211\346\216\222\357\274\214\347\224\250\346\210\267\344\271\237\345\217\257\344\273\245\345\274\200\345\220\257\346\234\254\345\234\260\346\225\260\346\215\256\345\255\230\345\202\250\345\212\237\350\203\275\357\274\214\346\240\271\346\215\256\347\224\250\346\210\267\346\233\276\347\273\217\347\232\204\350\256\277\351\227\256\350\256\260\345\275\225\357\274"
                        "\214\346\231\272\350\203\275\346\216\250\350\215\220\347\224\250\346\210\267\345\216\273\344\270\215\345\244\252\345\270\270\345\216\273\347\232\204\345\234\260\347\202\271\357\274\214\346\213\223\345\261\225\350\207\252\345\267\261\347\232\204\350\210\222\351\200\202\345\214\272\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\357\274\2102\357\274\211\345\206\205\345\215\267\346\250\241\345\274\217</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">    \347\250\213\345\272\217\345\260\206\344\274\232\344\270\272\347\224\250\346\210\267\346\217\220\344\276\233\346\267\213"
                        "\346\274\223\345\260\275\350\207\264\347\232\204\345\206\205\345\215\267\344\275\223\351\252\214\357\274\214\345\214\205\346\213\254\344\275\206\344\270\215\351\231\220\344\272\216\345\217\226\346\266\210\345\220\204\347\261\273\346\264\273\345\212\250\346\216\250\350\215\220\357\274\214\345\220\214\346\227\266\345\270\256\345\212\251\347\224\250\346\210\267\350\247\204\345\210\222\345\234\250\351\243\237\345\240\202\357\274\214\346\225\231\345\255\246\346\245\274\347\255\211\345\234\272\346\211\200\351\227\264\347\232\204\351\200\232\345\213\244\346\227\266\351\227\264\357\274\214\346\234\200\345\244\247\345\214\226\347\224\250\346\210\267\345\206\205\345\215\267\347\232\204\346\225\210\347\216\207\343\200\202</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\357\274\2103\357\274\211\346\221\206"
                        "\347\203\202\346\250\241\345\274\217</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">    \344\270\272\344\272\206\345\270\256\345\212\251\346\221\206\347\203\202\347\224\250\346\210\267\357\274\214\347\250\213\345\272\217\346\217\220\344\276\233\344\272\206\346\221\206\347\203\202\346\250\241\345\274\217\351\200\211\346\213\251\357\274\214\346\233\264\345\244\232\347\211\271\347\202\271\347\255\211\345\276\205\347\224\250\346\210\267\350\207\252\350\241\214\346\216\242\347\264\242\343\200\202</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; text-decoration: underline; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margi"
                        "n-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://github.com/haiweng05/QtProject\"><span style=\" font-size:11pt; text-decoration: underline; color:#000000;\">\345\205\266\344\275\231\344\270\252\346\200\247\345\214\226\351\200\211\351\241\271\345\214\205\346\213\254\351\203\250\345\210\206\345\234\260\347\202\271\346\230\257\345\220\246\345\220\257\347\224\250\347\255\211\357\274\214\345\275\261\345\223\215\345\233\272\345\256\232\344\275\215\347\275\256\347\232\204\350\247\204\345\210\222\346\203\205\345\206\265\357\274\214\347\224\250\346\210\267\345\217\257\344\273\245\346\240\271\346\215\256\350\207\252\345\267\261\347\232\204\344\270\252\344\272\272\345\201\217\345\245\275\350\277\233\350\241\214\350\256\276\347\275\256\343\200\202</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; text-decoration: underline; color:#000000;\"><br /></p>\n"
"<p style=\"-qt-par"
                        "agraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; text-decoration: underline; color:#0000ff;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Introduction: public Ui_Introduction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTRODUCTION_H
