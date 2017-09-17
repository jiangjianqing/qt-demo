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

public:
    TranslatorUtil();

    static void setResourceSource(ResourceSourceType type);
    static void setResourceFormFile();
    static void changeTr(const QString& langCode);
};

#endif // TRANSLATORUTIL_H
