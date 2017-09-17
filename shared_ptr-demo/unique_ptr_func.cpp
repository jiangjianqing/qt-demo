#include <QDebug>
#include <memory>

//支持普通指针的unique_ptr
template<class T,class... Args> inline
typename std::enable_if<!std::is_array<T>::value,std::unique_ptr<T>>::type
make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//支持动态数组
template<class T> inline
typename std::enable_if<std::is_array<T>::values && std::extent<T>::value==0,std::unique_ptr<T>>::type
make_unique(size_t size)
{
    typedef typename std::remove_extent<T>::type U;
    return std::unique_ptr<T>(new U[size]());
}

//过滤掉定长数组的情况
template<class T, class... Args>
typename std::enable_if<std::extent<T>::value != 0,void>::type make_unique(Args&&...) = delete;

void unique_ptr_test(){
    std::unique_ptr<int> myPtr(new int);
    //std::unique_ptr myOtherPtr = myPtr;//错误写法，不能复制
    std::unique_ptr<int> myOtherPtr = std::move(myPtr);//只能移动指针，不能复制指针


    //C++11目前还没有提供make_unique方法,C++14中会提供和make_shared类似的make_unique来创建unique_ptr
    //目前自己模仿
    std::unique_ptr<int> p1 = make_unique<int>(1);
    //std::unique_ptr<int[]> p1 = make_unique<int>(1);


    std::unique_ptr<int,void(*)(int*)> ptr2(new int(1),[](int *p){
        qDebug()<<"destory:unique_ptr的删除器写法";
        delete p;
    });
    std::unique_ptr<int,std::function<void(int*)>> ptr(new int(1),[&](int * p){
        qDebug()<<"destory:unique_ptr的删除器支持lambda的写法";
        delete p;
    });
}
