#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "../utils/stringutil.h"

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
    QString filePath;

    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("Open Image"));
    fileDialog->setDirectory(".");
    //fileDialog->setFilter(tr("Image Files(*.jpg *.png *.bmp)"));
    if(fileDialog->exec() == QDialog::Accepted) {
        filePath = fileDialog->selectedFiles()[0];
        QMessageBox::information(NULL, tr("Path"), tr("You selected ") + filePath);
    }else{
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        return;
    }


    ReadImage(&img, StringUtil::qstring2pchar(filePath));

    Hlong width, height;
    img.GetImageSize(&width, &height);

    //在qt界面中显示HImage
    Hlong winID=(Hlong)this->winId();//添加位置qt混合添加段
    //hv_WindowID = (Hlong)ui->graphicsView->window()->winId();
    OpenWindow(0, 0, 0.5*width, 0.5*height,winID,"","",&hv_WindowID);//修改这句 添加winID
    //OpenWindow(0,0,hv_Width/7,hv_Height/7,winID,"","",&hv_WindowID);//修改这句 添加winID
    HDevWindowStack::Push(hv_WindowID);
    if (HDevWindowStack::IsOpen())
        DispObj(img, HDevWindowStack::GetActive());
    //HWindow w(0, 0, 0.5*width, 0.5*height);
    //img.DispImage(w);
    //DispObj(img,(Hlong)ui->graphicsView->window()->winId());
    //w.Click();
    //w.ClearWindow();
}
