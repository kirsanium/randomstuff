cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -ISources")
set (CMAKE_CXX_STANDARD_LIBRARIES "-lfreeimage -lGL -lGLU -lGLEW -lglut")

file(GLOB_RECURSE Foo_SOURCES "Sources/*.cpp")
file(GLOB_RECURSE Foo_HEADERS "Sources/*.h")

set (Foo_INCLUDE_DIRS "")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

add_executable (run ${Foo_SOURCES})
target_include_directories(run PRIVATE ${Foo_INCLUDE_DIRS})