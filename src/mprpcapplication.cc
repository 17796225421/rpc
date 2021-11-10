#include "mprpcapplication.h"

#include <iostream>
#include <unistd.h>
#include <string>

void ShowArgsHelp(){
    std::cout<<"format: command -i <configfile>"<<std::endl;
}

void MprpcApplication::Init(int argc, char **argv)
{
    if (argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

    char c;
    std::string config_file;
    while((c=getopt(argc,argv,"i:"))!=-1){
        if(c=='i'){
            config_file=optarg;
        }else if(c=='?'||c==':'){
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        }
    }

    // 开始加载配置文件 rpcserver_ip=  rpcserver_port=  zookeeper_ip=  zookeeper_port=  
}

MprpcApplication &MprpcApplication::GetInstance()
{
    static MprpcApplication app;
    return app;
}