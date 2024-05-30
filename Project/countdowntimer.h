#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include<QLCDNumber>
namespace Ui {
class CountDownTimer;
}

class CountDownTimer : public QWidget
{
    Q_OBJECT

public:
    explicit CountDownTimer(QWidget *parent = 0);
    ~CountDownTimer();
private slots:
    void updateTime();

    void on_Start_clicked();

    void on_End_clicked();

    void on_Reset_clicked();

private:
    Ui::CountDownTimer *ui;
    QTimer *timer;
    int m_secCnt;
    int m_minCnt;
    bool isStart;
    void resetTimer(int minutes);
};



#endif // COUNTDOWNTIMER_H
