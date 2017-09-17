#include "mainwindow.h"
#include <QDebug>

#include "../utils/dbconnectdlg.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::on_configDB_triggered()
{
    DBConnectDlg dlg;
    if (dlg.exec() == QDialog::Accepted){
        qDebug()<<"dialog accept";
    }
    dlg.show();

}
