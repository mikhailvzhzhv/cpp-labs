cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(wav)

set(exe_name ${PROJECT_NAME})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(corelib OBJECT reader.cpp writer.cpp converter.cpp commander.cpp)

add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)
