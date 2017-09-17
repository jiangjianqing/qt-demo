#include "mainwindow.h"
#include <QApplication>

#include "../utils/stringutil.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    StringUtil::doExample();

    return a.exec();
}
