#include "area.h"

Area::Area(){
    m_array = new int[100];
}
Area::~Area(){
    if (m_array){
        delete []m_array;//重要：释放数组的方式
    }
}

Area::Area(const int &r)
{
    m_r = r;
}

Area::Area(const Area &area){
    m_r = area.m_r;
}

double Area::countArea(){
    return m_r*m_r*PI;
}

