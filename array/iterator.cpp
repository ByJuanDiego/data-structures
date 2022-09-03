//
// Created by Juan Diego on 9/2/2022.
//

#include "iterator.h"

template<typename T>
array_iterator<T>::array_iterator()
        : current(-1), array(nullptr)
{
}

template<typename T>
array_iterator<T>::array_iterator(circular_array<T> *array, const index_t& index)
        : array(array), current(index)
{
}

template<typename T>
array_iterator<T>::array_iterator(const array_iterator<T> &other)
        :  current(other.current), array(other.array)
{
}

template<typename T>
array_iterator<T> array_iterator<T>::operator++(int) {
    array_iterator<T> temp = (*this);
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
bool array_iterator<T>::operator==(const array_iterator<T> &other) const{
    return (this->current == other.current);
}

template<typename T>
bool array_iterator<T>::operator!=(const array_iterator<T> &other) const{
    return !(this->operator==(other));
}

template<typename T>
bool array_iterator<T>::operator<(const array_iterator<T> &other) const {
    if ((current >= 0) && (other.current == -1)) return true;
    else if ((current == -1) && (other.current >= 0)) return false;
    return this->current < other.current;
}

template<typename T>
bool array_iterator<T>::operator<=(const array_iterator<T> &other) const {
    return (this->operator<(other) || (current == other.current));
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const array_iterator<U> &iterator) {
    os << iterator.current;
    return os;
}
