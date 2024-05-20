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
    QMainWindow*& introwindow();

private slots:
    void ShowLaunch();

    void ShowIntro();

private:
    Ui::Menu *ui;
    QMainWindow* _mainwindow;
    QMainWindow* _introwindow;
};

#endif // MENU_H
