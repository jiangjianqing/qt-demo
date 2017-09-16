#ifndef AREA_H
#define AREA_H


class Area
{
private:
    const double PI = 3.14;
    int m_r=0;
    int* m_array = nullptr;//nullptr是c++ 11的指针,非常重要
public:
    Area();
    ~Area();
    Area(const Area &area);
    Area(const int &r); //经过使用valgrind观察，传入参数要标记为常量引用不会发生异常提示： Invalid write of size 8
    double countArea();
};

#endif // AREA_H
