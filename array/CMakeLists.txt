cmake_minimum_required(VERSION 3.23)
project(array)

set(CMAKE_CXX_STANDARD 17)

add_executable(array main.cpp circular_array.h circular_array.cpp iterator.cpp iterator.h)
