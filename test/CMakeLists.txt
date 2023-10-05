# GTest lib

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Testing

enable_testing()
add_executable(curves_test curves_test.cpp)
target_include_directories(curves_test PRIVATE ${CMAKE_SOURCE_DIR}/curves/include)
target_link_libraries(curves_test GTest::gtest_main GTest::gmock_main curves)
include(GoogleTest)
gtest_discover_tests(curves_test)