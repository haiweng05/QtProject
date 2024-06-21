#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextBrowser>

namespace Ui {
class Introduction;
}

class Introduction : public QWidget
{
    Q_OBJECT

public:
    explicit Introduction(QWidget *parent = nullptr);
    ~Introduction();

private slots:
    void Exit();
private:
    Ui::Introduction *ui;
};

#endif // INTRODUCTION_H
