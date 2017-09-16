#ifndef BASEWINDOW_H
#define BASHWINDOW_H

#include <QWidget>

class BaseWindow : public QObject
{
    Q_OBJECT

protected:
    void changeEvent(QEvent *e);

public:
    BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

};

#endif // LANGSWITCH_H
