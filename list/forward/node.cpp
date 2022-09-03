//
// Created by Juan Diego on 9/2/2022.
//

#include "node.h"

template<typename T>
node<T>::node()
: data(T()), next(nullptr)
{
}

template<typename T>
node<T>::node(const T &value)
: data(value), next(nullptr)
{
}

template<typename T>
void node<T>::_kill_self_() {
    next = nullptr;
}

template<typename T>
node<T>::~node() {
    _kill_self_();
}
