#include <QtGlobal>
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
//重要：在windows下并使用vc编译器才使用vld进行内存泄露测试
#if defined(Q_OS_WIN32) && defined(Q_CC_MSVC)
    #include <vld.h>
    //abort(); // trap; generates core dump
#else
    //exit(1); // goodbye cruel world

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
