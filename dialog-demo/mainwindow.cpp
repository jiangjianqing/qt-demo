#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QDebug>
#include <QLabel>
#include <QSizeGrip>
#include <QPushButton>
#include <QDockWidget>
#include <QLibrary>

#include "basewidget.h"

#include "../mydll/mydll.h"

void MainWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Mydll addm;
    qDebug()<<"addm 的结果 = "<< addm.add(3,4);

    // DLL显式加载，只需要DLL文件即可，不需要.H和.LIB文件
    // 需要将DLL放到可执行目录中
    typedef int(*FUN2)(int, int);


    //TestA();
    //testB(1, 300);

    QLibrary lib("mydll.dll");
    if (lib.load()) {
        qDebug() << "load ok!";

        FUN2 add = (FUN2)lib.resolve("Mydll::add");

        if (add) {
            qDebug() << "load add ok!";
            qDebug() << add(3, 5);
        }else{
            qDebug() << "not found add function!";
        }
        lib.unload();
    } else {
        qDebug() << "load error!";
    }


    //---------菜单栏--------------------
    QMenu *menu1= new QMenu("hello");
    menu1->addAction("菜单项1");
    menu1->addAction("菜单项2");



    /*注意： 该形式触发存在缺陷，会导致菜单出现但窗体却未出现
    if(QAction *act=menu1->exec(QCursor::pos()))
    {
        qDebug()<< act->text() <<"triggered";
    }*/

    QMenu *file_menu=new QMenu("文件");
    file_menu->addAction("打开");//可用返回的QAction 连接槽函数


    //添加菜单项，添加动作
    QAction * pNew = file_menu->addAction("新建");

    connect(pNew,&QAction::triggered,
            [=]()
    {
        qDebug()<<"新建被按下了";

    });
    //file_menu->addAction("退出",this,exit,QKeySequence("Ctrl+E"));//失败
    file_menu->addSeparator();
    //file_menu->addSection("Section");//貌似无效果
    file_menu->addMenu(menu1);
    ui->menuBar->addMenu(file_menu);

    QPushButton *btnHello=new QPushButton("hello");
    ui->menuBar->setCornerWidget(btnHello,Qt::TopLeftCorner);
    //ui->menuBar->setDefaultUp(true);//设置该参数会导致菜单默认向上打开

    //工具栏--菜单项的快捷方式
    //QToolBar *toolBar = addToolBar("toolbar");//创建新的工具栏
    QToolBar *toolBar = ui->mainToolBar;//直接使用默认提供的主工具栏
    toolBar->addAction(pNew);//工具栏添加菜单项--快捷键

    QPushButton * b = new QPushButton(this);
    b->setText("OK");
    toolBar->addWidget(b);//工具栏添加其他组件--按钮

    //-------------状态栏----------------
    QLabel *lbl=new QLabel("Widget");
    QPushButton *btn=new QPushButton("PermanentWidget");
    ui->statusBar->addPermanentWidget(btn);//从右往左添加组件
    ui->statusBar->addWidget(lbl);//从左往右添加组件

    ui->statusBar->showMessage("hello",3000);

    //QSizeGrip *grip =new QSizeGrip(ui->pushButton);
    //grip->setVisible(true);//不设置这个见不到它……

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);//浮动窗口组件QDockWidget
    addDockWidget(Qt::LeftDockWidgetArea,dock);//浮动窗口里添加其他组件

    //showFullScreen();//重要：窗口全屏显示，连Title栏都不会有
    //resize(..);指定窗口大小
    showMaximized();

    pArray[0] = menu1;
    pArray[1] = file_menu;
    //pArray[pPosition++] = btnHello;

    //file_menu->deleteLater();
   // menu1->deleteLater();
    //重要：在这里释放指针虽然有效，但界面上的元素也会立即删除，所以通过pArray进行了记录,保留至~MainWindow中释放内存
}

MainWindow::~MainWindow()
{

    //重要：申明的内容必须释放，否则容易发生内存泄露
    //这里进行了3种类型的测试：
    //1、deleteLater()无法控制泄露，但在MainWindow构造函数中可以
    //2、delete void*不行，Visual Leak Detector退出时崩溃，无法获得泄露数据
    //3、delete 原类型指针，获得正确效果！！！！！！
    QMenu *menu1 = (QMenu *)pArray[0];
    //void *menu1_p = pArray[0];
    delete menu1;//->deleteLater();
    QMenu *file_menu = (QMenu *)pArray[1];
    //void *file_menu_p = pArray[1];
    delete file_menu;//->deleteLater();

    qDebug()<<"**程序退出,这里表示正确处理内存泄露";
    //qt默认
    delete ui;
}

