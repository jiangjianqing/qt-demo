#include "halconutil.h"

HalconUtil::HalconUtil()
{

}

//通过HImage获取图像高度和宽度以及数据指针
int HalconUtil::getCImageDataFromHImage(HImage* hImg,unsigned char** ppImg,int* pnWidth,int* pnHeight,int* pnChannel)
{
    HTuple channels;

    void *potImg=NULL;
    void *potRed=NULL;
    void *potGreen=NULL;
    void *potBlue=NULL;

    HString type;
    //char type[128];// = new char[128]();
    //char* type = buf;//代替HString type;

    Hlong width,height;
    Hlong Pixels_per_channel;


    //获取图像通道数目
    channels = hImg->CountChannels();
    //HImage::CountChannels(*hImg,&channels);

    //传递通道数
    *pnChannel=channels[0].I();

    if(channels[0].I()==1)
    {
        potImg=(void *)hImg->GetImagePointer1(&type,&width,&height);
        Pixels_per_channel=width*height;
        *pnWidth=(int)width;
        *pnHeight=(int)height;
        *ppImg=(unsigned char*)malloc(Pixels_per_channel);
        memcpy(*ppImg,potImg,Pixels_per_channel);

    }
    else if(channels[0].I()==3)
    {
        hImg->GetImagePointer3(&potRed,&potGreen,&potBlue,&type,&width,&height);
        Pixels_per_channel=width*height;
        *pnWidth=(int)width;
        *pnHeight=(int)height;
        *ppImg=(unsigned char*)malloc(Pixels_per_channel*3);
        /*memcpy(*ppImg,potRed,Pixels_per_channel);*/
        //转化为字符类型的指针，指针才能偏移

        for(int i=0;i<(*pnWidth)*(*pnHeight);i++)
        {
            *((*ppImg)+3*i)=*((unsigned char*)potRed+i);
            *((*ppImg)+3*i+1)=*((unsigned char*)potGreen+i);
            *((*ppImg)+3*i+2)=*((unsigned char*)potBlue+i);
        }


    }

    return 0;
}

//转化换为halcon中的图像对象
HImage HalconUtil::ImageData_to_HImage(unsigned char* pImg,int nWidth,int nHeight,int nChannel)
{
    HImage hImg;
    const char* type="byte";
    //int pixels_per_channel=nWidth*nHeight;
    char* c_potRed,*c_potGreen,* c_potBlue;
    if(nChannel==1)
    {
        hImg.GenImage1(type,nWidth,nHeight,pImg);
        //生成HImage对象后，释放ImgData中指针指向的内存？

    }
    //原来数据为RGB格式
    else if(nChannel==3)
    {
        //3通道图像的生成HImage
        c_potRed=(char*)malloc(nWidth*nHeight);
        c_potGreen=(char*)malloc(nWidth*nHeight);
        c_potBlue=(char*)malloc(nWidth*nHeight);
        for(int i=0;i<nWidth*nHeight;i++)
        {
            *(c_potRed+i)=*(pImg+3*i);
            *(c_potGreen+i)=*(pImg+3*i+1);
            *(c_potBlue+i)=*(pImg+3*i+2);
        }
        hImg.GenImage3(type,(Hlong)nWidth,(Hlong)nHeight,c_potRed,c_potGreen,c_potBlue);
        free(c_potRed);
        free(c_potGreen);
        free(c_potBlue);

    }
    return hImg;
}
