cmake_minimum_required(VERSION 3.6)
project(composite)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Entry.h File.h Directory.h File.cpp Directory.cpp)
add_executable(composite ${SOURCE_FILES})