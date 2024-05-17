#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QDialogButtonBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleSelectionChanged();
    void Submit();

private:
    QCalendarWidget* calendar;
    QProgressBar* progress;
    QDialogButtonBox* button;
};

#endif // MAINWINDOW_H
