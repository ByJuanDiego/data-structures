//
// Created by Juan Diego on 9/2/2022.
//

#include "node.h"

template<typename T>
node<T>::node()
: data(T()), prev(nullptr), next(nullptr)
{
}

template<typename T>
node<T>::node(const T &value)
: data(value), prev(nullptr), next(nullptr)
{
}

template<typename T>
void node<T>::kill_self() {
    next = prev = nullptr;
}
