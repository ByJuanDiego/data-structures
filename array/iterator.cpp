//
// Created by Juan Diego on 9/2/2022.
//

#include "iterator.h"

template<typename T>
array_iterator<T>::array_iterator()
        : current(-1), data(nullptr), capacity(nullptr)
{
}

template<typename T>
array_iterator<T>::array_iterator(const index_t& idx, data_ptr& data, size_t& capacity)
        : current(idx), data(data), capacity(&capacity)
{
}

template<typename T>
array_iterator<T>::array_iterator(const array_iterator<T> &other)
        :  current(other.current), capacity(other.capacity), data(other.data)
{
}


template<typename T>
array_iterator<T> &array_iterator<T>::operator++() {
    current = (current + 1) % (*capacity);
    return (*this);
}

template<typename T>
array_iterator<T> &array_iterator<T>::operator--() {
    current = (current == 0)? (*capacity-1) : (current-1);
    return (*this);
}

template<typename T>
array_iterator<T> array_iterator<T>::operator++(int) {
    const array_iterator<T> temp = (*this);
    ++(*this);
    return temp;
}

template<typename T>
array_iterator<T> array_iterator<T>::operator--(int) {
    array_iterator<T> temp = (*this);
    --(*this);
    return temp;
}

template<typename T>
T &array_iterator<T>::operator*() {
    return data[current];
}

template<typename T>
T array_iterator<T>::operator*() const {
    return data[current];
}


template<typename T>
bool array_iterator<T>::operator==(const array_iterator<T> &other) const{
    return (this->current == other.current);
}

template<typename T>
bool array_iterator<T>::operator!=(const array_iterator<T> &other) const{
    return !(this->operator==(other));
}

template<typename T>
bool array_iterator<T>::operator<(const array_iterator<T> &other) const {
    return (this->current < other.current);
}

template<typename T>
bool array_iterator<T>::operator<=(const array_iterator<T> &other) const {
    return (this->current <=other.current);
}
