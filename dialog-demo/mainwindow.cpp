#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QDebug>
#include <QLabel>
#include <QSizeGrip>
#include <QPushButton>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
}

MainWindow::~MainWindow()
{
    delete ui;
}

