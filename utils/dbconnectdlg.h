#ifndef DBCONNECTDLG_H
#define DBCONNECTDLG_H

#include "ui_dbconnectdlg.h"
#include "../utils/dbdao.h"

class DBConnectDlg : public QDialog
{
    Q_OBJECT

    DatabaseConnectInfo m_connectInfo;
public:
    explicit DBConnectDlg(QWidget *parent = 0);



private slots:
    void on_btnAccept_clicked();

    void on_btnReject_clicked();

    void on_cbDriverList_currentIndexChanged(const QString &arg1);

    void on_btnTestConnection_clicked();

private:
    Ui::DBConnectDlg ui;
};

#endif // DBCONNECTDLG_H
