#include "basewindow.h"
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>
#include <QDebug>
BaseWindow::BaseWindow(QWidget *parent)
    //: QObject(parent)
{

}

void BaseWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

BaseWindow::~BaseWindow()
{

}
