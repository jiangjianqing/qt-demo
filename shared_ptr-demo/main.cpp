#include <QCoreApplication>

#include "shared_ptr_func.cpp"
#include "unique_ptr_func.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    func();
    unique_ptr_test();

    return a.exec();
}
