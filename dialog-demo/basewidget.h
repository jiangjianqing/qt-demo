#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>

namespace Ui {
class BaseWidget;
}

class BaseWidget : public QWidget
{
    Q_OBJECT

protected:
    void changeEvent(QEvent *e);

public:
    explicit BaseWidget(QWidget *parent = 0);
    ~BaseWidget();

private:
    Ui::BaseWidget *ui;
};

#endif // BASEWIDGET_H
