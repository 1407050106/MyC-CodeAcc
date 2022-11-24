cmake_minimum_required(VERSION 3.5) # 指定运行此配置文件所需的 CMake 的最低版本

set(execMainName TOY)
project(${execMainName}) #表示项目的名称

set(CMAKE_CXX_STANDARD 11)

set(TOOLCHAIN_DIR /home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux)
set(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++)
#指定交叉编译环境安装目录:
set(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
        ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/include
        ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/lib
)

file(GLOB_RECURSE CDR_FILE *.cpp)
file(GLOB_RECURSE HDR_FILE *.h)
file(GLOB_RECURSE HDR_FILES *.hpp)

#file(GLOB_RECURSE TOY_FILES test.cpp)

include_directories(
	${PROJECT_SOURCE_DIR}
        )

link_directories(
             
        )

add_library(test SHARED ${HDR_FILE} ${HDR_FILES} ${CDR_FILE})
