#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include <fcntl.h>       // fcntl()
#include <unistd.h>      // close()
#include <assert.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory>

class WebSvr
{
public:
    // @brief: 构造一个svr对象
    explicit WebSvr(int port, int trigMode, int timeoutMS, bool OptLinger,
            int sqlPort, const char* sqlUser, const  char* sqlPwd,
            const char* dbName, int connPoolNum, int threadNum,
            bool openLog, int logLevel, int logQueSize);

    // @brief: destroy
    virtual ~WebSvr();

    void Start();

private:
    // @brief: 构造对象
    int Init(int port, int trigMode, int timeoutMS, bool OptLinger,
             int sqlPort, const char* sqlUser, const  char* sqlPwd,
             const char* dbName, int connPoolNum, int threadNum,
             bool openLog, int logLevel, int logQueSize);

private:
    int port_;              // 数据库监听端口
    bool openLinger_;       // ?
    int timeoutMS_;         // 毫秒ms
    bool isClose_;          // 关闭?tag
    int listenFd_;          // 监听fd
    std::string srcDir_;    // 工作路径?

    uint32_t listenEvent_;  // ?
    uint32_t connEvent_;

//    std::unique_ptr<HeapTimer> timer_;
//    std::unique_ptr<ThreadPool> threadpool_;
//    std::unique_ptr<Epoller> epoller_;
//    std::unordered_map<int, HttpConn> users_;
};