//
// Created by Juan Diego on 9/4/2022.
//

#ifndef LIST_BIDIRECTIONAL_ITERATOR_H
#define LIST_BIDIRECTIONAL_ITERATOR_H

#include <stdexcept>
#include "bidirectional_node.h"

template <typename T>
class bidirectional_iterator {

private:

    bidirectional_node<T>* current;

public:

    bidirectional_iterator();
    explicit bidirectional_iterator(bidirectional_node<T>* node);
    bidirectional_iterator(const bidirectional_iterator<T>& other);

    bidirectional_iterator<T>& operator++();
    bidirectional_iterator<T>& operator--();
    bidirectional_iterator<T> operator++(int);
    bidirectional_iterator<T> operator--(int);

    [[nodiscard]] T& operator*();
    [[nodiscard]] T operator*() const;

    bool operator == (const bidirectional_iterator<T>& other) const;
    bool operator != (const bidirectional_iterator<T>& other) const;

};


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
bidirectional_iterator<T>& bidirectional_iterator<T>::operator++() {
    if (current == nullptr){
        throw std::invalid_argument("Invalid operation, the current node is the end of the list");
    }
    current = current->next;
    return (*this);
}

template<typename T>
bidirectional_iterator<T> &bidirectional_iterator<T>::operator--() {
    current = current->prev;
    return (*this);
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
T &bidirectional_iterator<T>::operator*() {
    return current->data;
}

template<typename T>
T bidirectional_iterator<T>::operator*() const {
    return current->data;
}

template<typename T>
bool bidirectional_iterator<T>::operator==(const bidirectional_iterator<T> &other) const {
    return &current->data == &other.current->data;
}

template<typename T>
bool bidirectional_iterator<T>::operator!=(const bidirectional_iterator<T> &other) const {
    return !(this->operator==(other));
}


#endif //LIST_BIDIRECTIONAL_ITERATOR_H
