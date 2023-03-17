// Callbacks.h
#include <memory>
#include <functional>

// 类的前向声明
class Buffer;
class TcpConnection;
class Timestamp;

using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using ConnectionCallback = std::function<void(const TcpConnectionPtr &)>;
using CloseCallback = std::function<void(const TcpConnectionPtr &)>; // 1
using WriteCompleteCallback = std::function < void(const TcpConnectionPtr)