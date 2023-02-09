#include "Socket.h"
#include "Logger.h"
#include "InetAddress.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/tcp.h>

// 析构函数 关闭套接字
Socket::~Socket()
{
    close(sockfd_); // 关闭套接字
}

// 绑定地址 参数为InetAddress类的引用 localaddr为本地地址
void Socket::bindAddress(const InetAddress &localaddr)
{
    // 绑定地址 传入套接字描述符 本地地址 本地地址长度 //返回值为0表示绑定成功
    int ret = ::bind(sockfd_, (struct sockaddr *)localaddr.getSockAddr(), sizeof(struct sockaddr_in));
    if (ret < 0)
    {
        LOG_FATAL("bind sockfd:%d fail \n", sockfd_); // 绑定失败
    }
}

//
void Socket::listen()
{
    // 监听套接字 传入套接字描述符 返回值为0表示监听成功
    if (0 != ::listen(sockfd_, SOMAXCONN))
    {
        LOG_FATAL("listen sockfd:%d fail \n", sockfd_); // 监听失败
    }
}

// 接受连接 参数为InetAddress类的指针 peeraddr为对端地址
int Socket::accept(InetAddress *peeraddr)
{
    /**
     * 1.accept函数参数不合法
     * 2.对返回的connfd没有设置非阻塞
     * Reactor模式下，accept返回的connfd是非阻塞的 one loop per thread模式下，accept返回的connfd是阻塞的
     * poller+线程池模式下，accept返回的connfd是阻塞的
     */
    sockaddr_in addr;            // 对端地址 用于保存对端地址 传入accept函数 保存对端地址 用于返回
    socklen_t len = sizeof addr; // 地址长度
    bzero(&addr, len);           // 清空地址

    // 接受连接 传入套接字描述符 对端地址 对端地址长度 返回值为新的套接字描述符 用于通信 为-1表示接受失败
    // SOCK_NONBLOCK | SOCK_CLOEXEC 为accept函数的第四个参数 用于设置非阻塞和关闭执行
    int connfd = ::accept4(sockfd_, (sockaddr *)&addr, &len, SOCK_NONBLOCK | SOCK_CLOEXEC);
    if (connfd >= 0)
    {
        peeraddr->setSockAddr(addr); // 设置对端地址  传入对端地址
    }
    return connfd; // 返回新的套接字描述符  用于通信 为-1表示接受失败
}

// 关闭写端
void Socket::shutdownWrite()
{
    if (::shutdown(sockfd_, SHUT_WR) < 0) // 关闭写端 传入套接字描述符 返回值为0表示关闭成功
    {
        LOG_ERROR("shutdownWrite error");
    }
}

// 设置套接字选项 TCP_NODELAY 为禁用Nagle算法 传入套接字描述符 选项名称 选项值 选项长度
void Socket::setTcpNoDelay(bool on)
{
    int optval = on ? 1 : 0;
    // 设置套接字选项 传入套接字描述符 选项名称 选项值 选项长度 返回值为0表示设置成功
    // IPPROTO_TCP 为传输层协议  TCP_NODELAY 为禁用Nagle算法 optval为选项值
    // static_cast<socklen_t>(sizeof optval) 为选项长度
    ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY, &optval, static_cast<socklen_t>(sizeof optval));
}

// 设置套接字选项 SO_REUSEADDR 为允许重用本地地址和端口 传入套接字描述符 选项名称 选项值 选项长度
void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;                                                 // 选项值 为1表示允许重用本地地址和端口 为0表示不允许
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval); // 设置套接字选项
}

// 设置套接字选项 SO_REUSEPORT 为允许重用本地地址和端口 传入套接字描述符 选项名称 选项值 选项长度
void Socket::setReusePort(bool on)
{
    int optval = on ? 1 : 0; // 选项值 为1表示允许重用本地地址和端口 为0表示不允许
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof optval);
}

//  设置套接字选项 SO_KEEPALIVE 为启用保活机制 传入套接字描述符 选项名称 选项值 选项长度
void Socket::setKeepAlive(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof optval);
}