cmake_minimum_required(VERSION 3.5)
project(round_404b)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(round_404b ${SOURCE_FILES})