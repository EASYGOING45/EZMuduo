// CurrentThread.h 头文件 用于获取当前线程的信息
//   Path: CurrentThread.h
#pragma once

#include <unistd.h>      // for getpid() 用于获取进程的id
#include <sys/syscall.h> // for SYS_xxx definitions 用于获取系统调用的定义

namespace CurrentThread
{
    extern __thread int t_cachedTid; // 线程的id 用于标识线程 extern的作用是声明一个全局变量

    void cacheTid(); // 用于获取线程的id cacheTid()函数的作用是获取线程的id

    // inline关键字的作用是告诉编译器，这个函数是内联函数，内联函数的作用是将函数的代码直接插入到调用函数的地方，而不是调用函数
    inline int tid()
    {
        if (__builtin_expect(t_cachedTid == 0, 0)) // __builtin_expect()函数的作用是告诉编译器，这个条件分支的可能性是多少
        {
            cacheTid();
        }
        return t_cachedTid;
    }
}