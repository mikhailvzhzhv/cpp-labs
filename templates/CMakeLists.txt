cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(tmp)

set(exe_name ${PROJECT_NAME})

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# add_library(corelib OBJECT flatmap.cpp)

add_executable(${exe_name} main.cpp)
# target_link_libraries(${exe_name} corelib)
