#include "area.h"

Area::Area(){

}

Area::Area(int r)
{
    m_r = r;
}

Area::Area(const Area &area){
    m_r = area.m_r;
}

double Area::countArea(){
    return m_r*m_r*PI;
}

