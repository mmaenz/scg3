# CMake configuration based on https://github.com/pablospe/cmake-example-library

cmake_minimum_required(VERSION 2.6)

# Project name
project (scg3)
set(LIBRARY_NAME scg3)
set(LIBRARY_FOLDER scg3)

# Use C++ 11
set(CMAKE_CXX_STANDARD 11)

# Library sources
add_subdirectory (libscg3)

# Example
#add_subdirectory (scg3_example)