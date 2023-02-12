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
private:
    EventLoop *baseLoop_; // EventLoopThreadPool类中的EventLoop指针 用于指向EventLoopThreadPool类中的EventLoop对象
    std::string name_;    // EventLoopThreadPool类中的std::string对象 用于存储EventLoopThreadPool类中的名称
    bool started_;        // EventLoopThreadPool类中的bool变量 用于标记EventLoopThreadPool类是否已经启动
    int numThreads_;      // EventLoopThreadPool类中的int变量 用于存储EventLoopThreadPool类中的线程数量
    int next_;            // EventLoopThreadPool类中的int变量 用于存储EventLoopThreadPool类中的下一个线程的索引

    std::vector<std::unique_ptr<EventLoopThread>> threads_; // EventLoopThreadPool类中的std::vector<std::unique_ptr<EventLoopThread>>对象 用于存储EventLoopThreadPool类中的EventLoopThread对象
    std::vector<EventLoop *> loops_;                        // EventLoopThreadPool类中的std::vector<EventLoop *>对象 用于存储EventLoopThreadPool类中的EventLoop指针
};
