
cmake_minimum_required(VERSION 3.14)

project(game CXX)

set(CMAKE_CXX_STANDARD 17)

set(exe_name ${PROJECT_NAME})

file(GLOB game_obj_sources "game_objects/*.cpp")
file(GLOB game_screen_sources "game_screen/*.cpp")
file(GLOB ctx_sources "context/*.cpp")
file(GLOB factory_sources "factory/*.cpp")
file(GLOB score_table_sources "score_table/*.cpp")
file(GLOB imp_sources "*.cpp")
file(GLOB save_table_sources "save_table/*.cpp")

if(WIN32 OR MSVC)
    include(FetchContent)
    FetchContent_Declare(
        PDcurses
        GIT_REPOSITORY https://github.com/dsavenko/PDCurses.git
        GIT_TAG        dfbac0fe5ef90a40a67d6b13cc7d9c69bf40a5f5
    )
    FetchContent_MakeAvailable(PDcurses)
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fsanitize=address")
add_compile_definitions(UBSAN_ON)
add_compile_definitions(ASAN_ON)

add_executable(${exe_name} ${imp_sources} ${game_obj_sources} ${game_screen_sources} ${ctx_sources} ${factory_sources} ${score_table_sources} ${save_table_sources})

if(WIN32 OR MSVC)
    target_link_libraries(${exe_name} PDcurses)
else()
    target_link_libraries(${exe_name} curses)
endif()
