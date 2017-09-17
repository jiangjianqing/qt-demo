#-------------------------------------------------
#
# Project created by QtCreator 2017-09-11T22:04:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dialog-demo
TEMPLATE = app


#判断CPU类型
greaterThan(QT_MAJOR_VERSION, 4) {
    TARGET_ARCH=$${QT_ARCH}
} else {
    TARGET_ARCH=$${QMAKE_HOST.arch}
}

contains(TARGET_ARCH, x86_64) {
    ARCHITECTURE = x64
    #message("x64")
} else {
    ARCHITECTURE = x86
    #message("x86")
}

#make 或make debug -------生成debug版
#make release          -------生成release版
#make all                 -------两个版本都生成
CONFIG+=debug_and_release
CONFIG(debug, debug|release){#TARGET = ui_debug
    win32 {
        LIBS += -L$$PWD/../build/mydll-Desktop_Qt_5_9_1_MSVC2017_64bit-Debug/debug -lmydll
    }
    unix{
        LIBS += -L$$PWD/../build/mydll-Desktop_Qt_5_9_1_GCC_64bit-Debug -lmydll
    }
} else {#TARGET = ui_release

    win32 {
        LIBS += -L$$PWD/../build/mydll-Desktop_Qt_5_9_1_MSVC2017_64bit-Debug/debug -lmydll
    }
    unix{
        LIBS += -L$$PWD/../build/mydll-Desktop_Qt_5_9_1_GCC_64bit-Release -lmydll
    }
    #屏蔽release版本中所有QDebug()提示信息
    DEFINES+=QT_NO_DEBUG_OUTPUT
}

#多国语言支持：推荐使用ISO标准中语言的简写形式
TRANSLATIONS += lang/en.ts  \
    lang/zh.ts



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
    countpanel.cpp \
    langswitch.cpp \
    ../utils/translatorutil.cpp \
    functions/area.cpp

HEADERS += \
        mainwindow.h \
    countpanel.h \
    langswitch.h \
    ../utils/translatorutil.h \
    functions/area.h

FORMS += \
        mainwindow.ui \
    countpanel.ui

DISTFILES +=

RESOURCES += \
    res.qrc
