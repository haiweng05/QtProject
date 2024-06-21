#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    QMainWindow*& mainwindow();

private slots:
    void ShowLaunch();

private:
    Ui::Menu *ui;
    QMainWindow* _mainwindow;
};

#endif // MENU_H
