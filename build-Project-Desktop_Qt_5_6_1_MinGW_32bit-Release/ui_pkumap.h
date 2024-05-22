/********************************************************************************
** Form generated from reading UI file 'pkumap.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PKUMAP_H
#define UI_PKUMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PKUMap
{
public:
    QPushButton *_prev;
    QPushButton *_showall;
    QPushButton *_config;
    QLabel *_picture;
    QPushButton *_next;
    QGraphicsView *_graph;

    void setupUi(QWidget *PKUMap)
    {
        if (PKUMap->objectName().isEmpty())
            PKUMap->setObjectName(QStringLiteral("PKUMap"));
        PKUMap->resize(1620, 1160);
        PKUMap->setMinimumSize(QSize(1080, 820));
        _prev = new QPushButton(PKUMap);
        _prev->setObjectName(QStringLiteral("_prev"));
        _prev->setGeometry(QRect(70, 1110, 80, 24));
        _showall = new QPushButton(PKUMap);
        _showall->setObjectName(QStringLiteral("_showall"));
        _showall->setGeometry(QRect(440, 1110, 80, 24));
        _config = new QPushButton(PKUMap);
        _config->setObjectName(QStringLiteral("_config"));
        _config->setGeometry(QRect(650, 1110, 80, 24));
        _picture = new QLabel(PKUMap);
        _picture->setObjectName(QStringLiteral("_picture"));
        _picture->setGeometry(QRect(0, 0, 1080, 1));
        _picture->setAlignment(Qt::AlignCenter);
        _next = new QPushButton(PKUMap);
        _next->setObjectName(QStringLiteral("_next"));
        _next->setGeometry(QRect(250, 1110, 80, 24));
        _graph = new QGraphicsView(PKUMap);
        _graph->setObjectName(QStringLiteral("_graph"));
        _graph->setGeometry(QRect(0, 0, 1620, 1080));
        _picture->raise();
        _next->raise();
        _config->raise();
        _prev->raise();
        _showall->raise();
        _graph->raise();

        retranslateUi(PKUMap);

        QMetaObject::connectSlotsByName(PKUMap);
    } // setupUi

    void retranslateUi(QWidget *PKUMap)
    {
        PKUMap->setWindowTitle(QApplication::translate("PKUMap", "Form", 0));
        _prev->setText(QApplication::translate("PKUMap", "\344\270\212\344\270\200\346\255\245", 0));
        _showall->setText(QApplication::translate("PKUMap", "\346\230\276\347\244\272\345\205\250\351\203\250", 0));
        _config->setText(QApplication::translate("PKUMap", "\350\212\202\347\202\271\350\256\276\347\275\256", 0));
        _picture->setText(QApplication::translate("PKUMap", "\345\234\260\345\233\276", 0));
        _next->setText(QApplication::translate("PKUMap", "\344\270\213\344\270\200\346\255\245", 0));
    } // retranslateUi

};

namespace Ui {
    class PKUMap: public Ui_PKUMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PKUMAP_H
