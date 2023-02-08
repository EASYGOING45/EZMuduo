#include "EPollPoller.h"
#include "Logger.h"
#include "Channel.h"

#include <errno.h>
#include <unistd.h>
#include <strings.h>

// Channel未添加到poller中
const int kNew = -1; // channel的成员变量index_的初始值

// Channel已添加到poller中
const int kAdded = 1; // channel的成员变量index_的值

// Channel已从poller中删除
const int kDeleted = 2; // channel的成员变量index_的值

EPollPoller::EPollPoller(EventLoop *loop)
    : Poller(loop),
      epollfd_(::epoll_create1(EPOLL_CLOEXEC)), // 创建epoll句柄
      events_(kInitEventListSize)               // 初始化事件列表大小
{
    if (epollfd_ < 0)
    {
        LOG_FATAL("EPollPoller::EPollPoller create error:%d \n", errno);
    }
}

EPollPoller::~EPollPoller()
{
    ::close(epollfd_); // 关闭epoll句柄
}

Timestamp EPollPoller::poll(int timeoutMs, ChannelList *activeChannels)
{
    LOG_INFO("func=%s => fd total count:%lu \n", __FUNCTION__, channels_.size());

    // epoll_wait等待事件发生
    int numEvents = ::epoll_wait(epollfd_, &*events_.begin(), static_cast<int>(events_.size()), timeoutMs); // 传入epoll句柄 事件列表 事件列表大小 超时时间 返回活跃的事件数量
    int savedErrno = errno;                                                                                 // 保存错误码 用于判断是否超时
    Timestamp now(Timestamp::now());                                                                        // 获取当前时间 用于更新Channel的lastEvents_成员变量

    if (numEvents > 0) // 如果有活跃的Channel
    {
        LOG_INFO("%d events happened \n", numEvents);         // 打印活跃的Channel数量
        fillActiveChannels(numEvents, activeChannels);        // 填写活跃的Channel
        if (static_cast<size_t>(numEvents) == events_.size()) // 如果活跃的Channel数量等于事件列表大小
        {
            events_.resize(events_.size() * 2); // 如果活跃的Channel数量等于事件列表大小 则扩大事件列表大小
        }
    }
    else if (numEvents == 0) // 如果没有活跃的Channel
    {
        LOG_INFO("func=%s => fd total count:%lu \n", __FUNCTION__, channels_.size()); // 如果没有活跃的Channel 则打印Channel数量
    }
    else // 如果epoll_wait出错
    {
        if (savedErrno != EINTR) // 如果不是被信号中断
        {
            errno = savedErrno; // 设置错误码
            LOG_ERROR("EPollPoller::poll() error:%d \n", errno);
        }
    }
    return now; // 返回当前时间
}

// channel update remove => EventLoop updateChannel removeChannel => Poller updateChannel removeChannel
/**
 *            EventLoop  =>   poller.poll
 *     ChannelList      Poller
 *                     ChannelMap  <fd, channel*>   epollfd
 */
void EPollPoller::updateChannel(Channel *channel)
{
    const int index = channel->index();                                                                        // 获取Channel的index_成员变量
    LOG_INFO("func=%s => fd=%d events=%d index=%d \n", __FUNCTION__, channel->fd(), channel->events(), index); // 打印Channel的fd_ events_ index_成员变量
    if (index == kNew || index == kDeleted)
    {
        if (index == kNew)
        {
            int fd = channel->fd();  // 获取Channel的fd_成员变量
            channels_[fd] = channel; // 将Channel添加到ChannelMap中
        }
        channel->set_index(kAdded);     // 设置Channel的index_成员变量为kAdded
        update(EPOLL_CTL_ADD, channel); // 添加Channel到epollfd中
    }
    else
    {
        int fd = channel->fd();     // 获取Channel的fd_成员变量
        if (channel->isNoneEvent()) // 如果Channel没有事件
        {
            update(EPOLL_CTL_DEL, channel); // 从epollfd中删除Channel
            channel->set_index(kDeleted);   // 设置Channel的index_成员变量为kDeleted
        }
        else
        {
            update(EPOLL_CTL_MOD, channel); // 修改epollfd中的Channel
        }
    }
}

// 从poller中删除channel
void EPollPoller::removeChannel(Channel *channel)
{
    int fd = channel->fd(); // 获取Channel的fd_成员变量
    channels_.erase(fd);    // 从ChannelMap中删除Channel

    LOG_INFO("func=%s => fd=%d\n", __FUNCTION__, fd); // 打印Channel的fd_成员变量

    int index = channel->index(); // 获取Channel的index_成员变量
    if (index == kAdded)          // 如果Channel的index_成员变量为kAdded
    {
        update(EPOLL_CTL_DEL, channel); // 从epollfd中删除Channel
    }
    channel->set_index(kNew); // 设置Channel的index_成员变量为kNew
}

// 填写活跃的Channel
void EPollPoller::fillActiveChannels(int numEvents, ChannelList *activeChannels) const
{
    for (int i = 0; i < numEvents; ++i) // 遍历活跃的Channel
    {
        Channel *channel = static_cast<Channel *>(events_[i].data.ptr); // 获取Channel   events_[i].data.ptr为Channel的地址
        channel->set_revents(events_[i].events);                        // 设置Channel的revents_成员变量
        activeChannels->push_back(channel);                             // 将Channel添加到活跃的Channel列表中
    }
}

// 更新epollfd中的Channel epoll_ctl add mod del'
void EPollPoller::update(int operation, Channel *channel)
{
    // epoll_ctl
    epoll_event event;           // 创建epoll_event结构体
    bzero(&event, sizeof event); // 初始化epoll_event结构体 为0 bzero memset

    event.events = channel->events(); // 设置epoll_event结构体的events成员变量
    event.data.fd = channel->fd();    // 设置epoll_event结构体的data成员变量
    event.data.ptr = channel;         // 设置epoll_event结构体的data成员变量

    if (::epoll_ctl(epollfd_, operation, channel->fd(), &event) < 0) // 调用epoll_ctl函数
    {
        if (operation == EPOLL_CTL_DEL) // 如果是删除操作
        {
            LOG_ERROR("epoll_ctl del error:%d\n", errno); // 打印错误信息
        }
        else // 如果是添加或修改操作
        {
            LOG_FATAL("epoll_ctl add/mod error:%d\n", errno); // 打印错误信息
        }
    }
}