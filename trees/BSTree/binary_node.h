//
// Created by Juan Diego on 9/8/2022.
//

#ifndef TREES_BINARY_NODE_H
#define TREES_BINARY_NODE_H


template <typename T>
struct binary_node {
    T data;
    binary_node<T>* left;
    binary_node<T>* right;

    binary_node();
    explicit binary_node(T value);
    binary_node(const binary_node<T>& other);

};

template<typename T>
binary_node<T>::binary_node()
: data(), left(nullptr), right(nullptr)
{
}

template<typename T>
binary_node<T>::binary_node(T value)
: data(value), left(nullptr), right(nullptr)
{
}

template<typename T>
binary_node<T>::binary_node(const binary_node<T> &other)
: data(other.data), left(other.left), right(other.right)
{
}


#endif //TREES_BINARY_NODE_H
