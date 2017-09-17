#include <QString>
#include <QtTest>

#include <QSqlRecord>
#include <QTime>
#include <QVariant>
#include <QSqlError>

#include "../../util/dbdao.h"

class DaoTest : public QObject
{
    Q_OBJECT

    DBDao m_dao;
    QSqlQuery m_query;
    QTime m_timer;
public:
    DaoTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1_data();
    void testCase1();
    void test1Query();
    void test2Insert();
    void test3Sort();
    void test4Update();
    void test5Delete();
};

DaoTest::DaoTest()
{
    DatabaseConnectInfo connectInfo;
    connectInfo.enumDbType=DBTYPE::SQLITE;
    connectInfo.strUserName="jjq";
    connectInfo.strPassword="";
    connectInfo.strHostName="localhost";
    connectInfo.strDatabaseName="qtDB.db";

    if (m_dao.connect(connectInfo).type() != QSqlError::NoError){
        qDebug()<<QObject::tr("连接数据库失败");
        return;
    }
    qDebug()<<QObject::tr("连接数据库成功");

    m_query= m_dao.createQuery();
    m_query.exec("drop table automobile");
    QString sql = "create table automobile "
                  "(id int primary key,"
                  "attribute varchar,"
                  "type varchar,"
                  "kind varchar,"
                  "nation int,"
                  "carnumber int,"
                  "elevaltor int,"
                  "distance int,"
                  "oil int,"
                  "temperature int)";
    qDebug()<<sql;
    bool success = m_query.exec(sql);

    if(success){
        qDebug()<<QObject::tr("数据库表创建成功");
    }else{
        qDebug()<<QObject::tr("数据库表创建失败");
    }


}

void DaoTest::initTestCase()
{
    qDebug()<<"initTestCase";

}

void DaoTest::cleanupTestCase()
{
}

void DaoTest::test1Query(){
    m_query.clear();
    m_timer.restart();

    m_query.exec("select * from automobile");
    QSqlRecord rec = m_query.record();
    qDebug()<<QObject::tr("automobile 表字段数:")<<rec.count();
    QVERIFY2(rec.count() == 10,"Failure");
}

void DaoTest::test2Insert(){
    m_query.clear();
    m_timer.restart();

    bool success;
    //插入记录

    m_query.prepare("insert into automobile values(?,?,?,?,?,?,?,?,?,?)");

    QVariant params[9]={
        "四轮","轿车","富康",rand()%100,rand()%10000,rand()%300,rand()%200000,rand()%52,rand()%100
    };
    long records = 100;
    for(int i=0;i<records;i++){
        for(int j=0;j<9;j++){
            m_query.bindValue(0,i);
            m_query.bindValue(j+1,params[j]);
        }
        success=m_query.exec();
        if(!success){
            QSqlError lastError = m_query.lastError();
            //重要：lastError.driverText()的值由数据库返回错误原因:比如"Parameter count mismatch"
            qDebug()<<lastError.driverText()<<QObject::tr("插入失败");
            QVERIFY2(false, "Failure");//判定失败
        }
    }
    qDebug()<<QString(QObject::tr("插入 %1 条记录，耗时： %2 ms")).arg(records).arg(m_timer.elapsed());
}

void DaoTest::test3Sort(){
    m_query.clear();
    m_timer.restart();
    //QSqlQuery query = m_dao.createQuery();

    bool success = m_query.exec("select * from automobile order by id desc");
    int records = m_dao.getQuerySize(m_query);
    if(success){
        qDebug()<<QString(QObject::tr("排序 %1 条记录，耗时： %2 ms")).arg(records).arg(m_timer.elapsed());
    }else{
        qDebug()<<QString(QObject::tr("排序失败"));
    }
    QVERIFY2(success,"Failure");
}

void DaoTest::test4Update(){

    m_timer.restart();
    bool success;

    QVariant params[9]={
        "四轮","轿车","富康",rand()%100,rand()%10000,rand()%300,rand()%200000,rand()%52,rand()%100
    };
    int records = 100;
    for(int i=0;i<records;i++){
        m_query.clear();
        m_query.prepare(QString("update automobile set attribute=? ,type=?,"
                                "kind=?,nation=?,"
                                "carnumber=?,elevaltor=?,"
                                "distance=?,oil=?,"
                                "temperature=? where id=%1").arg(i));
        for(int j=0;j<9;j++){
            m_query.bindValue(j,params[j]);
        }
        success = m_query.exec();
        if(!success){
            QSqlError lastError = m_query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("更新失败"));
            QVERIFY2(success,"Failure");
        }
    }
    qDebug()<<QString(QObject::tr("更新 %1 条记录，耗时： %2 ms")).arg(records).arg(m_timer.elapsed());

}

void DaoTest::test5Delete(){
    m_timer.restart();
    m_query.clear();
    bool success = m_query.exec("delete from automobile where id=15");
    qDebug()<<QString(QObject::tr("删除 %1 条记录，耗时： %2 ms")).arg(1).arg(m_timer.elapsed());
    QVERIFY2(success,"Failure");
}

void DaoTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void DaoTest::testCase1()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(DaoTest)

#include "tst_daotest.moc"
