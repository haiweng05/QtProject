#ifndef CLASSIMPORTWINDOW_H
#define CLASSIMPORTWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClassImportWindow;
}

class ClassImportWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClassImportWindow(QWidget *parent = nullptr);
    ~ClassImportWindow();

private:
    Ui::ClassImportWindow *ui;
};

#endif // CLASSIMPORTWINDOW_H
