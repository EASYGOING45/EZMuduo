#include "EventLoopThread.h"
#include "EventLoop.h"

/**
 * EventLoopThread.h
 * 用于创建一个线程，该线程中运行一个EventLoop对象
 */

EventLoopThread::EventLoopThread(const ThreadInitCallback &cb,
                                 const std::string &name)
    : loop_(nullptr) // 初始化loop_为空
      ,
      exiting_(false) // 初始化exiting_为false
      ,
      thread_(std::bind(&EventLoopThread::threadFunc, this), name) // 初始化thread_对象
      ,
      mutex_() // 初始化mutex_对象
      ,
      cond_() // 初始化cond_对象
      ,
      callback_(cb) // 初始化callback_对象
{
    // std::bind(&EventLoopThread::threadFunc, this) 用于绑定threadFunc函数
}

// 析构函数
EventLoopThread::~EventLoopThread()
{
    exiting_ = true;
    if (loop_ != nullptr)
    {
        loop_->quit();  // 退出loop_事件循环
        thread_.join(); // 等待线程退出
    }
}

// 启动线程 用于创建EventLoop对象
EventLoop *EventLoopThread::startLoop()
{
    thread_.start(); // 启动底层的全新线程

    EventLoop *loop = nullptr;

    {
        // 以{}为界限，保证lock_guard在{}结束时自动释放锁 线程安全操作
        std::unique_lock<std::mutex> lock(mutex_); // 互斥锁 用于保护eventLoop_
        while (loop_ == nullptr)
        {
            cond_.wait(lock); // 条件变量 用于通知eventLoop_已经创建
        }
        loop = loop_; // 获取EventLoop对象
    }
    return loop; // 返回EventLoop对象
}

void EventLoopThread::threadFunc()
{
    // 创建EventLoop对象
    EventLoop loop; // 创建一个独立的eventloop事件循环 one loop per thread

    if (callback_) // 如果有回调操作
    {
        callback_(&loop); // 线程初始化回调函数
    }

    {
        std::unique_lock<std::mutex> lock(mutex_); // 互斥锁 用于保护eventLoop_
        loop_ = &loop;
        cond_.notify_one(); // notify_one为通知一个线程
    }

    loop.loop(); // EventLoop loop => Poller.poll
    std::unique_lock<std::mutex> lock(mutex_);
    loop_ = nullptr;
}