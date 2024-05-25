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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QPushButton *_accept;
    QPushButton *_refuse;
    QCheckBox *_crazythursday;
    QCheckBox *_game;
    QCheckBox *_coffee;
    QCheckBox *_exercise;
    QLabel *label_3;
    QCheckBox *_store;
    QLabel *label_4;
    QComboBox *_origin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QStringLiteral("Config"));
        Config->resize(1280, 960);
        centralwidget = new QWidget(Config);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        _breakfast = new QCheckBox(centralwidget);
        _breakfast->setObjectName(QStringLiteral("_breakfast"));
        _breakfast->setGeometry(QRect(60, 120, 360, 40));
        _lunch = new QCheckBox(centralwidget);
        _lunch->setObjectName(QStringLiteral("_lunch"));
        _lunch->setGeometry(QRect(60, 170, 360, 40));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 100, 24));
        _mode = new QComboBox(centralwidget);
        _mode->setObjectName(QStringLiteral("_mode"));
        _mode->setGeometry(QRect(60, 40, 160, 40));
        _dinner = new QCheckBox(centralwidget);
        _dinner->setObjectName(QStringLiteral("_dinner"));
        _dinner->setGeometry(QRect(60, 240, 360, 40));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 80, 100, 24));
        _clock = new QCheckBox(centralwidget);
        _clock->setObjectName(QStringLiteral("_clock"));
        _clock->setGeometry(QRect(450, 70, 360, 40));
        _accept = new QPushButton(centralwidget);
        _accept->setObjectName(QStringLiteral("_accept"));
        _accept->setGeometry(QRect(470, 780, 160, 40));
        _refuse = new QPushButton(centralwidget);
        _refuse->setObjectName(QStringLiteral("_refuse"));
        _refuse->setGeometry(QRect(710, 780, 160, 40));
        _crazythursday = new QCheckBox(centralwidget);
        _crazythursday->setObjectName(QStringLiteral("_crazythursday"));
        _crazythursday->setGeometry(QRect(60, 310, 360, 40));
        _game = new QCheckBox(centralwidget);
        _game->setObjectName(QStringLiteral("_game"));
        _game->setGeometry(QRect(60, 370, 360, 40));
        _coffee = new QCheckBox(centralwidget);
        _coffee->setObjectName(QStringLiteral("_coffee"));
        _coffee->setGeometry(QRect(60, 420, 360, 40));
        _exercise = new QCheckBox(centralwidget);
        _exercise->setObjectName(QStringLiteral("_exercise"));
        _exercise->setGeometry(QRect(60, 460, 360, 40));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 100, 24));
        _store = new QCheckBox(centralwidget);
        _store->setObjectName(QStringLiteral("_store"));
        _store->setGeometry(QRect(450, 120, 360, 40));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 200, 100, 24));
        _origin = new QComboBox(centralwidget);
        _origin->setObjectName(QStringLiteral("_origin"));
        _origin->setGeometry(QRect(450, 190, 160, 40));
        Config->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Config);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        Config->setMenuBar(menubar);
        statusbar = new QStatusBar(Config);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Config->setStatusBar(statusbar);

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
        );
        _dinner->setText(QApplication::translate("Config", "\346\231\232\351\244\220", 0));
        label_2->setText(QApplication::translate("Config", "\345\212\237\350\203\275\350\256\276\347\275\256", 0));
        _clock->setText(QApplication::translate("Config", "\345\220\257\347\224\250\345\256\232\346\227\266\346\217\220\351\206\222", 0));
        _accept->setText(QApplication::translate("Config", "\347\241\256\350\256\244", 0));
        _refuse->setText(QApplication::translate("Config", "\345\217\226\346\266\210", 0));
        _crazythursday->setText(QApplication::translate("Config", "\347\226\257\347\213\202\346\230\237\346\234\237\345\233\233", 0));
        _game->setText(QApplication::translate("Config", "\346\211\223\347\224\265\345\212\250", 0));
        _coffee->setText(QApplication::translate("Config", "\347\221\236\345\271\270", 0));
        _exercise->setText(QApplication::translate("Config", "\344\275\223\350\202\262\351\224\273\347\202\274", 0));
        label_3->setText(QApplication::translate("Config", "\345\201\217\345\245\275", 0));
        _store->setText(QApplication::translate("Config", "\350\256\260\345\275\225\345\271\266\344\275\277\347\224\250\346\227\245\347\250\213\350\256\260\345\275\225\346\224\271\350\277\233\346\216\250\350\215\220", 0));
        label_4->setText(QApplication::translate("Config", "\350\267\257\345\276\204\350\265\267\347\202\271", 0));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
