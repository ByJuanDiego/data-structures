//
// Created by Juan Diego on 9/3/2022.
//

#ifndef LIST_FORWARD_ITERATOR_H
#define LIST_FORWARD_ITERATOR_H

#include "forward_node.h"
#include <stdexcept>

template <typename T>
class forward_iterator {
private:

    forward_node<T>* current;

public:

    forward_iterator();
    explicit forward_iterator(forward_node<T>* node);
    forward_iterator(const forward_iterator<T>& other);

    forward_iterator<T>& operator++();
    forward_iterator<T> operator++(int);

    bool operator== (const forward_iterator<T>& other) const;
    bool operator!= (const forward_iterator<T>& other) const;

    [[nodiscard]] T& operator*();
    [[nodiscard]] T operator*() const;
    [[nodiscard]] T* operator->();

};

template<typename T>
forward_iterator<T>::forward_iterator()
: current(nullptr)
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
forward_iterator<T> &forward_iterator<T>::operator++() {
    if (current == nullptr){
        throw std::invalid_argument("Invalid operation, the current node is the end of the list");
    }
    this->current = current->next;
    return *this;
}

template<typename T>
forward_iterator<T> forward_iterator<T>::operator++(int) {
    forward_iterator<T> temp = (*this);
    ++(*this);
    return temp;
}

template<typename T>
bool forward_iterator<T>::operator==(const forward_iterator<T> &other) const {
    return (
        (current == nullptr && other.current == nullptr)
        ||
        (&current->data == &other.current->data)
    );
}

template<typename T>
bool forward_iterator<T>::operator!=(const forward_iterator<T> &other) const {
    return !(this->operator==(other));
}

template<typename T>
T &forward_iterator<T>::operator*() {
    return current->data;
}

template<typename T>
T forward_iterator<T>::operator*() const {
    return current->data;
}

template<typename T>
T* forward_iterator<T>::operator->(){
    if (current == nullptr){
        throw std::invalid_argument("Invalid argument, the iterator points to nullptr");
    }
    return &current->data;
}

#endif //LIST_FORWARD_ITERATOR_H
