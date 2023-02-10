#include "Thread.h"
#include "CurrentThread.h"

#include <semaphore.h> //信号量 sem_t sem_init sem_wait sem_post

std::atomic_int Thread::numCreated_(0); // 用于获取线程创建的数量

// 用于设置线程名
Thread::Thread(ThreadFunc func, const std::string &name)
    : started_(false), joined_(false), tid_(0), func_(std::move(func)), name_(name)
{
    setDefaultName(); // 用于设置线程名
}

// 析构函数
Thread::~Thread()
{
    // started为true，joined为false，说明线程已经启动，但是没有回收
    if (started_ && !joined_) // 用于判断线程是否已经启动
    {
        thread_->detach(); // 用于回收线程资源
    }
}

// 用于创建线程
void Thread::start() // 一个Thread对象，记录的就是一个新线程的详细信息
{
    started_ = true;          // 用于判断线程是否已经启动
    sem_t sem;                // 信号量
    sem_init(&sem, false, 0); // 信号量初始化

    // 开启线程
    thread_ = std::shared_ptr<std::thread>(new std::thread([&]()
                                                           {
        // 获取线程的tid值
        tid_ = CurrentThread::tid();
        sem_post(&sem);
        // 开启一个新线程，专门执行该线程函数
        func_(); }));

    // 这里必须等待获取上面新创建的线程的tid值
    sem_wait(&sem); // 信号量等待
}

void Thread::join() // 用于回收线程资源
{
    joined_ = true;
    thread_->join();
}

void Thread::setDefaultName() // 用于设置线程名
{
    int num = ++numCreated_; // 用于获取线程创建的数量
    if (name_.empty())       // 用于判断线程名是否为空
    {
        char buf[32] = {0};                         // 用于存储线程名
        snprintf(buf, sizeof buf, "Thread%d", num); // 用于设置线程名
        name_ = buf;                                // 用于设置线程名
    }
}