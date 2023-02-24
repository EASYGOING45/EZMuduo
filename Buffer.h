#pragma once

/**
 * 网络库底层的缓冲器类型定义
 */

#include <vector>
#include <string>
#include <algorithm>

class Buffer
{
public:
    static const size_t kCheapPrepend = 8;   // 预留空间  8字节   用于预留空间
    static const size_t kInitialSize = 1024; // 初始大小  1024字节

    explicit Buffer(size_t initialSize = kInitialSize)
        : buffer_(kCheapPrepend + initialSize) // 预留空间
          ,
          readerIndex_(kCheapPrepend) // 读取位置
          ,
          writerIndex_(kCheapPrepend) // 写入位置
    {
    }

    // 可读字节数
    size_t readableBytes() const
    {
        return writerIndex_ - readerIndex_; // 写入位置 - 读取位置
    }

    // 可写字节数
    size_t writableBytes() const
    {
        return buffer_.size() - writerIndex_; // 缓冲区大小 - 写入位置
    }

    // 预留空间
    size_t prependdableBytes() const
    {
        return readerIndex_; // 读取位置
    }

    // 返回缓冲区中可读数据的起始地址
    const char *peek() const
    {
        return begin() + readerIndex_;
    }

    // 从缓冲区中读取数据 len:读取数据的长度 返回值：读取到的数据
    void retrieve(size_t len)
    {
        if (len < readableBytes())
        {
            // 应用只读取了刻度缓冲区数据的一部分，就是len，还剩下readerIndex_ += len -> writerIndex_
            readerIndex_ += len; // 读取位置 + len
        }
        else
        {
            retrieveAll(); // 读取所有数据
        }
    }

    // 从缓冲区中读取数据 len:读取数据的长度 返回值：读取到的数据
    void retrieveAll()
    {
        readerIndex_ = writerIndex_ = kCheapPrepend; // 读取位置 = 写入位置 = 预留空间
    }

    // 从缓冲区中读取数据 len:读取数据的长度 返回值：读取到的数据
    std::string retrieveAllAsString()
    {
        return retrieveAsString(readableBytes()); // 读取所有数据
    }

    // 从缓冲区中读取数据 len:读取数据的长度 返回值：读取到的数据
    std::string retrieveAsString(size_t len)
    {
        std::string result(peek(), len); // 读取数据
        retrieve(len);                   // 读取位置 + len
        return result;
    }

    // 从缓冲区中读取数据 len:读取数据的长度 返回值：读取到的数据
    void ensureWriteableBytes(size_t len)
    {
        // 如果缓冲区可写字节数小于len
        if (writableBytes() < len)
        {
            makeSpace(len); // 保证缓冲区有足够的空间 扩容函数
        }
    }
    // 返回缓冲区中可写数据的起始地址
    void append(const char *data, size_t len)
    {
        ensureWriteableBytes(len);                 // 保证缓冲区有足够的空间
        std::copy(data, data + len, beginWrite()); // 拷贝数据 从data开始拷贝len个字节到beginWrite()开始的位置
        writerIndex_ += len;                       // 写入位置 + len
    }

    // 返回缓冲区中可写数据的起始地址
    char *beginWrite()
    {
        return begin() + writerIndex_; // 返回缓冲区中可写数据的起始地址
    }

    // 返回缓冲区中可写数据的起始地址 const版本
    const char *beginWrite() const
    {
        return begin() + writerIndex_; // 返回缓冲区中可写数据的起始地址
    }

    // 从fd上读取数据    fd:文件描述符   saveErrno:保存错误码
    ssize_t readFd(int fd, int *saveErrno); // ssize_t是有符号的整型，用来表示文件大小

    // 通过fd发送数据
    ssize_t writeFd(int fd, int *saveErrno);

private:
    char *begin()
    {
        // 返回缓冲区的首地址
        return &*buffer_.begin(); // vector 容器的首地址
    }

    const char *begin() const // 重载const版本
    {
        return &*buffer_.begin(); // vector 容器的首地址
    }

    // 保证缓冲区有足够的空间
    void makeSpace(size_t len)
    {
        if (writableBytes() + prependdableBytes() < len + kCheapPrepend)
        {
            buffer_.resize(writerIndex_ + len); // 扩容 writerIndex_ + len
        }
        else
        {
            size_t readable = readableBytes(); // 可读字节数
            std::copy(begin() + readerIndex_,
                      begin() + writerIndex_,
                      begin() + kCheapPrepend);
            readerIndex_ = kCheapPrepend;
            writerIndex_ = readerIndex_ + readable; //
        }
    }

    std::vector<char> buffer_; // 缓冲区 vector 容器
    size_t readerIndex_;       // 读取位置
    size_t writerIndex_;       // 写入位置
};