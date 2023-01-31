#pragma once

/*
noncopyable类被继承后 派生类对象可以正常进行构造和析构操作
但是无法进行拷贝构造和赋值操作
*/

class noncopyable
{
public:
    noncopyable(const noncopyable &) = delete;
    noncopyable &operator=(const noncopyable &) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};
