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
forward_iterator<T>::forward_iterator(forward_node<T>* node)
: current(node)
{
}

template<typename T>
forward_iterator<T>::forward_iterator(const forward_iterator<T> &other)
: current(other.current)
{
}

template<typename T>
forward_iterator<T> forward_iterator<T>::operator++(int) {
    forward_iterator<T> temp = (*this);
    ++(*this);
    return temp;
}

template<typename T>
bool forward_iterator<T>::operator!=(const forward_iterator<T> &other) const {
    return !(this->operator==(other));
}
