#include "countpanel.h"
#include "ui_countpanel.h"
#include "functions/area.h"

CountPanel::CountPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountPanel)
{
    ui->setupUi(this);
}

CountPanel::~CountPanel()
{
    delete ui;
}

void CountPanel::on_countBtn_clicked()
{
    QString valueStr = ui->radiusLineEdit->text();
    bool ok;
    int valueInt = valueStr.toInt(&ok);
    Area *area = new Area(valueInt);
    ui->areaLabel->setNum(area->countArea());
    delete area;
}
