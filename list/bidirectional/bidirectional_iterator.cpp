//
// Created by Juan Diego on 9/4/2022.
//

#include "bidirectional_iterator.h"

template<typename T>
bidirectional_iterator<T>::bidirectional_iterator()
: current(nullptr)
{
}

template<typename T>
bidirectional_iterator<T>::bidirectional_iterator(bidirectional_node<T> *node)
: current(node)
{
}

template<typename T>
bidirectional_iterator<T>::bidirectional_iterator(const bidirectional_iterator<T> &other)
: current(other.current)
{
}

template<typename T>
bidirectional_iterator<T> bidirectional_iterator<T>::operator++(int) {
    bidirectional_iterator<T> temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
bidirectional_iterator<T> bidirectional_iterator<T>::operator--(int) {
    bidirectional_iterator<T> temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
bool bidirectional_iterator<T>::operator!=(const bidirectional_iterator<T> &other) const {
    return !(this->operator==(other));
}
