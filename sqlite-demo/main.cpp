#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "../utils/stringutil.h"

#include "../utils/taskcpp.h";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    StringUtil::doExample();

    Task<int ()> task([]{ return 128128;});

    auto r1 = task.then([](int result){
        qDebug()<<"first result:"<<result;
        return result+3;
    }).get();

    qDebug() << r1 <<endl;

    return a.exec();
}
