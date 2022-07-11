#include "websvr.h"

WebSvr::WebSvr(int port, int trigMode, int timeoutMS, bool OptLinger, int sqlPort, const char *sqlUser,
               const char *sqlPwd, const char *dbName, int connPoolNum, int threadNum, bool openLog, int logLevel,
               int logQueSize) {
    int ret = Init(port, trigMode, timeoutMS,
                   OptLinger, sqlPort, sqlUser,
                   sqlPwd, dbName, connPoolNum,
                   threadNum, openLog, logLevel, logQueSize);
    if (ret) {
        std::cout << "[ERROR]Init error" << std::endl;
    }
}

int WebSvr::Init(int port, int trigMode, int timeoutMS, bool OptLinger,
                 int sqlPort, const char* sqlUser, const  char* sqlPwd,
                 const char* dbName, int connPoolNum, int threadNum,
                 bool openLog, int logLevel, int logQueSize) {
    srcDir_ = getcwd(nullptr, 256);     // 获得绝对路径
    if (!srcDir_.c_str()) {
        return -1;
    }
    srcDir_ += "/resources/";

    return 0;
}

WebSvr::~WebSvr() {}

void
WebSvr::Start() {
    std::cout << "[Path]: "<< srcDir_ << std::endl;
}