cmake_minimum_required(VERSION 3.15)
project(snake)

set(CMAKE_CXX_STANDARD 14)
##set (CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(snake main.cpp Segment.cpp Segment.h Snake.cpp Snake.h Game.cpp Game.h Thread_for_MINGW/mingw.thread.h)

add_subdirectory(Google_tests)