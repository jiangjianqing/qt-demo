#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QWidget>

class abstractwidget : public QWidget
{
    Q_OBJECT

protected:
    void changeEvent(QEvent *e);

public:
    explicit abstractwidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ABSTRACTWIDGET_H
