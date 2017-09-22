#include "mainwindow.h"
#include <QApplication>

//重要：在windows下并使用vc编译器才使用vld进行内存泄露测试
#if defined(Q_OS_WIN32) && defined(Q_CC_MSVC) && defined(_DEBUG)
    #include <vld.h>
    //abort(); // trap; generates core dump
#else
    //exit(1); // goodbye cruel world

#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
