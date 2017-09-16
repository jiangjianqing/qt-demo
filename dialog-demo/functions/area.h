#ifndef AREA_H
#define AREA_H


class Area
{
private:
    const double PI = 3.14;
    int m_r=0;
public:
    Area();
    Area(const Area &area);
    Area(int r);
    double countArea();
};

#endif // AREA_H
