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
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <QAction>
#include <QAbstractItemView>
#include <QMenu>
#include <QTime>
#include <QLineEdit>
#include <vector>
#include <QMediaContent>
#include <QInputDialog>
#include <QIcon>
#include <QMediaPlaylist>

//#undef slots

//#include <Python.h>

//#define slots Q_SLOTS

class Config;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    // 主窗口的组件
    QMediaPlayer mediaPlayer;
    QTimer* timer;
    QWidget* _pkumap;

    // 手动倒计时
    CountDownTimer* mycountdown;

    // 课程时间的数组
    QTime classstart[13]{{8,0,0},{9,0,0},{10,10,0},{11,10,0},{13,0,0},{14,0,0},{15,10,0},{16,10,0},{17,10,0},{18,40,0},{19,40,0},{20,40,0}};
    QTime classend[13]{{8,50,0},{9,50,0},{11,0,0},{12,0,0},{13,50,0},{14,50,0},{16,0,0},{17,0,0},{18,0,0},{19,30,0},{20,30,0},{21,30,0}};


    // 课表
    schedule classschedule;

    // 文件读写用的变量
    FileIO files;

    // 设置使用的变量
    Config* configs;

    // 事件推送中使用的临时量
    Event event[3];
    QWidget* adder;

    // 主界面上方菜单栏中的选项
    QAction* menu_info;
    QAction* menu_calendar;
    QAction* menu_map;
    // 表格的基础接口
    void AddRow(int row);
    void AddColumn(int column);
    template<typename T>
    void AddItem(int row,int column,T item);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 地图
    QWidget*& pkumap();

    std::vector<Event>* ClassSchedule();
    // 表格的高级接口
    void AddEvent(Event& event);
    void tableclear();
    void AddHelper(int idx = 3);

    int dayindex;//星期几
    std::vector<Event> activities;
    QHash<QDate,std::vector<Event>> Memo;

    // 事件相关的接口

    // 输入一个时间点，遍历当天的vector查找是否有空
    bool Available(QTime t);
    // 输入一个事件,遍历当天事件查找是否会产生冲突
    bool Whetherclash(QTime begin, QTime end);
    // 找到第一个在某个时间点前的事件
    int FirstBefore(QTime t);

    // 插入事件，可同时用于手动添加和随机生成
    void InsertEvent(Event& event);

    // 提供两个版本的删除课程接口
    void DeleteEvent(Event& event);
    void DeleteEvent(const QString& Sname);

    // 不论是删除还是插入课程后都需要重新排序
    void SortEvent();

    // 个性化推荐的接口

    void Bailan();
    // 向当天依据个性化添加早饭，中饭，晚饭
    void GetSingle(QString name,QTime begin,QTime end,int type);
    void GetFood();
    // 向当天添加活动
    void GetActivity();
    void GetStudy();

    // 文件读写接口
    FileIO GetFile();
    // 关于菜单栏的交互
    void HideAll();

private slots:
    // 导入课表
    void ClassImport();
    // 修改当天安排
    void ActModify();
    // 个性化设置
    void Personalize();
    // 点击日历某一天
    void oneday(const QDate&date);
    void onedayHelper(QDate date,int ignore);

    // 表格交互
    void onItemContextMenuRequested(const QPoint& pos);
    void onActiondeleteTriggered(QTableWidgetItem *item);
    void onActionaddTriggered();
    void onActioncancelTriggered(QTableWidgetItem *item);
    void onActionreviseTriggered(QTableWidgetItem *item);

    // 自动倒计时提醒
    void updateTimeDisplay();

    // 个性化推荐中的交互
    void AddActivities();
    void onButton1Clicked();
    void onButton2Clicked();
    void onButton3Clicked();

    void saveToJson();

    // 关于菜单栏的交互

    // 地图
    void ShowMap();
    void HideMap();

    // 说明
    void ShowInfo();

    // 日历
    void ShowCalendar();
    void HideCalendar();

    // 展示讲座信息

    void GetLecture();
};

#endif // MAINWINDOW_H
