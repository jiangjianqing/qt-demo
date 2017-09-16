#include "dbdao.h"

DBDao::DBDao()
{

}

DBDao::~DBDao()
{
    if(db.isOpen()){
        db.close();
    }
}
