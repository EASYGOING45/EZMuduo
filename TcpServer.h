// TcpServer.h TcpServer类 用于创建服务器 用于监听客户端连接 用于接受客户端连接 用于创建线程池 用于创建线程池中的线程 用于创建TcpConnection类 用于创建TcpConnection类中的线程 用于创建TcpConnection类中的线程中的线程池 用于创建TcpConnection类中的线程中的线程池中的线程
//  Path: TcpServer.h
#pragma once

/**
 * TcpServer类
 * 用于创建服务器
 * 用于监听客户端连接
 * 用于接受客户端连接
 * 用户使用muduo编写服务器程序时，只需要创建一个TcpServer对象，然后调用start()方法即可
 */
#include "EventLoop.h"
#include "Acceptor.h"
#include "InetAddress.h"
#include "noncopyable.h"
