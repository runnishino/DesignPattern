cmake_minimum_required(VERSION 3.6)
project(UndoRedo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES SimpleUndoRedo/main.cpp SimpleUndoRedo/Command.h SimpleUndoRedo/InputCommand.h SimpleUndoRedo/InputCommand.cpp SimpleUndoRedo/Commander.cpp SimpleUndoRedo/Commander.h BaseCommand.h Factory.h BaseCommandManager.h CommandManager.h Singleton.h Subject.h CommandManager.cpp SimpleUndoRedo/Command.h Command.cpp BaseCommandReceiver.h MacroCommand.h MacroCommand.cpp Util.h)
add_executable(UndoRedo ${SOURCE_FILES})