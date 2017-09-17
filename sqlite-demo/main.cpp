#include <QCoreApplication>
#include <QDebug>
#include "util/stringutil.h"
#include "util/dbdao.h"
#include <QSqlRecord>
#include <QTime>
#include <QVariant>
#include <QSqlError>

void doStringExample(){
    qDebug()<<"故意泄露的范例，借此理解valgrind的判定机制"<<endl;

    char* pt = new char[123]();
    char* pt2 = pt;
    pt = new char[456];//上述pt[123]会被valgrind立即检测到泄露,但pt[456]还是无法被检测到，
    //重要结论：由此 可见pt[456]的泄露需要人工发现&处理，
    //valgrind的机制也许记录每个指针指向的地址，如果该地址执行过delete则认为被释放；如果到软件退出时该地址都没有被释放则认为内存泄露;
    //valgrind的机制：指针申请后又被重新申请，软件退出时将判定该指针区域为泄露。
    //最佳实践：每个指针变量在离开其作用域时都赋值为nullptr最保险
    delete []pt2;
    pt2=nullptr;
    delete []pt;
    pt=nullptr;


    char* mm;
    int len;
    StringUtil::qstring2pchar(QString("1234567"),&mm,&len);

    qDebug()<<mm<<endl;  //调试时，在console中输出


    qDebug()<<StringUtil::pchar2qstring(mm);
    delete []mm;

    char* mm2 = StringUtil::qstring2pchar(QString("tttttt"));
    qDebug()<<mm2;
    delete []mm2;
    //delete []mm;
}

void doDBExample(){
    DatabaseConnectInfo connectInfo;
    connectInfo.enumDbType=DBTYPE::SQLITE;
    connectInfo.strUserName="jjq";
    connectInfo.strPassword="";
    connectInfo.strHostName="localhost";
    connectInfo.strDatabaseName="qtDB.db";

    DBDao dao;
    if (dao.connect(connectInfo) == false){
        qDebug()<<QObject::tr("连接数据库失败");
        return;
    }
    qDebug()<<QObject::tr("连接数据库成功");

    QSqlQuery query= dao.createQuery();
    query.exec("drop table automobile");
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
    bool success = query.exec(sql);

    if(success){
        qDebug()<<QObject::tr("数据库表创建成功");
    }else{
        qDebug()<<QObject::tr("数据库表创建失败");
    }

    query.exec("select * from automobile");
    QSqlRecord rec = query.record();
    qDebug()<<QObject::tr("automobile 表字段数:")<<rec.count();

    //插入记录
    QTime t;
    t.start();
    query.prepare("insert into automobile values(?,?,?,?,?,?,?,?,?,?)");

    QVariant params[9]={
        "四轮","轿车","富康",rand()%100,rand()%10000,rand()%300,rand()%200000,rand()%52,rand()%100
    };
    long records = 100;
    for(int i=0;i<records;i++){
        for(int j=0;j<9;j++){
            query.bindValue(0,i);
            query.bindValue(j+1,params[j]);
        }
        success=query.exec();
        if(!success){
            QSqlError lastError = query.lastError();
            //重要：lastError.driverText()的值由数据库返回错误原因:比如"Parameter count mismatch"
            qDebug()<<lastError.driverText()<<QObject::tr("插入失败");
        }
    }
    qDebug()<<QString(QObject::tr("插入 %1 条记录，耗时： %2 ms")).arg(records).arg(t.elapsed());

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    doStringExample();

    doDBExample();

    return a.exec();
}
