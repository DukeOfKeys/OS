cmake_minimum_required(VERSION 3.15)

project(laba1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LAUNCH_METHOD "CMD" CACHE STRING "Method to launch program: CMD, WIN_API, CROSS_CPP")
set_property(CACHE LAUNCH_METHOD PROPERTY STRINGS CMD WIN_API CROSS_CPP)

if(LAUNCH_METHOD STREQUAL "CMD")
    add_compile_definitions(USED_CMD_LAUNCH)
    message(STATUS "Launch method: CMD (system())")
elseif(LAUNCH_METHOD STREQUAL "WIN_API")
    add_compile_definitions(USED_STANDART_WIN_API)
    message(STATUS "Launch method: WIN_API (Windows API)")
elseif(LAUNCH_METHOD STREQUAL "CROSS_CPP")
    add_compile_definitions(USED_STANDART_CROSSPLATFORM_CPP)
    message(STATUS "Launch method: CROSS_CPP (cross-platform C++)")
else()
    message(FATAL_ERROR "Unknown LAUNCH_METHOD: ${LAUNCH_METHOD}")
endif()

add_executable(main main.cpp)
target_link_libraries(main PRIVATE user32 gdi32 kernel32 advapi32)


add_library(creator_func STATIC creator_func.cpp)
target_include_directories(creator_func PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(creator creator.cpp)
target_link_libraries(creator PRIVATE creator_func user32 gdi32 kernel32 advapi32)

add_library(reporter_func STATIC reporter_func.cpp)
target_include_directories(reporter_func PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(reporter reporter.cpp)
target_link_libraries(reporter PRIVATE reporter_func user32 gdi32 kernel32 advapi32)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_subdirectory(tests)