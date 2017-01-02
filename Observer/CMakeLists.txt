cmake_minimum_required(VERSION 3.6)
project(Observer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Observer.h Observer.cpp)
add_executable(Observer ${SOURCE_FILES})