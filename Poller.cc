#include "Poller.h"
#include "Channel.h"

// 构造函数 初始化成员变量 ownerLoop_ 事件循环 Poller所属的事件循环EventLoop
Poller::Poller(EventLoop *loop)
    : ownerLoop_(loop)
{
}

bool Poller::hasChannel(Channel *channel) const
{
    // 判断channel通道是否在当前的IO复用中
    // 通过channel通道的fd_成员变量来判断
    auto it = channels_.find(channel->fd());
    return it != channels_.end() && it->second == channel;
}