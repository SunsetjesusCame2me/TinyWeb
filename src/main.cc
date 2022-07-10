#include "websvr.h"
#include "log.h"

int main() {
    WebSvr web;
    web.testPrint();

    // test log
    log lg;
    lg.log_info("Dmm's demo");

    return 0;
}