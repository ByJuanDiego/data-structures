cmake_minimum_required(VERSION 3.23)
project(list)

set(CMAKE_CXX_STANDARD 17)

add_executable(list main.cpp node.cpp node.h forward_list.cpp forward_list.h)
