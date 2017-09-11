#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_countBtn_clicked();

private:
    Ui::MainWindow *ui;

    const double PI = 3.1415926;
};

#endif // MAINWINDOW_H
