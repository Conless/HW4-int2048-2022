# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build

# Include any dependencies generated for this target.
include src/CMakeFiles/BigInteger_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/BigInteger_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/BigInteger_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/BigInteger_lib.dir/flags.make

src/CMakeFiles/BigInteger_lib.dir/int2048.cc.o: src/CMakeFiles/BigInteger_lib.dir/flags.make
src/CMakeFiles/BigInteger_lib.dir/int2048.cc.o: ../src/int2048.cc
src/CMakeFiles/BigInteger_lib.dir/int2048.cc.o: src/CMakeFiles/BigInteger_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/BigInteger_lib.dir/int2048.cc.o"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/BigInteger_lib.dir/int2048.cc.o -MF CMakeFiles/BigInteger_lib.dir/int2048.cc.o.d -o CMakeFiles/BigInteger_lib.dir/int2048.cc.o -c /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src/int2048.cc

src/CMakeFiles/BigInteger_lib.dir/int2048.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInteger_lib.dir/int2048.cc.i"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src/int2048.cc > CMakeFiles/BigInteger_lib.dir/int2048.cc.i

src/CMakeFiles/BigInteger_lib.dir/int2048.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInteger_lib.dir/int2048.cc.s"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src/int2048.cc -o CMakeFiles/BigInteger_lib.dir/int2048.cc.s

src/CMakeFiles/BigInteger_lib.dir/main.cpp.o: src/CMakeFiles/BigInteger_lib.dir/flags.make
src/CMakeFiles/BigInteger_lib.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/BigInteger_lib.dir/main.cpp.o: src/CMakeFiles/BigInteger_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/BigInteger_lib.dir/main.cpp.o"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/BigInteger_lib.dir/main.cpp.o -MF CMakeFiles/BigInteger_lib.dir/main.cpp.o.d -o CMakeFiles/BigInteger_lib.dir/main.cpp.o -c /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src/main.cpp

src/CMakeFiles/BigInteger_lib.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigInteger_lib.dir/main.cpp.i"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src/main.cpp > CMakeFiles/BigInteger_lib.dir/main.cpp.i

src/CMakeFiles/BigInteger_lib.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigInteger_lib.dir/main.cpp.s"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src/main.cpp -o CMakeFiles/BigInteger_lib.dir/main.cpp.s

# Object files for target BigInteger_lib
BigInteger_lib_OBJECTS = \
"CMakeFiles/BigInteger_lib.dir/int2048.cc.o" \
"CMakeFiles/BigInteger_lib.dir/main.cpp.o"

# External object files for target BigInteger_lib
BigInteger_lib_EXTERNAL_OBJECTS =

../lib/libBigInteger_lib.a: src/CMakeFiles/BigInteger_lib.dir/int2048.cc.o
../lib/libBigInteger_lib.a: src/CMakeFiles/BigInteger_lib.dir/main.cpp.o
../lib/libBigInteger_lib.a: src/CMakeFiles/BigInteger_lib.dir/build.make
../lib/libBigInteger_lib.a: src/CMakeFiles/BigInteger_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../lib/libBigInteger_lib.a"
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BigInteger_lib.dir/cmake_clean_target.cmake
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigInteger_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/BigInteger_lib.dir/build: ../lib/libBigInteger_lib.a
.PHONY : src/CMakeFiles/BigInteger_lib.dir/build

src/CMakeFiles/BigInteger_lib.dir/clean:
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BigInteger_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/BigInteger_lib.dir/clean

src/CMakeFiles/BigInteger_lib.dir/depend:
	cd /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022 /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/src /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src /mnt/d/OneDrive/cs/course/22fall/sjtu/cs1953/project/HW4-int2048-2022/build/src/CMakeFiles/BigInteger_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/BigInteger_lib.dir/depend

