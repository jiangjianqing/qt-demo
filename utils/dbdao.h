#ifndef DBDAO_H
#define DBDAO_H

#include <QSqlDatabase>
#include <QSqlQuery>

typedef struct {
    QString strDatabaseDriver;
    QString strHostName;
    QString strDatabaseName;
    QString strUserName;
    QString strPassword;
    int intPort;
    QString strConnectOptions;

} DatabaseConnectInfo;

class DBDao
{
private:
    QSqlDatabase m_db;
public:
    DBDao();
    ~DBDao();
    QSqlError connect(DatabaseConnectInfo &connectInfo);
    QSqlQuery createQuery(const QString &query = QString());

    //重要：用于获取QSqlQuery的记录数
    int getQuerySize(QSqlQuery & query);
    //const QSqlError & getLastError();
};

#endif // DBDAO_H
