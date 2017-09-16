#include "stringutil.h"
#include <QTextCodec>
#include <QDebug>

//QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

StringUtil::StringUtil()
{

}

char* StringUtil::qstring2pchar(const QString &qstr){
    int len = qstr.length()+1;
    //char *p=new char[len];// vs 编译器则不进行初始化
    char *pchar = new char[len]();//vs 编译器将其初始化为0
    pchar[0] = '\0';//比较好的写法
    QByteArray dome2 = qstr.toLocal8Bit();
    strcpy(pchar, dome2.data());
    return pchar;

    //转为标准字符串
    //std::string str = qstr.toStdString();
    //return str.c_str();
    //下面的转换方法会出现错误：Invalid read of size 1
    //QByteArray ba = qstr.toLatin1();//QString转char *
    //return ba.data();
}

void StringUtil::qstring2pchar(const QString &qstr,char** pchar,int* plen){
    *plen = qstr.length()+1;
    //char *p=new char[10];// vs 编译器则不进行初始化
    *pchar = new char[*plen]();//vs 编译器将其初始化为0
    (*pchar)[0] = '\0';//比较好的写法
    QByteArray dome2 = qstr.toLocal8Bit();
    strcpy(*pchar, dome2.data());
    //return dome1;

    //转为标准字符串
    //std::string str = qstr.toStdString();
    //return str.c_str();
    //下面的转换方法会出现错误：Invalid read of size 1
    //QByteArray ba = qstr.toLatin1();//QString转char *
    //return ba.data();
}

QString StringUtil::pchar2qstring(const char *pstr){
    return QString(pstr);
}

/**
 * @brief StringUtil::doExample   |   char*标准用例，测试内存泄露
 */
void StringUtil::doExample(){
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
}
