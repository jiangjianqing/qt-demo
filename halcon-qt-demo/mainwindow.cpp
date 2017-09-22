#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLoadImage_clicked()
{
    HImage img;
    HTuple hv_WindowID;
    ReadImage(&img, "c:/image1.jpg");
    Hlong width, height;
    img.GetImageSize(&width, &height);

    //在qt界面中显示HImage
    Hlong winID=(Hlong)this->winId();//添加位置qt混合添加段
    OpenWindow(0, 0, 0.5*width, 0.5*height,winID,"","",&hv_WindowID);//修改这句 添加winID
    //OpenWindow(0,0,hv_Width/7,hv_Height/7,winID,"","",&hv_WindowID);//修改这句 添加winID
    HDevWindowStack::Push(hv_WindowID);
    if (HDevWindowStack::IsOpen())
        DispObj(img, HDevWindowStack::GetActive());
    //HWindow w(0, 0, 0.5*width, 0.5*height);
    //img.DispImage(w);
    //DispObj(img,ui->graphicsView);
    //w.Click();
    //w.ClearWindow();
}
