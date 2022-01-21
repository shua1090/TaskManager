cmake_minimum_required(VERSION 3.21)
project(task_manager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(task_manager task_manager/TaskManager.hpp task_manager/TaskManager.cpp 
task_manager/main.cpp)