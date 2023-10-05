add_executable(sandbox src/main.cpp)
target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR}/curves/include)
target_link_libraries(sandbox curves)

if(MSVC)
    target_compile_options(sandbox PRIVATE /W4)
else()
    target_compile_options(sandbox PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()
