/********************************************************************************
** Form generated from reading UI file 'countdowntimer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDOWNTIMER_H
#define UI_COUNTDOWNTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CountDownTimer
{
public:
    QLCDNumber *lcdNumber;
    QPushButton *Start;
    QPushButton *Reset;
    QPushButton *End;

    void setupUi(QWidget *CountDownTimer)
    {
        if (CountDownTimer->objectName().isEmpty())
            CountDownTimer->setObjectName(QStringLiteral("CountDownTimer"));
        CountDownTimer->resize(240, 240);
        lcdNumber = new QLCDNumber(CountDownTimer);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(0, 0, 240, 180));
        Start = new QPushButton(CountDownTimer);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(10, 190, 60, 36));
        Reset = new QPushButton(CountDownTimer);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setGeometry(QRect(90, 190, 60, 36));
        End = new QPushButton(CountDownTimer);
        End->setObjectName(QStringLiteral("End"));
        End->setGeometry(QRect(180, 190, 60, 36));

        retranslateUi(CountDownTimer);

        QMetaObject::connectSlotsByName(CountDownTimer);
    } // setupUi

    void retranslateUi(QWidget *CountDownTimer)
    {
        CountDownTimer->setWindowTitle(QApplication::translate("CountDownTimer", "Form", 0));
        Start->setText(QApplication::translate("CountDownTimer", "\345\274\200\345\247\213", 0));
        Reset->setText(QApplication::translate("CountDownTimer", "\351\207\215\347\275\256", 0));
        End->setText(QApplication::translate("CountDownTimer", "\347\273\223\346\235\237", 0));
    } // retranslateUi

};

namespace Ui {
    class CountDownTimer: public Ui_CountDownTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDOWNTIMER_H
