/*
#if (defined(Q_OS_UNIX) || defined(Q_CC_MINGW))
    abort(); // trap; generates core dump
#else
    exit(1); // goodbye cruel world
#endif

#ifdef Q_OS_LINUX

    //your code

#endif


#ifdef Q_OS_WIN

    //your code
    #include <vld.h>
#endif
*/
//重要：在windows下才进行vld内存泄露测试
#if (defined(Q_OS_UNIX) || defined(Q_CC_MINGW))
    //abort(); // trap; generates core dump
#else
    //exit(1); // goodbye cruel world
    #include <vld.h>
#endif


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
