cmake_minimum_required(VERSION 3.6)
project(_UndoRedo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Command.h Commander.cpp Commander.h InputCommand.h InputCommand.cpp)
add_executable(_UndoRedo ${SOURCE_FILES})