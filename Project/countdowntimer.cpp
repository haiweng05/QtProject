#include "countdowntimer.h"
#include "ui_countdowntimer.h"
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include<QLCDNumber>
#include<QInputDialog>
CountDownTimer::CountDownTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountDownTimer)
{
    ui->setupUi(this);
    isStart = false;
    timer = new QTimer;
    m_secCnt = 0;
    m_minCnt = 0;

    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Filled);
    ui->lcdNumber->display("00:00");
    ui->End->setEnabled(false);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(ui->Reset, SIGNAL(clicked()), this, SLOT(on_Reset_clicked()));
}

CountDownTimer::~CountDownTimer()
{
    delete ui;
}

void CountDownTimer::updateTime() {
    if (m_secCnt > 0) {
        m_secCnt--;
        int minutes = m_secCnt / 60;
        int seconds = m_secCnt % 60;
        ui->lcdNumber->display(QString::number(minutes) + ":" + QString("%1").arg(seconds, 2, 10, QChar('0')));
    } else {
        ui->End->setDisabled(true);
        ui->Start->setEnabled(true);
        timer->stop();
        resetTimer(0);
        QMessageBox::information(this,
                tr("温馨提示"), tr("时间到，休息一下吧~"),
                QMessageBox::Ok | QMessageBox::Cancel,
                QMessageBox::Ok);
    }
}

void CountDownTimer::on_Start_clicked()
{
    if (!isStart) {
        timer->start(1000);
        ui->lcdNumber->display(QString::number(m_minCnt) + ":00");
        ui->Start->setDisabled(true);
        ui->End->setEnabled(true);
        isStart = true;
    }
}

void CountDownTimer::on_End_clicked()
{
    ui->End->setDisabled(false);
    ui->Start->setEnabled(true);
    isStart=false;
    timer->stop();
    resetTimer(0);
}
void CountDownTimer::on_Reset_clicked()
{
    int resetMinutes;
    isStart=0;
    bool ok=0;
    resetMinutes = QInputDialog::getInt(this, tr("重置倒计时"), tr("请输入分钟数:"), 0, 0, 60, 1, &ok);
    if (ok) {
        resetTimer(resetMinutes);
    } else {
        QMessageBox::warning(this, tr("警告"), tr("您取消了重置操作或输入了无效的分钟数。"));
    }
}

void CountDownTimer::resetTimer(int minutes)
{
    m_secCnt = minutes * 60;
    m_minCnt = minutes;
    ui->lcdNumber->display(QString::number(minutes) + ":00");
    isStart = false;
    ui->End->setDisabled(false);
    ui->Start->setEnabled(true);
}
