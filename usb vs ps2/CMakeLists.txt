cmake_minimum_required(VERSION 3.5)
project(usb_vs_ps2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(usb_vs_ps2 ${SOURCE_FILES})