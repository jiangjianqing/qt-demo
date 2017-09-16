#include <QCoreApplication>
#include <QDebug>
#include "util/stringutil.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"故意泄露的范例，借此理解valgrind的判定机制"<<endl;

    char* pt = new char[123]();
    pt = new char[456];//上述pt[123]会被valgrind立即检测到泄露,但pt[456]还是无法被检测到，
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


    return a.exec();
}
