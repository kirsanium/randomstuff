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
CMAKE_SOURCE_DIR = /home/kirsanium/CLionProjects/opp_lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opp_lab4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opp_lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opp_lab4.dir/flags.make

CMakeFiles/opp_lab4.dir/main.c.o: CMakeFiles/opp_lab4.dir/flags.make
CMakeFiles/opp_lab4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/opp_lab4.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/opp_lab4.dir/main.c.o   -c /home/kirsanium/CLionProjects/opp_lab4/main.c

CMakeFiles/opp_lab4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/opp_lab4.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kirsanium/CLionProjects/opp_lab4/main.c > CMakeFiles/opp_lab4.dir/main.c.i

CMakeFiles/opp_lab4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/opp_lab4.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kirsanium/CLionProjects/opp_lab4/main.c -o CMakeFiles/opp_lab4.dir/main.c.s

CMakeFiles/opp_lab4.dir/main.c.o.requires:

.PHONY : CMakeFiles/opp_lab4.dir/main.c.o.requires

CMakeFiles/opp_lab4.dir/main.c.o.provides: CMakeFiles/opp_lab4.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/opp_lab4.dir/build.make CMakeFiles/opp_lab4.dir/main.c.o.provides.build
.PHONY : CMakeFiles/opp_lab4.dir/main.c.o.provides

CMakeFiles/opp_lab4.dir/main.c.o.provides.build: CMakeFiles/opp_lab4.dir/main.c.o


# Object files for target opp_lab4
opp_lab4_OBJECTS = \
"CMakeFiles/opp_lab4.dir/main.c.o"

# External object files for target opp_lab4
opp_lab4_EXTERNAL_OBJECTS =

opp_lab4: CMakeFiles/opp_lab4.dir/main.c.o
opp_lab4: CMakeFiles/opp_lab4.dir/build.make
opp_lab4: CMakeFiles/opp_lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable opp_lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opp_lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opp_lab4.dir/build: opp_lab4

.PHONY : CMakeFiles/opp_lab4.dir/build

CMakeFiles/opp_lab4.dir/requires: CMakeFiles/opp_lab4.dir/main.c.o.requires

.PHONY : CMakeFiles/opp_lab4.dir/requires

CMakeFiles/opp_lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opp_lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opp_lab4.dir/clean

CMakeFiles/opp_lab4.dir/depend:
	cd /home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kirsanium/CLionProjects/opp_lab4 /home/kirsanium/CLionProjects/opp_lab4 /home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug /home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug /home/kirsanium/CLionProjects/opp_lab4/cmake-build-debug/CMakeFiles/opp_lab4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opp_lab4.dir/depend

