#pragma once

#include "noncopyable.h"
#include "Timestamp.h"

#include <vector>
#include <unordered_map>

class Channel;
class EventLoop;

// muduo网络库中多路事件分发器的核心IO复用模块
// 该类是一个抽象类，它的派生类有PollPoller和EPollPoller
class Poller : noncopyable
{
public:
    using ChannelList = std::vector<Channel *>; // 保存所有的channel通道
    Poller(EventLoop *loop);                    // 构造函数
    virtual ~Poller();                          // 析构函数(虚函数)

    // 给所有IO复用保留统一的接口
    virtual Timestamp poll(int timeoutMs, ChannelList *activeChannels) = 0; // 纯虚函数 参数：超时时间 活跃的channel通道
    virtual void updateChannel(Channel *channel) = 0;                       // 纯虚函数 更新channel通道 参数：channel通道
    virtual void removeChannel(Channel *channel) = 0;                       // 纯虚函数 移除channel通道 参数：channel通道

    // 判断是否在当前的IO复用中 即Poller中
    bool hasChannel(Channel *channel) const; // 判断channel通道是否在当前的IO复用中 const修饰的成员函数不能修改成员变量

    // EventLoop可以通过该接口获取默认的IO复用的具体实现
    static Poller *newDefaultPoller(EventLoop *loop); // 生成默认的IO复用的具体实现
protected:
    // map的key ：sockfd
    // map的value：Channel对象 sockfd所属的channel通道类型
    using ChannelMap = std::unordered_map<int, Channel *>;
    ChannelMap channels_; // 保存所有的channel通道
private:
    EventLoop *ownerLoop_; // 事件循环 Poller所属的事件循环EventLoop
};