cmake_minimum_required(VERSION 3.2)

project(cadex-task)

add_executable(curves src/main.cpp)

if(MSVC)
    target_compile_options(curves PRIVATE /W4)
else()
    target_compile_options(curves PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()

target_compile_features(curves PRIVATE cxx_std_20)