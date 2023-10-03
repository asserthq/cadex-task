cmake_minimum_required(VERSION 3.2)

project(cadex-task)

# GTest lib

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/a6d7fa8c0cebaa8b493a1cecdfa05018f6adc8df.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

##########

add_executable(curves src/main.cpp)

if(MSVC)
    target_compile_options(curves PRIVATE /W4)
else()
    target_compile_options(curves PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()

target_compile_features(curves PRIVATE cxx_std_20)

# Testing

enable_testing()
add_executable(curves_test test/curves_test.cpp)
target_link_libraries(curves_test GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(curves_test)