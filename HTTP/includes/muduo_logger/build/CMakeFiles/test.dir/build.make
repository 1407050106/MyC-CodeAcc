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
CMAKE_SOURCE_DIR = /home/wangyonglin/VScode/HTTP/includes/muduo_logger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/LogStream.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/LogStream.cpp.o: ../LogStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/LogStream.cpp.o"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/LogStream.cpp.o -c /home/wangyonglin/VScode/HTTP/includes/muduo_logger/LogStream.cpp

CMakeFiles/test.dir/LogStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/LogStream.cpp.i"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangyonglin/VScode/HTTP/includes/muduo_logger/LogStream.cpp > CMakeFiles/test.dir/LogStream.cpp.i

CMakeFiles/test.dir/LogStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/LogStream.cpp.s"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangyonglin/VScode/HTTP/includes/muduo_logger/LogStream.cpp -o CMakeFiles/test.dir/LogStream.cpp.s

CMakeFiles/test.dir/Logger.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Logger.cpp.o: ../Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/Logger.cpp.o"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Logger.cpp.o -c /home/wangyonglin/VScode/HTTP/includes/muduo_logger/Logger.cpp

CMakeFiles/test.dir/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Logger.cpp.i"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangyonglin/VScode/HTTP/includes/muduo_logger/Logger.cpp > CMakeFiles/test.dir/Logger.cpp.i

CMakeFiles/test.dir/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Logger.cpp.s"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangyonglin/VScode/HTTP/includes/muduo_logger/Logger.cpp -o CMakeFiles/test.dir/Logger.cpp.s

CMakeFiles/test.dir/TimeStamp.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/TimeStamp.cpp.o: ../TimeStamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/TimeStamp.cpp.o"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/TimeStamp.cpp.o -c /home/wangyonglin/VScode/HTTP/includes/muduo_logger/TimeStamp.cpp

CMakeFiles/test.dir/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/TimeStamp.cpp.i"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangyonglin/VScode/HTTP/includes/muduo_logger/TimeStamp.cpp > CMakeFiles/test.dir/TimeStamp.cpp.i

CMakeFiles/test.dir/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/TimeStamp.cpp.s"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangyonglin/VScode/HTTP/includes/muduo_logger/TimeStamp.cpp -o CMakeFiles/test.dir/TimeStamp.cpp.s

CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.o"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.o -c /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp

CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.i"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp > CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.i

CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.s"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp -o CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.s

CMakeFiles/test.dir/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/test.cpp.o"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cpp.o -c /home/wangyonglin/VScode/HTTP/includes/muduo_logger/test.cpp

CMakeFiles/test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangyonglin/VScode/HTTP/includes/muduo_logger/test.cpp > CMakeFiles/test.dir/test.cpp.i

CMakeFiles/test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	/home/wangyonglin/VScode/HTTP/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangyonglin/VScode/HTTP/includes/muduo_logger/test.cpp -o CMakeFiles/test.dir/test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/LogStream.cpp.o" \
"CMakeFiles/test.dir/Logger.cpp.o" \
"CMakeFiles/test.dir/TimeStamp.cpp.o" \
"CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.o" \
"CMakeFiles/test.dir/test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

libtest.so: CMakeFiles/test.dir/LogStream.cpp.o
libtest.so: CMakeFiles/test.dir/Logger.cpp.o
libtest.so: CMakeFiles/test.dir/TimeStamp.cpp.o
libtest.so: CMakeFiles/test.dir/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp.o
libtest.so: CMakeFiles/test.dir/test.cpp.o
libtest.so: CMakeFiles/test.dir/build.make
libtest.so: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libtest.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: libtest.so

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wangyonglin/VScode/HTTP/includes/muduo_logger /home/wangyonglin/VScode/HTTP/includes/muduo_logger /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build /home/wangyonglin/VScode/HTTP/includes/muduo_logger/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

