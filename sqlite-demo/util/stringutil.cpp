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

    //char* pt = new char[123]();
    //pt = new char[456];//上述pt[123]会被valgrind立即检测到泄露,但pt[456]还是无法被检测到，
    //重要结论：由此 可见pt[456]的泄露需要人工发现&处理，
    //valgrind的机制也许记录每个指针指向的地址，如果该地址执行过delete则认为被释放；如果到软件退出时该地址都没有被释放则认为内存泄露;
    //valgrind的机制：指针申请后又被重新申请，软件退出时将判定该指针区域为泄露。
    //最佳实践：每个指针变量在离开其作用域时都赋值为nullptr最保险

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
