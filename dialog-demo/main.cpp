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





#include "mainwindow.h"
#include <QApplication>

//重要：在windows下并使用vc编译器才使用vld进行内存泄露测试
#if defined(Q_OS_WIN32) && defined(Q_CC_MSVC) && defined(_DEBUG)
    #include <vld.h>
    //abort(); // trap; generates core dump
#else
    //exit(1); // goodbye cruel world

#endif

#include "../utils/translatorutil.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加入多国语言支持，多国语言由langswitch完成
    //TranslatorUtil::setResourceFormFile();//默认从资源文件中读取，如果要从文件读取多国语言，使用该函数设置
    TranslatorUtil::changeTr("zh");
    /*
    QTranslator *translator = new QTranslator();
    translator->load("lang/zh.qm");
    qDebug() << a.applicationDirPath();
    a.installTranslator(translator);
    */

    MainWindow w;
    w.show();

    return a.exec();
}
