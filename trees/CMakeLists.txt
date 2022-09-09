cmake_minimum_required(VERSION 3.23)
project(trees)

set(CMAKE_CXX_STANDARD 17)

add_executable(trees main.cpp BSTree/binary_search_tree.h BSTree/binary_node.h)
