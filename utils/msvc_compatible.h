#ifndef MSVC_COMPATIBLE_H
#define MSVC_COMPATIBLE_H

//重要：在windows下并使用vc编译器才使用vld进行内存泄露测试
#if defined(Q_OS_WIN32) && defined(Q_CC_MSVC)
    //abort(); // trap; generates core dump
#else
    //exit(1); // goodbye cruel world
    //window下C++编程转到linux系统下：
    typedef unsigned char BYTE;
    typedef int64_t LONGLONG;//解决error: ‘LONGLONG’ does not name a type
#endif



#endif // MSVC_COMPATIBLE_H
