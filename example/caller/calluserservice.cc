#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"

#include <iostream>

int main(int argc, char **argv)
{
    // 想要使用mprpc框架的服务，一定要先调用框架的初始化函数（只初始化一次）
    MprpcApplication::Init(argc, argv);

    // 演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    // rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    // rpc方法的响应
    fixbug::LoginResponse response;
    // 发起rpc方法的调用，同步的rpc调用过程  MprpcChannel::callmethod
    stub.Login(nullptr, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网路发送

    // 一次rpc调用完成，读调用的结果
    if (0 == response.result().errcode())
    {
        std::cout << "rpc login response:" << response.sucess() << std::endl;
    }
    else
    {
        std::cout<<"rpc login response error: "<<response.result().errmsg()<<std::endl;
    }
    return 0;
}