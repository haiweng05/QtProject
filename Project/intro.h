#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextBrowser>

namespace Ui {
class Intro;
}

class Intro : public QWidget
{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = nullptr);
    ~Intro();

private slots:
    void Exit();
private:
    Ui::Intro *ui;
};

#endif // INTRODUCTION_H
