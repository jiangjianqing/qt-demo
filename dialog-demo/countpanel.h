#ifndef COUNTPANEL_H
#define COUNTPANEL_H

#include <QWidget>

namespace Ui {
class CountPanel;
}

class CountPanel : public QWidget
{
    Q_OBJECT

public:
    explicit CountPanel(QWidget *parent = 0);
    ~CountPanel();

private slots:
    void on_countBtn_clicked();

private:
    Ui::CountPanel *ui;
};

#endif // COUNTPANEL_H
