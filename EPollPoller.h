#pragma once

#include "Poller.h"
#include "Timestamp.h"

#include <vector>
#include <sys/epoll.h>

class Channel;

/**
 * EPoll的使用
 * epoll_create()创建一个epoll句柄
 * epoll_ctl()注册事件 add/mod/del
 * epoll_wait()等待事件发生
 */
class EPollPoller : public Poller
{
public:
    EPollPoller(EventLoop *loop); // 构造函数 传入EventLoop 用于更新Channel
    ~EPollPoller() override;      // 析构函数 关闭epoll句柄 释放空间 override表示重写基类的虚函数

    // 重写基类Poller的抽象方法
    Timestamp poll(int timeoutMs, ChannelList *activeChannels) override; // 轮询事件 返回活跃的Channel 传入超时时间和活跃的Channel列表
    void updateChannel(Channel *channel) override;                       // 更新Channel 传入Channel 重写基类的虚函数
    void removeChannel(Channel *channel) override;                       // 移除Channel 传入Channel 重写基类的虚函数
private:
    static const int kInitEventListSize = 16; // 初始化事件列表大小
    // 填写活跃的Channel连接
    void fillActiveChannels(int numEvents, ChannelList *activeChannels) const; // 传入活跃的Channel数量和活跃的Channel列表

    // 更新Channel
    void update(int operation, Channel *channel); // 传入操作类型和Channel

    using EventList = std::vector<struct epoll_event>; // 事件列表

    int epollfd_;      // epoll句柄
    EventList events_; // 事件列表
};