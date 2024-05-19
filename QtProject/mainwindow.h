#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

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

private slots:
    void handleSelectionChanged();
    void Submit();
    void ClassImport();
    void ClassModify();
    void Personalize();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
