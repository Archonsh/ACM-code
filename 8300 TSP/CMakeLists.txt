cmake_minimum_required(VERSION 3.5)
project(8300_TSP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(8300_TSP ${SOURCE_FILES})