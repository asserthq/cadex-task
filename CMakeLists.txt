cmake_minimum_required(VERSION 3.20)

project(cadex-task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    cmake_policy(SET CMP0135 NEW)
endif()

add_subdirectory(curves)
add_subdirectory(sandbox)
add_subdirectory(test)
