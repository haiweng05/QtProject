#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QTimeEdit>
#include <QTableWidgetItem>
#include "event.h"
#include <string>
#include <QFileDialog>
#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QAxObject>
#include <QApplication>
#include <QDebug>
#include "fileio.h"
#include "schedule.h"
#include "pkumap.h"
#include "config.h"
#include <vector>
#include <QTime>
#include <QComboBox>
#include "selection.h"
#include <QHash>
#include <QTimer>
#include <QMessageBox>
#include "countdowntimer.h"
#include <QMediaPlayer>

class Config;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ShowMap();
    void AddRow(int row);
    void AddColumn(int column);
    template<typename T>
    void AddItem(int row,int column,T item);
    void AddEvent(Event& event);
    void tableclear();
    QWidget*& pkumap();
    int dayindex;//星期几
    std::vector<Event> activities;
    QHash<QDate,std::vector<Event>> Memo;

    // 输入一个时间点，遍历当天的vector查找是否有空
    bool Available(QTime t);

    // 找到第一个在某个时间点前的事件
    int FirstBefore(QTime t);

    // 插入事件，可同时用于手动添加和随机生成
    void InsertEvent(Event& event);

    // 提供两个版本的删除课程接口
    void DeleteEvent(Event& event);
    void DeleteEvent(const QString& Sname);

    // 不论是删除还是插入课程后都需要重新排序
    void SortEvent();

    // 向当天依据个性化添加早饭，中饭，晚饭

    void GetSingle(QString name,QTime begin,QTime end,int type);
    void GetFood();

    // 向当天添加活动
    void GetActivity();

    void GetStudy();

    FileIO GetFile();

    void Bailan();

    void AddHelper(int idx = 3);

    bool Whetherclash(QTime begin, QTime end);
private slots:
    void handleSelectionChanged();
    void Submit();
    void ClassImport();
    void ClassModify();
    void Personalize();


    void oneday(const QDate&date);
    void onedayHelper(QDate date,int ignore);
    void onItemContextMenuRequested(const QPoint& pos);
    void onActiondeleteTriggered(QTableWidgetItem *item);
    void onActionaddTriggered();
    void onActioncancelTriggered(QTableWidgetItem *item);
    void onActionreviseTriggered(QTableWidgetItem *item);
    void updateTimeDisplay();


    void AddActivities();

    void onButton1Clicked();


    void onButton2Clicked();


    void onButton3Clicked();

    void saveToJson();



private:
    Ui::MainWindow *ui;
    QMediaPlayer mediaPlayer;
    QTimer* timer;
    QWidget* _pkumap;
    CountDownTimer* mycountdown;
    QTime classstart[13]{{8,0,0},{9,0,0},{10,10,0},{11,10,0},{13,0,0},{14,0,0},{15,10,0},{16,10,0},{17,10,0},{18,40,0},{19,40,0},{20,40,0}};
    QTime classend[13]{{8,50,0},{9,50,0},{11,0,0},{12,0,0},{13,50,0},{14,50,0},{16,0,0},{17,0,0},{18,0,0},{19,30,0},{20,30,0},{21,30,0}};
    schedule classschedule;

    FileIO files;

    Config* configs;
    // 事件推送中使用的临时量
    Event event[3];
    QWidget* adder;
};

#endif // MAINWINDOW_H
