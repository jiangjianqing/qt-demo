#-------------------------------------------------
#
# Project created by QtCreator 2017-09-11T22:04:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dialog-demo
TEMPLATE = app

#引用自定义dll
#LIBS += D:\git\qt-demo\build\mydll-Desktop_Qt_5_9_1_MSVC2017_64bit-Debug\debug\mydll.lib
#LIBS += -LD:/git/qt-demo/build/mydll-Desktop_Qt_5_9_1_MSVC2017_64bit-Debug/debug -lmydll
#重要：从相对路径导入动态库
LIBS += -L$$PWD/../build/mydll-Desktop_Qt_5_9_1_MSVC2017_64bit-Debug/debug -lmydll


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    countpanel.cpp

HEADERS += \
        mainwindow.h \
    countpanel.h

FORMS += \
        mainwindow.ui \
    countpanel.ui

DISTFILES +=
