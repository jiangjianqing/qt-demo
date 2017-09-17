#ifndef SMART_PTR2_H
#define SMART_PTR2_H

//自定义模板实现动态数组的管理
template<typename T>
std::shared_ptr<T> make_shared_array(size_t size);

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

//支持普通指针的unique_ptr
template<class T,class... Args> inline
typename std::enable_if<!std::is_array<T>::value,std::unique_ptr<T>>::type
make_unique(Args&&... args);

class smart_ptr2
{
public:
    smart_ptr2();


};

#endif // SMART_PTR2_H
