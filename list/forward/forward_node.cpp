//
// Created by Juan Diego on 9/2/2022.
//

#include "forward_node.h"

template<typename T>
forward_node<T>::forward_node()
: data(T()), next(nullptr)
{
}

template<typename T>
forward_node<T>::forward_node(const T &value)
: data(value), next(nullptr)
{
}

template<typename T>
void forward_node<T>::_kill_self_() {
    next = nullptr;
}

template<typename T>
forward_node<T>::~forward_node() {
    _kill_self_();
}
