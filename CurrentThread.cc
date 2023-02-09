#include "CurrentThread.h"

namespace CurrentThread
{
    //_thread关键字的作用是告诉编译器，这个变量是线程局部变量，线程局部变量的作用是每个线程都有一个独立实体，各个线程的值互不干扰
    _thread int t_cachedTid = 0; // 线程的id 用于标识线程

    // cacheTid()函数的作用是获取线程的id
    void cacheTid()
    {
        if (t_cachedTid == 0) // 如果线程的id为0
        {
            t_cachedTid = static_cast<pid_t>(::syscall(SYS_gettid)); // ::syscall()函数的作用是调用系统调用
        }
    }
}