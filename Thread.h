#pragma once
// Thread类 用于创建线程
#include "noncopyable.h"

#include <functional> //std::function
#include <thread>     //std::thread
#include <memory>     //std::shared_ptr
#include <unistd.h>   //sleep
#include <string>
#include <atomic> //原子操作 std::atomic

class Thread : noncopyable
{
public:
    // using的作用是为了简化代码，将std::function<void()>简化为ThreadFunc
    using ThreadFunc = std::function<void()>; // 线程函数类型 用于创建线程函数

    // explicit的作用是防止隐式转换
    explicit Thread(ThreadFunc, const std::string &name = std::string()); // 显示构造函数
    ~Thread();                                                            // 析构函数

    void start(); // 用于创建线程
    void join();  // 用于回收线程 用于回收线程资源

    bool started() const { return started_; }         // 用于判断线程是否已经启动
    pid_t tid() const { return tid_; }                // 用于获取线程id pid_t是一个整型数据类型，用于存储进程id
    const std::string &name() const { return name_; } // 用于获取线程名

    static int numCreated() { return numCreated_; } // 用于获取线程创建的数量
private:
    void setDefaultName(); // 用于设置线程名

    bool started_;                        // 用于判断线程是否已经启动
    bool joined_;                         // 用于判断线程是否已经回收
    std::shared_ptr<std::thread> thread_; // 用于创建线程
    pid_t tid_;                           // 用于获取线程id
    ThreadFunc func_;                     // 用于创建线程函数
    std::string name_;                    // 用于获取线程名
    static std::atomic<int> numCreated_;  // 用于获取线程创建的数量 atomic是原子操作
};