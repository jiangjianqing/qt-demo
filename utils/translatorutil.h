#ifndef TRANSLATORUTIL_H
#define TRANSLATORUTIL_H

#include <QObject>

enum ResourceSourceType{
    fromFile,
    fromRes
};

class TranslatorUtil
{
private:
    static ResourceSourceType sourceType ;
    static QTranslator* sTranslator;								//(a)

public:
    TranslatorUtil();

    static void setResourceSource(ResourceSourceType type);
    static void setResourceFormFile();
    static void changeTr(const QString& langCode);
    static void clear();//程序退出时调用该方法可以避免内存泄漏
};

#endif // TRANSLATORUTIL_H
