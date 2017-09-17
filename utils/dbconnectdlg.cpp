#include "dbconnectdlg.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

DBConnectDlg::DBConnectDlg(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);

    QStringList drivers = QSqlDatabase::drivers();
    ui.cbDriverList->addItems(drivers);
}

void DBConnectDlg::on_btnAccept_clicked()
{
    //对话框有accept 、 reject 、 done 三种状态
    accept();
}

void DBConnectDlg::on_btnReject_clicked()
{
    reject();
}

void DBConnectDlg::on_cbDriverList_currentIndexChanged(const QString &arg1)
{
    m_connectInfo.strDatabaseDriver = arg1;
}

void DBConnectDlg::on_btnTestConnection_clicked()
{

    DatabaseConnectInfo connectInfo;
    connectInfo.strDatabaseDriver = m_connectInfo.strDatabaseDriver;
    //connectInfo.strDatabaseName = ui.ledtDatabaseName->text();
    //connectInfo.strHostName = ui.ledtHostName->text();
    //connectInfo.strUserName = ui.ledtUserName->text();
    //connectInfo.strPassword = ui.ledtPassword->text();

    QString hint;
    DBDao dao;

    if (dao.connect(connectInfo).type()== QSqlError::NoError){
        hint = "测试连接成功";
        ui.btnAccept->setEnabled(true);
    }else{
        hint = "测试连接失败";
        ui.btnAccept->setEnabled(false);
    }

    ui.lblConnectHint->setText(hint);
    qDebug()<<hint;

}
