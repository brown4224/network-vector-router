cmake_minimum_required(VERSION 3.6)
project(RouterProgram)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node0.cpp)
add_executable(RouterProgram ${SOURCE_FILES})