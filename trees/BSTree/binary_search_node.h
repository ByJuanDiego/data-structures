//
// Created by Juan Diego on 9/8/2022.
//

#ifndef TREES_BINARY_SEARCH_NODE_H
#define TREES_BINARY_SEARCH_NODE_H


template <typename T>
struct binary_search_node {
    T data;
    binary_search_node<T>* left;
    binary_search_node<T>* right;

    binary_search_node();
    explicit binary_search_node(T value);
    binary_search_node(const binary_search_node<T>& other);

};

template<typename T>
binary_search_node<T>::binary_search_node()
: data(), left(nullptr), right(nullptr)
{
}

template<typename T>
binary_search_node<T>::binary_search_node(T value)
: data(value), left(nullptr), right(nullptr)
{
}

template<typename T>
binary_search_node<T>::binary_search_node(const binary_search_node<T> &other)
: data(other.data), left(other.left), right(other.right)
{
}


#endif //TREES_BINARY_SEARCH_NODE_H
