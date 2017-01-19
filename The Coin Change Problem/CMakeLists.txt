cmake_minimum_required(VERSION 3.5)
project(The_Coin_Change_Problem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(The_Coin_Change_Problem ${SOURCE_FILES})