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
CMAKE_SOURCE_DIR = /home/kirsanium/CLionProjects/Task1_psv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/glm_dummy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glm_dummy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glm_dummy.dir/flags.make

CMakeFiles/glm_dummy.dir/main.cpp.o: CMakeFiles/glm_dummy.dir/flags.make
CMakeFiles/glm_dummy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/glm_dummy.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/main.cpp.o -c /home/kirsanium/CLionProjects/Task1_psv/main.cpp

CMakeFiles/glm_dummy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirsanium/CLionProjects/Task1_psv/main.cpp > CMakeFiles/glm_dummy.dir/main.cpp.i

CMakeFiles/glm_dummy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirsanium/CLionProjects/Task1_psv/main.cpp -o CMakeFiles/glm_dummy.dir/main.cpp.s

CMakeFiles/glm_dummy.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/glm_dummy.dir/main.cpp.o.requires

CMakeFiles/glm_dummy.dir/main.cpp.o.provides: CMakeFiles/glm_dummy.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/glm_dummy.dir/build.make CMakeFiles/glm_dummy.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/glm_dummy.dir/main.cpp.o.provides

CMakeFiles/glm_dummy.dir/main.cpp.o.provides.build: CMakeFiles/glm_dummy.dir/main.cpp.o


CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o: CMakeFiles/glm_dummy.dir/flags.make
CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o: ../glm/detail/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o -c /home/kirsanium/CLionProjects/Task1_psv/glm/detail/dummy.cpp

CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirsanium/CLionProjects/Task1_psv/glm/detail/dummy.cpp > CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.i

CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirsanium/CLionProjects/Task1_psv/glm/detail/dummy.cpp -o CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.s

CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.requires:

.PHONY : CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.requires

CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.provides: CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.requires
	$(MAKE) -f CMakeFiles/glm_dummy.dir/build.make CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.provides.build
.PHONY : CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.provides

CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.provides.build: CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o


CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o: CMakeFiles/glm_dummy.dir/flags.make
CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o: ../glm/detail/glm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o -c /home/kirsanium/CLionProjects/Task1_psv/glm/detail/glm.cpp

CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirsanium/CLionProjects/Task1_psv/glm/detail/glm.cpp > CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.i

CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirsanium/CLionProjects/Task1_psv/glm/detail/glm.cpp -o CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.s

CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.requires:

.PHONY : CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.requires

CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.provides: CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.requires
	$(MAKE) -f CMakeFiles/glm_dummy.dir/build.make CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.provides.build
.PHONY : CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.provides

CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.provides.build: CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o


# Object files for target glm_dummy
glm_dummy_OBJECTS = \
"CMakeFiles/glm_dummy.dir/main.cpp.o" \
"CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o" \
"CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o"

# External object files for target glm_dummy
glm_dummy_EXTERNAL_OBJECTS =

glm_dummy: CMakeFiles/glm_dummy.dir/main.cpp.o
glm_dummy: CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o
glm_dummy: CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o
glm_dummy: CMakeFiles/glm_dummy.dir/build.make
glm_dummy: CMakeFiles/glm_dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable glm_dummy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glm_dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glm_dummy.dir/build: glm_dummy

.PHONY : CMakeFiles/glm_dummy.dir/build

CMakeFiles/glm_dummy.dir/requires: CMakeFiles/glm_dummy.dir/main.cpp.o.requires
CMakeFiles/glm_dummy.dir/requires: CMakeFiles/glm_dummy.dir/glm/detail/dummy.cpp.o.requires
CMakeFiles/glm_dummy.dir/requires: CMakeFiles/glm_dummy.dir/glm/detail/glm.cpp.o.requires

.PHONY : CMakeFiles/glm_dummy.dir/requires

CMakeFiles/glm_dummy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glm_dummy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glm_dummy.dir/clean

CMakeFiles/glm_dummy.dir/depend:
	cd /home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kirsanium/CLionProjects/Task1_psv /home/kirsanium/CLionProjects/Task1_psv /home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug /home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug /home/kirsanium/CLionProjects/Task1_psv/cmake-build-debug/CMakeFiles/glm_dummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glm_dummy.dir/depend

