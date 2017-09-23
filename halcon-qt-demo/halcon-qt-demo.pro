#-------------------------------------------------
#
# Project created by QtCreator 2017-09-22T14:52:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = halcon-qt-demo
TEMPLATE = app

#加入halcon配置
#includes
INCLUDEPATH += "$$(HALCONROOT)/include"
INCLUDEPATH += "$$(HALCONROOT)/include/halconcpp"
#libs
QMAKE_LIBDIR     += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
unix:LIBS   += -lhalconcpp -lhalcon -ldl -lpthread
win32:LIBS  += halconcpp.lib halcon.lib
#在此处明确指出，不问是32位还是64位，前面都是win32：LIBS这个作为windows平台下的设置，我已经做完测试



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
    halconutil.cpp

HEADERS += \
        mainwindow.h \
    halconutil.h \
    ../utils/msvc_compatible.h

FORMS += \
        mainwindow.ui
