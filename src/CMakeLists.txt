#aux_source_directory(. SRC_LIST)
set(SRC_LIST 
    rpcapplication.cc 
    rpcconfig.cc 
    rpcheader.pb.cc 
    rpcprovider.cc 
    rpcchannel.cc
    rpccontroller.cc
    logger.cc
    zookeeperutil.cc)
add_library(rpc ${SRC_LIST})
target_link_libraries(rpc netlibrary pthread zookeeper_mt)