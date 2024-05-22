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

private slots:
    void handleSelectionChanged();
    void Submit();
    void ClassImport();
    void ClassModify();
    void Personalize();
    void oneday(const QDate&date);

private:
    Ui::MainWindow *ui;
    QWidget* _pkumap;
    QTime classstart[13]{{8,0,0},{9,0,0},{10,10,0},{11,10,0},{13,0,0},{14,0,0},{15,10,0},{16,10,0},{17,10,0},{18,40,0},{19,40,0},{20,40,0}};
    QTime classend[13]{{8,50,0},{9,50,0},{11,0,0},{12,0,0},{13,50,0},{14,50,0},{16,0,0},{17,0,0},{18,0,0},{19,30,0},{20,30,0},{21,30,0}};
    schedule classschedule;
};

#endif // MAINWINDOW_H
