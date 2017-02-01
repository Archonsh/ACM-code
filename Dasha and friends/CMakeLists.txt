cmake_minimum_required(VERSION 3.5)
project(Dasha_and_friends)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Dasha_and_friends ${SOURCE_FILES})