cmake_minimum_required(VERSION 3.23)
project(list)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp

        forward/forward_node.h
        forward/forward_list.h
        forward/forward_iterator.h

        bidirectional/bidirectional_node.h
        bidirectional/bidirectional_list.h
        bidirectional/bidirectional_iterator.h

)
