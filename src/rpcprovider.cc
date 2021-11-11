#include "rpcprovider.h"
#include "mprpcapplication.h"

#include <string>
#include <functional>

// 框架提供给外部使用的，可以发布rpc方法的接口函数接口
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
}

// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);

    // 创建TcpServer对象
    muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");
    // 绑定连接回调和消息读写回调方法，分离了网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this,
                                        std::placeholders::_1,
                                        std::placeholders::_2,
                                        std::placeholders::_3));

    // 设置muduo库的线程数量
    server.setThreadNum(4);

    std::cout<<"RpcProvider start service at ip:"<<ip<<" port:"<<port<<std::endl; 

    // 启动网络服务
    server.start();
    m_eventLoop.loop();
}

// 新的socket连接回调
void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr &conn)
{
}

// 已建立连接用户的读写事件
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp)
{
} 