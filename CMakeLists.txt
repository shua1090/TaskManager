cmake_minimum_required(VERSION 3.15)
project(task_manager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(task_manager task_manager/TaskManager.hpp
        task_manager/example.cpp task_manager/Time.hpp)

if (UNIX AND NOT APPLE)
    message("On Linux, linking with pthread")
    target_link_libraries(task_manager pthread)
endif()