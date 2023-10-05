add_library(curves SHARED 
    src/Circle.cpp 
    src/Ellipse.cpp 
    src/Helix.cpp 
    include/Circle.h 
    include/Ellipse.h 
    include/Helix.h 
    include/ICurve.h 
    include/Vec3.h
    include/curves.h
)

target_include_directories(curves PRIVATE ${CMAKE_SOURCE_DIR}/curves/include)

if(MSVC)
    target_compile_options(curves PRIVATE /W4)
else()
    target_compile_options(curves PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()