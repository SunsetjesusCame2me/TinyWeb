#include "websvr.h"
#include "log.h"

int main() {
    WebSvr web(1316, 3, 60000, false,             /* 端口 ET模式 timeoutMs 优雅退出  */
               3306, "root", "root", "webserver", /* Mysql配置 */
               12, 6, true, 1, 1024);
    web.Start();

    return 0;
}