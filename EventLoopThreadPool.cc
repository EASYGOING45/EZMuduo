/**
 * EventLoopThreadPool.cc
 * 用于创建多个EventLoopThread线程，每个线程都有一个EventLoop对象
 */

#include "EventLoopThreadPool.h"
#include "EventLoopThread.h"

#include <memory> // std::shared_ptr shared_ptr为智能指针，用于管理内存，防止内存泄漏

// 构造函数 初始化 baseLoop_ baseLoop_是主线程的EventLoop对象
// name_ nameArg是线程池的名字 started_ false表示线程池未启动 numThreads_ 0表示线程池中线程数为0 next_ 0表示线程池中下一个线程的索引
EventLoopThreadPool::EventLoopThreadPool(EventLoop *baseLoop, const std::string &nameArg)
    : baseLoop_(baseLoop) // baseLoop_是主线程的EventLoop对象
      ,
      name_(nameArg) // name_是线程池的名字
      ,
      started_(false) // started_ false表示线程池未启动
      ,
      numThreads_(0) // numThreads_ 0表示线程池中线程数为0
      ,
      next_(0) // next_ 0表示线程池中下一个线程的索引
{
}

EventLoopThreadPool::~EventLoopThreadPool()
{
    // Don't delete loop, it's stack variable
}

void EventLoopThreadPool::start(const ThreadInitCallback &cb)
{
    started_ = true; // started_ true表示线程池已启动

    for (int i = 0; i < numThreads_; ++i)
    {
        char buf[name_.size() + 32];                             // 用于存储线程名字 name_是线程池的名字 32是数字的最大位数
        snprintf(buf, sizeof buf, "%s%d", name_.c_str(), i);     // 将name_和i拼接成线程名字
        EventLoopThread *t = new EventLoopThread(cb, buf);       // 创建一个EventLoopThread线程
        threads_.push_back(std::unique_ptr<EventLoopThread>(t)); // 将线程添加到线程池中
        loops_.push_back(t->startLoop());                        // 将线程的EventLoop对象添加到线程池中
    }

    // 整个服务端进程只有一个线程，运行着baseloop
    if (numThreads_ == 0 && cb)
    {
        cb(baseLoop_); // 如果线程池中线程数为0，直接调用cb函数
    }
}

// 获取线程池中下一个线程的EventLoop对象
EventLoop *EventLoopThreadPool::getNextLoop()
{
    EventLoop *loop = baseLoop_; // loop是线程池中下一个线程的EventLoop对象

    if (!loops_.empty())
    {
        // 通过轮询的方式获取下一个处理事件 的loop
        loop = loops_[next_];                            // 获取线程池中下一个线程的EventLoop对象
        ++next_;                                         // next_表示线程池中下一个线程的索引
        if (static_cast<size_t>(next_) >= loops_.size()) // 如果next_大于等于线程池中线程数
        {
            next_ = 0; // next_表示线程池中下一个线程的索引
        }
    }
    return loop; // 返回线程池中下一个线程的EventLoop对象
}

// 获取线程池中所有线程的EventLoop对象
std::vector<EventLoop *> EventLoopThreadPool::getAllLoops()
{
    if (loops_.empty())
    {
        return std::vector<EventLoop *>(1, baseLoop_); // 如果线程池中线程数为0，返回主线程的EventLoop对象
    }
    else
    {
        return loops_; // 返回线程池中所有线程的EventLoop对象
    }
}