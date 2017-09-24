#ifndef TASKCPP_H
#define TASKCPP_H

#include <future>
#include <iostream> //std::out
#include <functional> //std::function

#include <vector>
#include <map>

//using namespace std;

template<typename T>
class Task;

template<typename R, typename...Args>
class Task<R(Args...)>
{
    std::function<R(Args...)> m_fn;
public:
    typedef R return_type;

    template<typename F>
    auto then(F&& f)->Task<typename std::result_of<F(R)>::type(Args...)>{
        typedef typename std::result_of<F(R)>::type ReturnType;
        auto func = std::move(m_fn);
        return Task<ReturnType(Args...)>([func,&f](Args&&... args){
            std::future<R> lastf = std::async(func,std::forward<Args>(args)...);
            return std::async(f,lastf.get()).get();
        });

    }

    Task(std::function<R(Args...)>&& f) :m_fn(std::move(f)){}
    Task(std::function<const R(Args...)>& f) :m_fn(f){}
    ~Task(){

    }

    /**
     * @brief wait 等待异步操作完成
     */
    void wait(){
        std::async(m_fn).wait();
    }

    /**
     *获取异步操作的结果
     */
    template<typename... TArgs>
    R get(TArgs &&... args){
        return std::async(m_fn,std::forward<TArgs>(args)...).get();
    }

    /**
     * @brief run 发起异步操作
     * @return   返回std::shared_future对象，这里不能返回std::future,因为std::future是不可能复制的，不能作为返回值，如果要返回future，就要通过std::shared_future返回出来
     */
    std::shared_future<R> run(){
        return std::async(m_fn);
    }
};

//无法用std::shared_future<void>完成声明，所有用template完成
//template<typename R>
class TaskGroup{

    std::vector<std::shared_future<int>> m_voidGroup;
    //std::vector<std::shared_future<R>> m_voidGroup;

public:
    TaskGroup(){

    }
    ~TaskGroup(){

    }

    void run(Task<int()>&& task){
        m_voidGroup.push_back(task.run());
    }

    template<typename F>
    void run(F&& f){
        run(Task<std::result_of<F()>::type()>(std::forward<F>(f)));
    }

    template<typename F,typename... Funs>
    void run(F&& first,Funs&&... rest){
        run(std::forward<F>(first));
        run(std::forward<Funs>(rest)...);
    }

    void wait(){
        for(auto it = m_voidGroup.begin();it != m_voidGroup.end();++it){
            it->get();
        }
    }
};

#endif // TASKCPP_H
