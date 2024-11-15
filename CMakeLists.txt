cmake_minimum_required(VERSION 3.5)

# Set C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

# The project
project(My3dEngine)
add_executable(test src/test.cpp)
