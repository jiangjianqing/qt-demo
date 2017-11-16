#include <QApplication>
#include <QTranslator>
#include <QDebug>

#include "translatorutil.h"

//初始化静态成员变量的格式：<数据类型><类名>::<静态数据成员> = <值>
ResourceSourceType TranslatorUtil::sourceType=ResourceSourceType::fromRes; //默认从文件读取
QTranslator* TranslatorUtil::sTranslator= nullptr;

TranslatorUtil::TranslatorUtil()
{

}

void TranslatorUtil::setResourceSource(ResourceSourceType type){
    sourceType = type;
}

void TranslatorUtil::setResourceFormFile(){//设置为从文件读取
    setResourceSource(ResourceSourceType::fromFile);
}

void TranslatorUtil::changeTr(const QString& langCode)
{
    clear();

    sTranslator = new QTranslator;
    QString resPrefix = sourceType==ResourceSourceType::fromRes? ":/" : "" ;
    QString qmFilename = resPrefix+"lang/" + langCode + ".qm"; //从资源文件中加载
    //QString qmFilename = "lang/" + langCode + ".qm";	//从目录中加载				//(b)
    //if (translator->load(QString("D:/Qt/CH14/CH1402/LangSwitch/")+qmFilename))
    if (sTranslator->load(qmFilename))
    {
            qApp->installTranslator(sTranslator);
    }else{
        qDebug()<<QString("加载translator所需的qm文件失败:")<<qmFilename;
    }
}

void TranslatorUtil::clear()
{
    if (sTranslator != nullptr)
    {
        qApp->removeTranslator(sTranslator);
        delete sTranslator;
        sTranslator = nullptr;
    }
}
