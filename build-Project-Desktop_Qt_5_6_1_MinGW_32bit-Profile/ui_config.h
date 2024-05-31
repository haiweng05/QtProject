/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QWidget *centralwidget;
    QCheckBox *_breakfast;
    QCheckBox *_lunch;
    QLabel *label;
    QComboBox *_mode;
    QCheckBox *_dinner;
    QLabel *label_2;
    QCheckBox *_clock;
    QLabel *label_3;
    QCheckBox *_store;
    QLabel *label_4;
    QComboBox *_origin;
    QPushButton *_clear;
    QCheckBox *_answer;
    QPushButton *_dest;
    QLabel *_direction;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *_refuse;
    QPushButton *_accept;

    void setupUi(QMainWindow *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QStringLiteral("Config"));
        Config->resize(1080, 720);
        QFont font;
        font.setPointSize(10);
        Config->setFont(font);
        centralwidget = new QWidget(Config);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _breakfast = new QCheckBox(centralwidget);
        _breakfast->setObjectName(QStringLiteral("_breakfast"));
        _breakfast->setGeometry(QRect(170, 130, 360, 40));
        _breakfast->setFont(font);
        _lunch = new QCheckBox(centralwidget);
        _lunch->setObjectName(QStringLiteral("_lunch"));
        _lunch->setGeometry(QRect(170, 180, 360, 40));
        _lunch->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 100, 24));
        _mode = new QComboBox(centralwidget);
        _mode->setObjectName(QStringLiteral("_mode"));
        _mode->setGeometry(QRect(170, 40, 210, 40));
        _dinner = new QCheckBox(centralwidget);
        _dinner->setObjectName(QStringLiteral("_dinner"));
        _dinner->setGeometry(QRect(170, 230, 360, 40));
        _dinner->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 50, 100, 40));
        _clock = new QCheckBox(centralwidget);
        _clock->setObjectName(QStringLiteral("_clock"));
        _clock->setGeometry(QRect(450, 90, 1, 1));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 130, 100, 40));
        _store = new QCheckBox(centralwidget);
        _store->setObjectName(QStringLiteral("_store"));
        _store->setGeometry(QRect(170, 320, 360, 40));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(560, 140, 100, 40));
        _origin = new QComboBox(centralwidget);
        _origin->setObjectName(QStringLiteral("_origin"));
        _origin->setGeometry(QRect(720, 140, 210, 40));
        _clear = new QPushButton(centralwidget);
        _clear->setObjectName(QStringLiteral("_clear"));
        _clear->setGeometry(QRect(170, 380, 160, 48));
        _answer = new QCheckBox(centralwidget);
        _answer->setObjectName(QStringLiteral("_answer"));
        _answer->setGeometry(QRect(720, 50, 360, 40));
        _dest = new QPushButton(centralwidget);
        _dest->setObjectName(QStringLiteral("_dest"));
        _dest->setGeometry(QRect(720, 210, 160, 48));
        _direction = new QLabel(centralwidget);
        _direction->setObjectName(QStringLiteral("_direction"));
        _direction->setGeometry(QRect(560, 250, 841, 161));
        QFont font1;
        font1.setPointSize(8);
        _direction->setFont(font1);
        _direction->setLayoutDirection(Qt::LeftToRight);
        _direction->setTextFormat(Qt::AutoText);
        _direction->setScaledContents(false);
        _direction->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(560, 220, 171, 40));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 320, 100, 40));
        _refuse = new QPushButton(centralwidget);
        _refuse->setObjectName(QStringLiteral("_refuse"));
        _refuse->setGeometry(QRect(640, 560, 240, 72));
        _accept = new QPushButton(centralwidget);
        _accept->setObjectName(QStringLiteral("_accept"));
        _accept->setGeometry(QRect(200, 560, 240, 72));
        Config->setCentralWidget(centralwidget);

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QMainWindow *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "MainWindow", 0));
        _breakfast->setText(QApplication::translate("Config", "\346\227\251\351\244\220", 0));
        _lunch->setText(QApplication::translate("Config", "\344\270\255\351\244\220", 0));
        label->setText(QApplication::translate("Config", "\346\250\241\345\274\217", 0));
        _mode->clear();
        _mode->insertItems(0, QStringList()
         << QApplication::translate("Config", "\346\216\242\347\264\242\346\250\241\345\274\217", 0)
         << QApplication::translate("Config", "\345\206\205\345\215\267\346\250\241\345\274\217", 0)
         << QApplication::translate("Config", "\346\221\206\347\203\202\346\250\241\345\274\217", 0)
        );
        _dinner->setText(QApplication::translate("Config", "\346\231\232\351\244\220", 0));
        label_2->setText(QApplication::translate("Config", "\345\212\237\350\203\275\350\256\276\347\275\256", 0));
        _clock->setText(QApplication::translate("Config", "\345\220\257\347\224\250\345\256\232\346\227\266\346\217\220\351\206\222", 0));
        label_3->setText(QApplication::translate("Config", "\345\201\217\345\245\275", 0));
        _store->setText(QApplication::translate("Config", "\350\256\260\345\275\225\345\271\266\344\275\277\347\224\250\346\227\245\347\250\213\350\256\260\345\275\225\346\224\271\350\277\233\346\216\250\350\215\220", 0));
        label_4->setText(QApplication::translate("Config", "\345\256\277\350\210\215\345\234\260\347\202\271", 0));
        _clear->setText(QApplication::translate("Config", "\346\270\205\347\251\272\350\256\260\345\275\225\346\225\260\346\215\256", 0));
        _answer->setText(QApplication::translate("Config", "\346\230\216\347\241\256\347\232\204\347\255\224\345\244\215", 0));
        _dest->setText(QApplication::translate("Config", "\346\233\264\346\224\271\345\233\276\347\211\207", 0));
        _direction->setText(QApplication::translate("Config", "\345\275\223\345\211\215\345\234\260\345\235\200:", 0));
        label_5->setText(QApplication::translate("Config", "\345\200\222\350\256\241\346\227\266\350\256\276\347\275\256", 0));
        label_6->setText(QApplication::translate("Config", "\346\216\250\350\215\220\346\226\271\345\274\217", 0));
        _refuse->setText(QApplication::translate("Config", "\345\217\226\346\266\210", 0));
        _accept->setText(QApplication::translate("Config", "\347\241\256\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
