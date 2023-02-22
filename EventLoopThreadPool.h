#pragma once
#include "noncopyable.h"
#include <functional>
#include <string>
#include <vector>
#include <memory>

// EventLoopThreadPool类 用于创建线程池 用于创建线程池中的线程

class EventLoop;       // 前置声明
class EventLoopThread; // 前置声明

class EventLoopThreadPool : noncopyable
{
public:
    using ThreadInitCallback = std::function<void(EventLoop *)>; // 定义EventLoopThreadPool类中的ThreadInitCallback类型 用于指向EventLoopThreadPool类中的ThreadInitCallback函数

    // baseLoop是EventLoopThreadPool类中的EventLoop指针 用于指向EventLoopThreadPool类中的EventLoop对象
    EventLoopThreadPool(EventLoop *baseLoop, const std::string &nameArg); // EventLoopThreadPool类的构造函数 用于创建EventLoopThreadPool类的对象
    ~EventLoopThreadPool();                                               // EventLoopThreadPool类的析构函数 用于销毁EventLoopThreadPool类的对象

    void setThreadNum(int numThreads) { numThreads_ = numThreads; }  // EventLoopThreadPool类中的setThreadNum函数 用于设置EventLoopThreadPool类中的线程数量
    void start(const ThreadInitCallback &cb = ThreadInitCallback()); // EventLoopThreadPool类中的start函数 用于启动EventLoopThreadPool类中的线程池

    // 如果工作再多线程中 baseLoop_默认以轮询的方式分配channel给subloop
    // 如果只有一个线程 则所有的channel都添加到baseLoop_中
    EventLoop *getNextLoop(); // EventLoopThreadPool类中的getNextLoop函数 用于获取EventLoopThreadPool类中的下一个EventLoop对象

    std::vector<EventLoop *> getAllLoops(); // EventLoopThreadPool类中的getAllLoops函数 用于获取EventLoopThreadPool类中的所有EventLoop对象

    bool started() const { return started_; }         // EventLoopThreadPool类中的started函数 用于获取EventLoopThreadPool类是否已经启动
    const std::string &name() const { return name_; } // EventLoopThreadPool类中的name函数 用于获取EventLoopThreadPool类中的名称
private:
    EventLoop *baseLoop_; // EventLoopThreadPool类中的EventLoop指针 用于指向EventLoopThreadPool类中的EventLoop对象
    std::string name_;    // EventLoopThreadPool类中的std::string对象 用于存储EventLoopThreadPool类中的名称
    bool started_;        // EventLoopThreadPool类中的bool变量 用于标记EventLoopThreadPool类是否已经启动
    int numThreads_;      // EventLoopThreadPool类中的int变量 用于存储EventLoopThreadPool类中的线程数量
    int next_;            // EventLoopThreadPool类中的int变量 用于存储EventLoopThreadPool类中的下一个线程的索引

    std::vector<std::unique_ptr<EventLoopThread>> threads_; // EventLoopThreadPool类中的std::vector<std::unique_ptr<EventLoopThread>>对象 用于存储EventLoopThreadPool类中的EventLoopThread对象
    std::vector<EventLoop *> loops_;                        // EventLoopThreadPool类中的std::vector<EventLoop *>对象 用于存储EventLoopThreadPool类中的EventLoop指针
};
