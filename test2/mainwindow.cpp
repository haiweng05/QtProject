#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    calendar = new QCalendarWidget(this);
    connect(calendar, &QCalendarWidget::selectionChanged, this, &MainWindow::handleSelectionChanged);
    layout->addWidget(calendar);

    progress = new QProgressBar(this);
    layout->addWidget(progress);
    button = new QDialogButtonBox(QDialogButtonBox::Ok, this);
    // button = new QDialogButtonBox(this);
    layout->addWidget(button);

    connect(button,&QDialogButtonBox::accepted,this,&MainWindow::Submit);
    setCentralWidget(centralWidget);
}


MainWindow::~MainWindow()
{
}

void MainWindow::Submit(){
    QDate date = QDate();
    date = calendar->selectedDate();
    int d = date.day();
    progress->setValue(d);
}
void MainWindow::handleSelectionChanged()
{
    // QDate date = QDate();
    // date = calendar->selectedDate();
    // // 在这里处理选定的日期...
    // int d = date.day();
    // progress->setValue(d);

}
