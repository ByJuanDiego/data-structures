cmake_minimum_required(VERSION 3.23)
project(list)

set(CMAKE_CXX_STANDARD 17)

add_executable(list main.cpp forward/node.cpp forward/node.h forward/forward_list.cpp forward/forward_list.h forward/forward_iterator.cpp forward/forward_iterator.h)
