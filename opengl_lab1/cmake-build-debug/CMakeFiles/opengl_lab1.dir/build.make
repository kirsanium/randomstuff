# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/kirsanium/Downloads/clion-2018.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/kirsanium/Downloads/clion-2018.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kirsanium/CLionProjects/opengl_lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opengl_lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl_lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl_lab1.dir/flags.make

CMakeFiles/opengl_lab1.dir/main.cpp.o: CMakeFiles/opengl_lab1.dir/flags.make
CMakeFiles/opengl_lab1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl_lab1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_lab1.dir/main.cpp.o -c /home/kirsanium/CLionProjects/opengl_lab1/main.cpp

CMakeFiles/opengl_lab1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_lab1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirsanium/CLionProjects/opengl_lab1/main.cpp > CMakeFiles/opengl_lab1.dir/main.cpp.i

CMakeFiles/opengl_lab1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_lab1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirsanium/CLionProjects/opengl_lab1/main.cpp -o CMakeFiles/opengl_lab1.dir/main.cpp.s

CMakeFiles/opengl_lab1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/opengl_lab1.dir/main.cpp.o.requires

CMakeFiles/opengl_lab1.dir/main.cpp.o.provides: CMakeFiles/opengl_lab1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/opengl_lab1.dir/build.make CMakeFiles/opengl_lab1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/opengl_lab1.dir/main.cpp.o.provides

CMakeFiles/opengl_lab1.dir/main.cpp.o.provides.build: CMakeFiles/opengl_lab1.dir/main.cpp.o


# Object files for target opengl_lab1
opengl_lab1_OBJECTS = \
"CMakeFiles/opengl_lab1.dir/main.cpp.o"

# External object files for target opengl_lab1
opengl_lab1_EXTERNAL_OBJECTS =

opengl_lab1: CMakeFiles/opengl_lab1.dir/main.cpp.o
opengl_lab1: CMakeFiles/opengl_lab1.dir/build.make
opengl_lab1: CMakeFiles/opengl_lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opengl_lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl_lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl_lab1.dir/build: opengl_lab1

.PHONY : CMakeFiles/opengl_lab1.dir/build

CMakeFiles/opengl_lab1.dir/requires: CMakeFiles/opengl_lab1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/opengl_lab1.dir/requires

CMakeFiles/opengl_lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl_lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl_lab1.dir/clean

CMakeFiles/opengl_lab1.dir/depend:
	cd /home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kirsanium/CLionProjects/opengl_lab1 /home/kirsanium/CLionProjects/opengl_lab1 /home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug /home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug /home/kirsanium/CLionProjects/opengl_lab1/cmake-build-debug/CMakeFiles/opengl_lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl_lab1.dir/depend
