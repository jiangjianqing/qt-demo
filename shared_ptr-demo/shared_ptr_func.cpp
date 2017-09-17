#include <QDebug>
#include <memory>


//自定义模板实现动态数组的管理
template<typename T>
std::shared_ptr<T> make_shared_array(size_t size)
{
    return std::shared_ptr<T>(new T[size],std::default_delete<T []>());
}

//当我们用shared_ptr管理动态数组时，需要指定删除器，因为std::shared_ptr的默认删除器不支持数组对象
/*
std::shared_ptr<int> p8(new int[10](),[](int* p){
    delete[] p;//释放动态数组
    qDebug()<<"动态数组删除器被调用";
});*/
//c++11提供的std::default_delete同样可以实现动态数组的管理
//std::shared_ptr<int> p9(new int[10](),std::default_delete<int []>());
//自定义模板实现动态数组的管理
//std::shared_ptr<int> p10 = make_shared_array<int>(10);

//定义删除器
void deleteIntPtr(int* p){//删除器
    delete p;
    qDebug()<<"destroy:shared_ptr删除器被调用";
}

//在一个类中返回指向自己的智能指针的标准写法:让目标类派生std::enable_shared_from_this<T类>
//然后使用基类的成员函数shared_from_this来返回this的shared_ptr
class A:public std::enable_shared_from_this<A>{
public:
    std::shared_ptr<A> GetSelf(){
        qDebug()<<"通过shared_from_this获取当前类的智能指针";
        return shared_from_this();
    }
};

void func(){
    qDebug()<<"shared_ptr test start:";

    std::shared_ptr<int> p(new int(1));
    std::shared_ptr<int> p2 = p;
    //std::shared_ptr<int> p3 = new int(1);//错误：不能将一个原始指针直接赋值给一个智能指针
    std::shared_ptr<int> p4 = std::make_shared<int>(1);//应该优先使用make_shared来构造智能指针，因为更加高效
    std::shared_ptr<int> ptr;
    ptr.reset(new int(1));

    if(ptr){
        qDebug() << "ptr is not null";
    }

    std::shared_ptr<int> ptr5(new int(1));
    int* pp = ptr.get();//获得原始指针


    //使用删除器
    std::shared_ptr<int> p6(new int(1),deleteIntPtr);
    std::shared_ptr<int> p7(new int,[](int* p){
        delete p;
        qDebug()<<"destroy:shared_ptr lambda表达式形式的删除器被调用";
    });

    //当我们用shared_ptr管理动态数组时，需要指定删除器，因为std::shared_ptr的默认删除器不支持数组对象
    std::shared_ptr<int> p8(new int[10](),[](int* p){
        delete[] p;//释放动态数组
        qDebug()<<"destroy:shared_ptr动态数组删除器被调用";
    });
    //c++11提供的std::default_delete同样可以实现动态数组的管理
    std::shared_ptr<int> p9(new int[10](),std::default_delete<int []>());
    //自定义模板实现动态数组的管理
    std::shared_ptr<int> p10 = make_shared_array<int>(10);

    std::shared_ptr<A> spy(new A());
    std::shared_ptr<A> p11 = spy->GetSelf();


}
