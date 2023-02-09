// Socket 类的声明 用于构造TcpServer类 TcpClient类 TcpConnection类
#pragma once
#include "noncopyable.h"

class InetAddress; // 前向声明 InetAddress类 用于构造Socket类

// 封装socket类 fd_套接字描述符
class Socket : noncopyable
{
public:
    explicit Socket(int sockfd) : sockfd_(sockfd) {} // 构造函数 传入套接字描述符 explicit防止隐式转换
    ~Socket();                                       // 析构函数 关闭套接字

    int fd() const { return sockfd_; }              // 返回套接字描述符 const修饰 不可修改
    void bindAddress(const InetAddress &localaddr); // 绑定地址 参数为InetAddress类的引用 localaddr为本地地址
    void listen();                                  // 监听套接字
    int accept(InetAddress *peeraddr);              // 接受连接 参数为InetAddress类的指针 peeraddr为对端地址

    void shutdownWrite();        // 关闭写端  用于TcpConnection类
    void setTcpNoDelay(bool on); // 设置TCP_NODELAY选项 用于TcpConnection类 TCP_NODELAY选项用于禁用Nagle算法
    void setReuseAddr(bool on);  // 设置SO_REUSEADDR选项 用于TcpServer类 SO_REUSEADDR选项允许多个进程或线程绑定到同一个端口
    void setReusePort(bool on);  // 设置SO_REUSEPORT选项 用于TcpServer类 SO_REUSEPORT选项允许多个进程或线程绑定到同一个端口
    void setKeepAlive(bool on);  // 设置SO_KEEPALIVE选项 用于TcpConnection类 keepalive选项用于检测连接是否断开
private:
    const int sockfd_; // 套接字描述符 const修饰 不可修改
};