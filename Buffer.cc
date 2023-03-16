/**
 * Buffer.cc
 */
#include "Buffer.h"
#include <errno.h>
#include <sys/uio.h>
#include <unistd.h>

/**
 * 从fd上读取数据 Poller工作在LT模式
 * Buffer缓冲区有着其大小！ 但是从fd上读取数据时，可能一次性读取的数据量大于缓冲区的大小
 * 不知道TCP数据最终的大小
 */

// 从fd上读取数据 Poller工作在LT模式 Buffer缓冲区有着其大小！ 但是从fd上读取数据时，可能一次性读取的数据量大于缓冲区的大小 不知道TCP数据最终的大小
// LT模式下，如果缓冲区的数据没有被读取完毕，那么下一次还会触发可读事件，所以需要循环读取
ssize_t Buffer::readFd(int fd, int *saveErrno)
{
    char extrabuf[65536] = {0}; // 64k 一次性读取的数据量大于缓冲区的大小
    // iovec结构体 用于readv函数
    struct iovec vec[2]; // 两个缓冲区 一个是缓冲区的数据，一个是extrabuf

    const size_t writable = writableBytes();  // 缓冲区剩余的可写空间
    vec[0].iov_base = begin() + writerIndex_; // 缓冲区的数据
    vec[0].iov_len = writable;                // 缓冲区剩余的可写空间

    vec[1].iov_base = extrabuf;        // extrabuf 一次性读取的数据量大于缓冲区的大小
    vec[1].iov_len = sizeof(extrabuf); // 64k  一次性读取的数据量大于缓冲区的大小

    // 从fd上读取数据   readv函数 一次性读取数据到多个缓冲区
    const int iovcnt = (writable < sizeof extrabuf) ? 2 : 1;
    const ssize_t n = ::readv(fd, vec, iovcnt); // 从fd上读取数据
    if (n < 0)
    {
        *saveErrno = errno; // 保存错误信息
    }
    else if (n <= writable)
    {
        // Buffer的数据没有被读取完毕，下一次还会触发可读事件
        writerIndex_ += n; // 更新writerIndex_
    }
    else
    {
        // Buffer的数据被读取完毕，下一次不会触发可读事件
        writerIndex_ = buffer_.size();  // 更新writerIndex_
        append(extrabuf, n - writable); // 将extrabuf的数据追加到Buffer中
    }
    return n;
}

ssize_t Buffer::writeFd(int fd, int *saveErrno)
{
    ssize_t n = ::write(fd, peek(), readableBytes()); // 从Buffer中读取数据
    if (n < 0)
    {
        *saveErrno = errno;
    }
    return n;
}
