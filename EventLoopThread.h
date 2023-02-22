#pragma once

/**
 * EventLoopThread
 * 用于创建一个线程，该线程中运行一个EventLoop对象
 */

#include "Thread.h"
#include "noncopyable.h"

#include <functional>
#include <mutex>
#include <condition_variable> //用于条件变量
#include <string>

class EventLoop; // 前向声明

class EventLoopThread : noncopyable
{
public:
    // using关键字用于定义类型别名
    using ThreadInitCallback = std::function<void(EventLoop *)>; // 线程初始化回调函数

    // 构造函数 传入线程初始化回调函数和线程名称 用于创建线程 该线程中运行一个EventLoop对象
    EventLoopThread(const ThreadInitCallback &cb = ThreadInitCallback(),
                    const std::string &name = std::string());

    ~EventLoopThread(); // 析构函数

    EventLoop *startLoop(); // 启动线程 用于创建EventLoop对象

private:
    void threadFunc();             // 线程函数 用于创建EventLoop对象
    EventLoop *loop_;              // EventLoop对象 指针
    void ThreadFunc();             // 线程函数 用于创建EventLoop对象
    bool exiting_;                 // 线程退出标志
    Thread thread_;                // 线程对象
    std::mutex mutex_;             // 互斥锁 用于保护eventLoop_
    std::condition_variable cond_; // 条件变量 用于通知eventLoop_已经创建
    ThreadInitCallback callback_;  // 线程初始化回调函数
};