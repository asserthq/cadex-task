cmake_minimum_required(VERSION 3.2)

project(cadex-task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(curves)
add_subdirectory(sandbox)
add_subdirectory(test)