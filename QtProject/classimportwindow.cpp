#include "classimportwindow.h"
#include "ui_classimportwindow.h"

ClassImportWindow::ClassImportWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClassImportWindow)
{
    ui->setupUi(this);
}

ClassImportWindow::~ClassImportWindow()
{
    delete ui;
}
