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

    Task<int ()> task([]{ return 32;});

    auto r1 = task.then([](int result){
        qDebug()<<"first result:"<<result;
        return result + 3;
    }).then([](int result)->int{
        qDebug()<<"second result:"<<result;
        return result + 3;
    }).get();

    qDebug() << r1 <<endl;

    Task<int(int)> t1([](int i)->int{
        return i;
    });

    t1.then([](int result)->std::string{
        return std::to_string(result);
    }).then([](const std::string& str)->int{
        qDebug()<<str.c_str();
       return 0;
    }).get(1);

    TaskGroup g;
    std::function<int()> f = []()->int{
        qDebug()<<"ok0";
        return 0;
    };
    auto f1 = []{
        qDebug()<<"ok1";
    };
    g.run(f,f1);


    return a.exec();
}
