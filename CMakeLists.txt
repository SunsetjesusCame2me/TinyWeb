cmake_minimum_required(VERSION 3.21)        # cmake version
project(TinyWeb)                            # 设置project名 与父文件夹同名

# (Hello "Hello" "World")                                       # 也可设置变量：多个值set给一个变量
set(CMAKE_CXX_STANDARD 11)                                      # 设置cpp的版本
set(CMAKE_CXX_STANDARD_REQUIRED True)                           # 此选项为true 则强行指定c++11版本; off 则首选11 无则使用上一ver
set(CMAKE_BUILD_TYPE "Release")                                 # 设置编译模式: Debug/Release
# set(CMAKE_CXX_FLAGS_DEBUG "-o0 -Wall -g -pthread")                # 针对Debug下的编译选项
# 追加: set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pthread")
set(CMAKE_CXX_FLAGS_RELEASE  "-O0 -Wall -g -pthread")               # 针对Release下的编译选项

message("current path: " ${CMAKE_CURRENT_LIST_DIR})                          # 执行到此输出一些信息 可结合变量如 ${CMAKE_CXX_STANDARD}

# 仅需要包含头文件就这么做
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/websvr)          # 把当前cmakelist目录下的include文件加入到包含路径
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/log)

# 需要链接 .a 库文件时
# link_directories(${CMAKE_CURRENT_LIST_DIR}/{库文件path})

# 源文件目录保存到 TinyWeb_src变量
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/websvr TinyWeb_src)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src/log Log_src)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src Main_src)

message("src list: " ${Log_src} ${TinyWeb_src} ${Main_src})

add_executable(${PROJECT_NAME}
        ${Log_src}
        ${TinyWeb_src}
        ${Main_src})

# 去链接静态库 libKu,
#target_link_libraries(${PROJECT_NAME} Ku)