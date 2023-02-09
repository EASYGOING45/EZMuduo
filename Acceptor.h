#pragma once
// Acceptor.h 用于监听新连接 由Acceptor类实现 该类是不可拷贝的 该类包含一个Socket对象和一个Channel对
#include "noncopyable.h" // noncopyable 用于禁止拷贝和赋值
#include "Socket.h"      // Socket 用于创建套接字
#include "Channel.h"     // Channel 用于监听新连接

#include <functional> // std::function 用于回调函数、

class EventLoop;
class InetAddress;

class Acceptor : noncopyable
{
public:
    // using的作用是为了方便使用，可以直接使用newConnectionCallback代替std::function<void(int sockfd, const InetAddress&)>
    using newConnectionCallback = std::function<void(int sockfd, const InetAddress &)>; // 回调函数类型

    Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reuseport); // 构造函数 参数：事件循环，监听地址，是否重用端口
    ~Acceptor();                                                              // 析构函数

    // 设置回调函数 参数：回调函数
    void setNewConnectionCallback(const newConnectionCallback &cb) { newConnectionCallback_ = cb; } // 设置回调函数

    bool listenning() const { return listenning_; } // 是否正在监听
    void listen();                                  // 开始监听
private:
    void handleRead(); // 处理读事件

    EventLoop *loop_;       // 事件循环 loop_指向EventLoop对象
    Socket acceptSocket_;   // 套接字 acceptSocket_指向Socket对象
    Channel acceptChannel_; // 通道 acceptChannel_指向Channel对象

    newConnectionCallback newConnectionCallback_; // 回调函数 newConnectionCallback_指向回调函数
    bool listenning_;                             // 是否正在监听
};