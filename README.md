
win10下配置qt：

1、安装VC2015  为的是VC编译器,VDL目前只支持到vc2015
2、安装windows SDK
3、环境变量  添加以下内容：
C:\Qt\Qt5.9.1\5.9.1\msvc2015_64\bin;C:\Qt\Qt5.9.1\Tools\QtCreator\bin;C:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\x64

重启QT Creator



一般用Qt写软件，使用designer创建一个窗口，拖几个控件进行一下布局就够用了，但有些需求，需要自定义各种类型的控件，并且很多控件需要根据数据的交互，动态的添加和删除，为此学习了一下Qt的实现方法，在此记录之。

方法是，使用布局的addWidget函数添加控件，删除时使用removeWidget函数，需要设置控件的deleteLater属性，也可以使用delete直接删除。
QString objName = chk->objectName();    //得到发出信号的对象名  
    if (objName == "chk1") {  
        if(state){                          //根据状态选择增加或者删除控件  
            Frame *fm = new Frame;          //初始化一个自定义的控件类  
            fm->setObjectName(tr("1#"));    //设置新增对象名称  
            fm->setTitle(1);                //自定义函数  
            ui->verticalLayout->addWidget(fm); //添加到水平布局(这里根据需要选择布局)  
        }else{  
            Frame *fm = ui->scrollArea->findChild<Frame*>("1#"); //找到指定名称的控件  
            ui->verticalLayout->removeWidget(fm);                //移除控件  
            fm->deleteLater();                                     
            //delete fm;                                         //使用delete也可以  
        }  