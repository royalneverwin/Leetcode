# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangxinhao/CLionProjects/Leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Leetcode4.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Leetcode4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Leetcode4.dir/flags.make

CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.o: CMakeFiles/Leetcode4.dir/flags.make
CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.o: ../寻找两个正序数组的中位数.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.o -c /Users/wangxinhao/CLionProjects/Leetcode/寻找两个正序数组的中位数.cpp

CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangxinhao/CLionProjects/Leetcode/寻找两个正序数组的中位数.cpp > CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.i

CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangxinhao/CLionProjects/Leetcode/寻找两个正序数组的中位数.cpp -o CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.s

# Object files for target Leetcode4
Leetcode4_OBJECTS = \
"CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.o"

# External object files for target Leetcode4
Leetcode4_EXTERNAL_OBJECTS =

Leetcode4: CMakeFiles/Leetcode4.dir/寻找两个正序数组的中位数.cpp.o
Leetcode4: CMakeFiles/Leetcode4.dir/build.make
Leetcode4: CMakeFiles/Leetcode4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Leetcode4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Leetcode4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Leetcode4.dir/build: Leetcode4
.PHONY : CMakeFiles/Leetcode4.dir/build

CMakeFiles/Leetcode4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Leetcode4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Leetcode4.dir/clean

CMakeFiles/Leetcode4.dir/depend:
	cd /Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangxinhao/CLionProjects/Leetcode /Users/wangxinhao/CLionProjects/Leetcode /Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug /Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug /Users/wangxinhao/CLionProjects/Leetcode/cmake-build-debug/CMakeFiles/Leetcode4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Leetcode4.dir/depend

