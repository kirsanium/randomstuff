# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm

# Include any dependencies generated for this target.
include CMakeFiles/glm_dummy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glm_dummy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glm_dummy.dir/flags.make

CMakeFiles/glm_dummy.dir/detail/glm.o: CMakeFiles/glm_dummy.dir/flags.make
CMakeFiles/glm_dummy.dir/detail/glm.o: detail/glm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/glm_dummy.dir/detail/glm.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/detail/glm.o -c /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/detail/glm.cpp

CMakeFiles/glm_dummy.dir/detail/glm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/detail/glm.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/detail/glm.cpp > CMakeFiles/glm_dummy.dir/detail/glm.i

CMakeFiles/glm_dummy.dir/detail/glm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/detail/glm.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/detail/glm.cpp -o CMakeFiles/glm_dummy.dir/detail/glm.s

CMakeFiles/glm_dummy.dir/detail/glm.o.requires:

.PHONY : CMakeFiles/glm_dummy.dir/detail/glm.o.requires

CMakeFiles/glm_dummy.dir/detail/glm.o.provides: CMakeFiles/glm_dummy.dir/detail/glm.o.requires
	$(MAKE) -f CMakeFiles/glm_dummy.dir/build.make CMakeFiles/glm_dummy.dir/detail/glm.o.provides.build
.PHONY : CMakeFiles/glm_dummy.dir/detail/glm.o.provides

CMakeFiles/glm_dummy.dir/detail/glm.o.provides.build: CMakeFiles/glm_dummy.dir/detail/glm.o


CMakeFiles/glm_dummy.dir/detail/dummy.o: CMakeFiles/glm_dummy.dir/flags.make
CMakeFiles/glm_dummy.dir/detail/dummy.o: detail/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/glm_dummy.dir/detail/dummy.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/glm_dummy.dir/detail/dummy.o -c /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/detail/dummy.cpp

CMakeFiles/glm_dummy.dir/detail/dummy.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glm_dummy.dir/detail/dummy.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/detail/dummy.cpp > CMakeFiles/glm_dummy.dir/detail/dummy.i

CMakeFiles/glm_dummy.dir/detail/dummy.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glm_dummy.dir/detail/dummy.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/detail/dummy.cpp -o CMakeFiles/glm_dummy.dir/detail/dummy.s

CMakeFiles/glm_dummy.dir/detail/dummy.o.requires:

.PHONY : CMakeFiles/glm_dummy.dir/detail/dummy.o.requires

CMakeFiles/glm_dummy.dir/detail/dummy.o.provides: CMakeFiles/glm_dummy.dir/detail/dummy.o.requires
	$(MAKE) -f CMakeFiles/glm_dummy.dir/build.make CMakeFiles/glm_dummy.dir/detail/dummy.o.provides.build
.PHONY : CMakeFiles/glm_dummy.dir/detail/dummy.o.provides

CMakeFiles/glm_dummy.dir/detail/dummy.o.provides.build: CMakeFiles/glm_dummy.dir/detail/dummy.o


# Object files for target glm_dummy
glm_dummy_OBJECTS = \
"CMakeFiles/glm_dummy.dir/detail/glm.o" \
"CMakeFiles/glm_dummy.dir/detail/dummy.o"

# External object files for target glm_dummy
glm_dummy_EXTERNAL_OBJECTS =

glm_dummy: CMakeFiles/glm_dummy.dir/detail/glm.o
glm_dummy: CMakeFiles/glm_dummy.dir/detail/dummy.o
glm_dummy: CMakeFiles/glm_dummy.dir/build.make
glm_dummy: CMakeFiles/glm_dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable glm_dummy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glm_dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glm_dummy.dir/build: glm_dummy

.PHONY : CMakeFiles/glm_dummy.dir/build

CMakeFiles/glm_dummy.dir/requires: CMakeFiles/glm_dummy.dir/detail/glm.o.requires
CMakeFiles/glm_dummy.dir/requires: CMakeFiles/glm_dummy.dir/detail/dummy.o.requires

.PHONY : CMakeFiles/glm_dummy.dir/requires

CMakeFiles/glm_dummy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glm_dummy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glm_dummy.dir/clean

CMakeFiles/glm_dummy.dir/depend:
	cd /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm /home/kirsanium/Downloads/Task01/Task1_GL20/include/glm/CMakeFiles/glm_dummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glm_dummy.dir/depend

