#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//非常重要：解决中文乱码问题
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    const double PI = 3.1415926;

    void *  pArray[20];
};

#endif // MAINWINDOW_H
