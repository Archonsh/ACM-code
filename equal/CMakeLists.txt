cmake_minimum_required(VERSION 3.5)
project(equal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(equal ${SOURCE_FILES})
add_executable(scratch /Users/Archon/Library/Preferences/CLion2016.1/scratches/scratch.cpp)