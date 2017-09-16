#include <QCoreApplication>
#include <QDebug>
#include "util/stringutil.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char* pt = new char[123]();


    char* mm;
    int len;
    StringUtil::qstring2pchar(QString("1234567"),&mm,&len);

    qDebug()<<mm<<endl;  //调试时，在console中输出


    qDebug()<<StringUtil::pchar2qstring(mm);
    delete[] mm;

    char* mm2 = StringUtil::qstring2pchar(QString("tttttt"));
    qDebug()<<mm2;
    delete[] mm2;
    //delete []mm;


    return a.exec();
}
