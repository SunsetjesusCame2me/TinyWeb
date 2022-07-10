#include "websvr.h"
#include "log.h"

int main() {
    WebSvr web;
    web.testPrint();

    log lg;
    lg.log_info("Dmm's demo");

    return 0;
}