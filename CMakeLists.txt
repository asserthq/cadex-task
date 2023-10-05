cmake_minimum_required(VERSION 3.2)

project(cadex-task)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GTest lib

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Project Targets

add_library(curves SHARED src/Circle.cpp src/Circle.h src/Ellipse.h src/Ellipse.cpp src/Helix.h src/Helix.cpp src/ICurve.h src/Vec3.h)
add_executable(sandbox src/main.cpp)
target_link_libraries(sandbox curves)

if(MSVC)
    target_compile_options(curves PRIVATE /W4)
else()
    target_compile_options(curves PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()

# Testing

enable_testing()
add_executable(curves_test test/curves_test.cpp)
target_include_directories(curves_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(curves_test GTest::gtest_main GTest::gmock_main curves)
include(GoogleTest)
gtest_discover_tests(curves_test)