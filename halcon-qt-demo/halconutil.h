#ifndef HALCONUTIL_H
#define HALCONUTIL_H

#include "HalconCpp.h"

using namespace HalconCpp;

class HalconUtil
{
public:
    HalconUtil();

    ////通过HImage获取图像高度和宽度以及数据指针
    static int HalconUtil::getCImageDataFromHImage(HImage * hImg,BYTE** ppImg,int* pnWidth,int* pnHeight,int* pnChannel);

    //转化换为halcon中的图像对象
    static HImage HalconUtil::ImageData_to_HImage(unsigned char* pImg,int nWidth,int nHeight,int nChannel);

};

#endif // HALCONUTIL_H
