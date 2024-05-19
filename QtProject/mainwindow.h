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
