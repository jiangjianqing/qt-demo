#ifndef DBDAO_H
#define DBDAO_H

#include <QSqlDatabase>

enum DBTYPE{
    SQLITE,MYSQL
};

struct ConnectInfo{

};

class DBDao
{
private:
    QSqlDatabase db;
public:
    DBDao();
    ~DBDao();
};

#endif // DBDAO_H
