#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <QString>

class StringUtil
{
public:
    StringUtil();
    static char* qstring2pchar(const QString &qstr);
    static void qstring2pchar(const QString &qstr,char** pchar,int* len);
    static QString pchar2qstring(const char *pstr);
    static void doExample();
};

#endif // STRINGUTIL_H
