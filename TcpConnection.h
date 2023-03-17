// TcpConnection.h
#include "noncopyable.h"
#include "InetAddress.h"
#include "Callbacks.h"
#include "Buffer.h"
#include "Timestamp.h"

#include <memory>
#include <string>
#include <atomic>

// 类的前向声明
class Channel;
class EventLoop;
class Socket;

/**
 * TcpServer => Acceptor => 有一个新用户连接，通过accept函数拿到connfd
 * =>TcpConnection 设置回调 =>Channel =>Poller =>Channel回调操作
 */

// enable_shared_from_this<TcpConnection> 用于解决TcpConnection对象的生命周期问题
class TcpConnection : noncopyable, public std::enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(EventLoop *loop,
                  const std::string &name,
                  int sockfd,
                  const InetAddress &localAddr,
                  const InetAddress &peerAddr);
    ~TcpConnection();

    EventLoop *getLoop() const { return loop_; }                   // 获取所属的EventLoop
    const std::string &name() const { return name_; }              // 获取连接的名字
    const InetAddress &localAddress() const { return localAddr_; } // 获取本地地址
    const InetAddress &peerAddress() const { return peerAddr_; }   // 获取对端地址

    bool connected() const { return state_ == kConnected; } // 是否已连接

    // 发送数据
    void send(const std::string &buf);

    // 关闭连接
    void shutdown();

    // 建立连接
    void setConnectionCallback(const ConnectionCallback &cb) { connectionCallback_ = cb; }

    void setMessageCallback(const MessageCallback &cb)
    {
        messageCallback_ = cb;
    }

    void setWriteCompleteCallback(const WriteCompleteCallback &cb)
    {
        writeCompleteCallback_ = cb;
    }

    void setHighWaterMarkCallback(const HighWaterMarkCallback &cb, size_t highWaterMark)
    {
        highWaterMarkCallback_ = cb;
        highWaterMark_ = highWaterMark;
    }

    void setCloseCallback(const CloseCallback &cb)
    {
        closeCallback_ = cb;
    }

    // 连接建立
    void connectEstablished();
    // 连接销毁
    void connectDestroyed();

private:
    // enum class StateE state_的状态
    enum StateE
    {
        kDisconnected, // 断开连接
        kConnecting,   // 正在连接
        kConnected,    // 已连接
        kDisconnecting // 正在断开连接
    };
    void setState(StateE state) { state_ = state; }

    void handleRead(Timestamp reveiveTime); // 处理读事件
    void handleWrite();                     // 处理写事件
    void handleClose();                     // 处理关闭事件
    void handleError();                     // 处理错误事件

    void sendInLoop(const void *message, size_t len);
    void shutdownInLoop();

    // 注意！这里绝对不是baseLoop,因为TcpConnection都是在subLoop里面管理的
    EventLoop *loop_;        // 所属的EventLoop
    const std::string name_; // 连接的名字
    std::atomic_int state_;  // 连接的状态
    bool reading_;           // 是否正在读取数据

    // 这里类似于Acceptor Acceptor => mainLoop  TcpConnection => subLoop
    // 所以这里的socket_和channel_都是在subLoop里面的
    std::unique_ptr<Socket> socket_;   // 封装的socket
    std::unique_ptr<Channel> channel_; // 封装的channel

    const InetAddress localAddr_; // 本地地址
    const InetAddress peerAddr_;  // 对端地址

    ConnectionCallback connectionCallback_;       // 连接建立时的回调
    MessageCallback messageCallback_;             // 有读写消息时的回调
    WriteCompleteCallback writeCompleteCallback_; // 消息发送完成以后的回调
    HighWaterMarkCallback highWaterMarkCallback_; // 高水位回调
    CloseCallback closeCallback_;                 // 连接断开时的回调
    size_t highWaterMark_;                        // 高水位标记

    // 高水位标记 就是当outputBuffer_的数据量大于highWaterMark_时，就会触发高水位回调
    // 什么是高水位？ 高水位意为缓冲区已经满了，不能再写入数据了，所以需要等待缓冲区的数据被发送出去

    Buffer inputBuffer_;  // 输入缓冲区
    Buffer outputBuffer_; // 输出缓冲区
};