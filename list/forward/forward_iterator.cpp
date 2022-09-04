//
// Created by Juan Diego on 9/3/2022.
//

#include "forward_iterator.h"

template<typename T>
forward_iterator<T>::forward_iterator()
:current(nullptr)
{
}

template<typename T>
forward_iterator<T>::forward_iterator(node<T>* nodo)
: current(nodo)
{
}

template<typename T>
forward_iterator<T>::forward_iterator(const forward_iterator<T> &other)
: current(other.current)
{
}
