#include "InetAddress.h"
#include <strings.h>
#include <string.h>

InetAddress::InetAddress(uint16_t port, std::string ip)
{
    bzero(&addr_, sizeof addr_); // 置零
    addr_.sin_family = AF_INET;  // TCP/IP – IPv4
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str()); // 将 const string* 类型 转化为 const char*
}

std::string InetAddress::toIp() const
{
    // addr_
    char buf[64] = {0};
    // inet_ntop将IPv4或IPv6 Internet网络地址转换为 Internet标准格式的字符串
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    return buf;
}

std::string InetAddress::toIpPort() const
{
    // ip::port
    char buf[64] = {0};
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    size_t end = strlen(buf);
    uint16_t port = ntohs(addr_.sin_port); // 将一个16位数由网络字节顺序转换为主机字节顺序。
    sprintf(buf + end, ":%u", port);
    return buf;
}

uint16_t InetAddress::toPort() const
{
    return ntohs(addr_.sin_port);
}