cmake_minimum_required(VERSION 3.5) # 指定运行此配置文件所需的 CMake 的最低版本

set(execMainName MODBUS)
project(${execMainName}) #表示项目的名称

set(CMAKE_CXX_STANDARD 11)

set(TOOLCHAIN_DIR /opt/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux)
set(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++)
#指定交叉编译环境安装目录:
set(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
        ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/include
        ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/lib
)

#file(GLOB_RECURSE SRC_FILES *.c)
#file(GLOB_RECURSE SRCPLUS_FILES includes/muduo_logger/*.cpp)
#file(GLOB_RECURSE HDR_FILE includes/muduo_logger/*.h)
#file(GLOB_RECURSE HDR_FILES includes/muduo_logger/*.hpp)

file(GLOB_RECURSE COMM_FILES tongxun.cpp)

include_directories(
	#${PROJECT_SOURCE_DIR}/includes
        )

link_directories(
        #"includes/muduo_network"
        )

# 指定生成目标
#add_executable(${execMainName} ${HDR_FILE} ${HDR_FILES} ${SRCPLUS_FILES} ${HTTP_FILES})
# 添加链接库
#target_link_libraries(${execMainName} test)

set(execDataCollectName MODBUS_DAQ)
# 指定生成目标
add_executable(${execDataCollectName} ${COMM_FILES})
# 添加链接库
#target_link_libraries(${execDataCollectName} test)
