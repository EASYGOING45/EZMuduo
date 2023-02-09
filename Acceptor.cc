// Acceptor.cc 用于监听新连接 由Acceptor类实现 该类是不可拷贝的 该类包含一个Socket对象和一个Channel对象
#include "Acceptor.h"    // Acceptor 用于监听新连接
#include "Logger.h"      // Logger 用于日志记录
#include "InetAddress.h" // InetAddress 用于获取地址信息

#include <sys/types.h>  // socket 函数 该函数在sys/types.h中
#include <sys/socket.h> // socket 函数 该函数在sys/socket.h中
#include <errno.h>      // errno 用于获取错误码 该头文件在errno.h中
#include <unistd.h>     // close 函数 用于关闭套接字 该函数在unistd.h中

static int createNonblocking() // 创建非阻塞套接字 函数返回值：套接字描述符 该函数在Acceptor.cc中
{
    int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0); // 创建套接字 AF_INET：IPv4协议 SOCK_STREAM：TCP协议 SOCK_NONBLOCK：非阻塞 SOCK_CLOEXEC：关闭文件描述符
    if (sockfd < 0)
    {
        // 创建套接字失败 记录日志 并退出程序
        LOG_FATAL("%s:%s:%d listen socket create err:%d \n", __FILE__, __FUNCTION__, __LINE__, errno);
    }
    return sockfd;
}

// 构造函数 参数：loop：EventLoop对象 listenAddr：InetAddress对象 reuseport：是否复用端口
Acceptor::Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reuseport)
    : loop_(loop), acceptSocket_(createNonblocking()), // socket, 用于监听新连接
      acceptChannel_(loop, acceptSocket_.fd()),        // channel 用于监听新连接
      listenning_(false)                               // 是否正在监听
{
    acceptSocket_.setReuseAddr(true);      // 设置地址复用
    acceptSocket_.setReusePort(true);      // 设置端口复用
    acceptSocket_.bindAddress(listenAddr); // bind  绑定地址
    // TcpServer::start() Acceptor.listen  有新用户的连接，要执行一个回调（connfd=》channel=》subloop）
    // baseLoop => acceptChannel_(listenfd) =>
    acceptChannel_.setReadCallback(std::bind(&Acceptor::handleRead, this)); // 设置读回调函数
}

// 析构函数
Acceptor::~Acceptor()
{
    acceptChannel_.disableAll(); // 禁用所有事件
    acceptChannel_.remove();     // 从poller中移除channel
}

// 开始监听
void Acceptor::listen()
{
    listenning_ = true;             // 正在监听
    acceptSocket_.listen();         // 监听
    acceptChannel_.enableReading(); // 开启读事件
}

// 处理读事件 listenfd可读 新用户连接
void Acceptor::handleRead()
{
    InetAddress peerAddr;                         // 客户端地址 用于获取客户端地址 该类在InetAddress.h中
    int connfd = acceptSocket_.accept(&peerAddr); // 接受连接 该函数在Socket.cc中 该函数返回值：客户端套接字描述符
    if (connfd >= 0)                              // 接受连接成功
    {
        if (newConnectionCallback_) // 如果有新连接回调函数
        {
            // 有新用户的连接，要执行一个回调（connfd=》channel=》subloop）
            newConnectionCallback_(connfd, peerAddr); // 轮询找到subLoop，唤醒，分发当前的新客户端的Channel
        }
        else
        {
            // 没有新连接回调函数 关闭套接字
            ::close(connfd);
        }
    }
    else
    {
        // 接受连接失败 记录日志 并退出程序
        LOG_ERROR("%s:%s:%d accept err:%d \n", __FILE__, __FUNCTION__, __LINE__, errno);
        if (errno == EMFILE)
        {
            // 套接字描述符达到上限 记录日志 并退出程序
            LOG_ERROR("%s:%s:%d sockfd reached limit! \n", __FILE__, __FUNCTION__, __LINE__);
        }
    }
}
