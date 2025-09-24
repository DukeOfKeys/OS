cmake_minimum_required(VERSION 3.15)

project(laba2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LAUNCH_METHOD "WINAPI" CACHE STRING "Method to launch program: WINAPI, THREAD")
set_property(CACHE LAUNCH_METHOD PROPERTY STRINGS WINAPI THREAD)

if(LAUNCH_METHOD STREQUAL "THREAD")
    add_compile_definitions(USED_CXX_THREADS)
    message(STATUS "Launch method: CXX thread")
elseif(LAUNCH_METHOD STREQUAL "WINAPI")
    add_compile_definitions(USED_STANDART_WIN_API)
    message(STATUS "Launch method: WINAPI (Windows API)")
else()
    message(FATAL_ERROR "Unknown LAUNCH_METHOD: ${LAUNCH_METHOD}")
endif()

# Основное приложение
add_executable(main main.cpp avarage.cpp min_max.cpp)
target_link_libraries(main PRIVATE user32 gdi32 kernel32 advapi32)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR})

# ----------------- TESTS -----------------
include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.6.0
)

FetchContent_MakeAvailable(catch2)

include(CTest)
enable_testing()

add_subdirectory(tests)
