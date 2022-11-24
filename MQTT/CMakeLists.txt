cmake_minimum_required(VERSION 3.5) # 指定运行此配置文件所需的 CMake 的最低版本

set(execDataCollectName FANUC_DAQ)
project(${execDataCollectName}) #表示项目的名称

set(CMAKE_CXX_STANDARD 11)

set(TOOLCHAIN_DIR ${PROJECT_SOURCE_DIR}/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux)
set(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++)
#指定交叉编译环境安装目录:
set(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
        ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/include
        ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/lib
)

#从来不在指定目录下查找工具程序
# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#只在指定目录下查找库文件
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARYONLY)
#只在指定目录下查找头文件
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDEONLY)

file(GLOB_RECURSE SRC_FILES my_part_code/*.c)
file(GLOB_RECURSE SRCPLUS_FILES my_part_code/*.cpp)
file(GLOB_RECURSE HDR_FILES my_part_code/*.h)

file(GLOB_RECURSE Linux_TaijiDataCollect_FILES Src/Linux_TaijiDataCollect/*.cpp)

include_directories(
                    ${PROJECT_SOURCE_DIR}/3rd_part_code/mqtt/include
                    ${PROJECT_SOURCE_DIR}/3rd_part_code/log4cpp/include
              
                    ${PROJECT_SOURCE_DIR}/my_part_code/MQTTManager
                    ${PROJECT_SOURCE_DIR}/my_part_code/Log
                    ${PROJECT_SOURCE_DIR}/my_part_code/config
        )

link_directories(
                "3rd_part_code/mqtt/lib"
                "3rd_part_code/log4cpp/lib"
        )


# 指定生成目标
add_executable(${execDataCollectName} ${HDR_FILES} ${SRC_FILES} ${SRCPLUS_FILES} ${Linux_TaijiDataCollect_FILES})
# 添加链接库
target_link_libraries(${execDataCollectName} paho-mqtt3a paho-mqtt3c log4cpp)
