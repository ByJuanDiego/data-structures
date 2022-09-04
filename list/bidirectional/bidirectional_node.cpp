//
// Created by Juan Diego on 9/4/2022.
//

#include "bidirectional_node.h"

template<typename T>
void bidirectional_node<T>::_kill_self_() {
    prev = next = nullptr;
}

template<typename T>
bidirectional_node<T>::bidirectional_node()
: data(T()), next(nullptr), prev(nullptr)
{
}

template<typename T>
bidirectional_node<T>::bidirectional_node(const T &value)
:data(value), next(nullptr), prev(nullptr)
{
}

template<typename T>
bidirectional_node<T>::bidirectional_node(const bidirectional_node<T> *&other)
: data(other->data), next(other->next), prev(other->next)
{
}

template<typename T>
bidirectional_node<T>::~bidirectional_node() {
    _kill_self_();
}
