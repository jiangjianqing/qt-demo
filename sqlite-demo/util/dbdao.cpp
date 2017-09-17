#include "dbdao.h"
#include <QDebug>
#include <QSqlDriver>

DBDao::DBDao()
{

}

DBDao::~DBDao()
{
    if(m_db.isOpen()){
        m_db.close();
    }
    //QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
}

bool DBDao::connect(DatabaseConnectInfo & connectInfo){
    QString qstrType;
    switch (connectInfo.enumDbType) {
    case DBTYPE::SQLITE:
        qstrType="QSQLITE";
        break;
    case DBTYPE::MYSQL:
        qstrType="QMYSQL";
        break;
    default:
        qDebug()<<"请输入需要连接的数据库类型!";
        std::abort();
        break;
    }
    m_db = QSqlDatabase::addDatabase(qstrType);
    m_db.setHostName(connectInfo.strHostName);
    m_db.setDatabaseName(connectInfo.strDatabaseName);
    m_db.setUserName(connectInfo.strUserName);
    m_db.setPassword(connectInfo.strPassword);
    m_db.setPort(connectInfo.intPort);
    m_db.setConnectOptions(connectInfo.strConnectOptions);

    //如果打开数据库出现错误，则错误信息通过m_db.lastError()获取
    return m_db.open();
}

QSqlQuery DBDao::createQuery(const QString &query){
    QSqlQuery qry(query,m_db);
    return qry;
}

int DBDao::getQuerySize(QSqlQuery & query){
    //defaultDB.driver()->hasFeature(QSqlDriver::QuerySize)
    if (m_db.driver()->hasFeature(QSqlDriver::QuerySize)) {

        return  query.size();

    } else {

        // this can be very slow
        qDebug()<<"当前数据库没有提供QuerySize，查询速度会比较慢";
        query.last();
        return query.at() + 1;

    }
}

/*
const QSqlError & DBDao::getLastError(){
    return m_db.lastError();
}
*/
