cmake_minimum_required(VERSION 3.3)
project(main)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")

set(SOURCE_FILES main.cpp)
include_directories(.)
add_executable(main ${SOURCE_FILES})
LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)
TARGET_LINK_LIBRARIES(main glfw GLEW GLU GL pthread)

