# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wyl/MqttTest/Zibian

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wyl/MqttTest/Zibian/build

# Include any dependencies generated for this target.
include CMakeFiles/FANUC_DAQ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FANUC_DAQ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FANUC_DAQ.dir/flags.make

CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.o: CMakeFiles/FANUC_DAQ.dir/flags.make
CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.o: ../my_part_code/Log/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.o"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.o -c /home/wyl/MqttTest/Zibian/my_part_code/Log/Logger.cpp

CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.i"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyl/MqttTest/Zibian/my_part_code/Log/Logger.cpp > CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.i

CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.s"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyl/MqttTest/Zibian/my_part_code/Log/Logger.cpp -o CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.s

CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.o: CMakeFiles/FANUC_DAQ.dir/flags.make
CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.o: ../my_part_code/MQTTManager/MqttManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.o"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.o -c /home/wyl/MqttTest/Zibian/my_part_code/MQTTManager/MqttManager.cpp

CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.i"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyl/MqttTest/Zibian/my_part_code/MQTTManager/MqttManager.cpp > CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.i

CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.s"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyl/MqttTest/Zibian/my_part_code/MQTTManager/MqttManager.cpp -o CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.s

CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.o: CMakeFiles/FANUC_DAQ.dir/flags.make
CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.o: ../my_part_code/config/BasicInformation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.o"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.o -c /home/wyl/MqttTest/Zibian/my_part_code/config/BasicInformation.cpp

CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.i"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyl/MqttTest/Zibian/my_part_code/config/BasicInformation.cpp > CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.i

CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.s"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyl/MqttTest/Zibian/my_part_code/config/BasicInformation.cpp -o CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.s

CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.o: CMakeFiles/FANUC_DAQ.dir/flags.make
CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.o: ../my_part_code/config/ReadConfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.o"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.o -c /home/wyl/MqttTest/Zibian/my_part_code/config/ReadConfig.cpp

CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.i"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyl/MqttTest/Zibian/my_part_code/config/ReadConfig.cpp > CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.i

CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.s"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyl/MqttTest/Zibian/my_part_code/config/ReadConfig.cpp -o CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.s

CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.o: CMakeFiles/FANUC_DAQ.dir/flags.make
CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.o: ../Src/Linux_TaijiDataCollect/DataSend.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.o"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.o -c /home/wyl/MqttTest/Zibian/Src/Linux_TaijiDataCollect/DataSend.cpp

CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.i"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyl/MqttTest/Zibian/Src/Linux_TaijiDataCollect/DataSend.cpp > CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.i

CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.s"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyl/MqttTest/Zibian/Src/Linux_TaijiDataCollect/DataSend.cpp -o CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.s

CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.o: CMakeFiles/FANUC_DAQ.dir/flags.make
CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.o: ../Src/Linux_TaijiDataCollect/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.o"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.o -c /home/wyl/MqttTest/Zibian/Src/Linux_TaijiDataCollect/main.cpp

CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.i"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wyl/MqttTest/Zibian/Src/Linux_TaijiDataCollect/main.cpp > CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.i

CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.s"
	/home/wyl/MqttTest/Zibian/3rd_part_code/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wyl/MqttTest/Zibian/Src/Linux_TaijiDataCollect/main.cpp -o CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.s

# Object files for target FANUC_DAQ
FANUC_DAQ_OBJECTS = \
"CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.o" \
"CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.o" \
"CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.o" \
"CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.o" \
"CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.o" \
"CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.o"

# External object files for target FANUC_DAQ
FANUC_DAQ_EXTERNAL_OBJECTS =

FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/my_part_code/Log/Logger.cpp.o
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/my_part_code/MQTTManager/MqttManager.cpp.o
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/my_part_code/config/BasicInformation.cpp.o
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/my_part_code/config/ReadConfig.cpp.o
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/DataSend.cpp.o
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/Src/Linux_TaijiDataCollect/main.cpp.o
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/build.make
FANUC_DAQ: CMakeFiles/FANUC_DAQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wyl/MqttTest/Zibian/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable FANUC_DAQ"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FANUC_DAQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FANUC_DAQ.dir/build: FANUC_DAQ

.PHONY : CMakeFiles/FANUC_DAQ.dir/build

CMakeFiles/FANUC_DAQ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FANUC_DAQ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FANUC_DAQ.dir/clean

CMakeFiles/FANUC_DAQ.dir/depend:
	cd /home/wyl/MqttTest/Zibian/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wyl/MqttTest/Zibian /home/wyl/MqttTest/Zibian /home/wyl/MqttTest/Zibian/build /home/wyl/MqttTest/Zibian/build /home/wyl/MqttTest/Zibian/build/CMakeFiles/FANUC_DAQ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FANUC_DAQ.dir/depend

