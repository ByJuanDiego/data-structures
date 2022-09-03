//
// Created by Juan Diego on 9/2/2022.
//

#include "forward_list.h"

template<typename T>
forward_list<T>::forward_list()
: nodes(0), head(nullptr), tail(nullptr)
{
}

template<typename T>
forward_list<T>::~forward_list()
{
}

template<typename T>
bool forward_list<T>::empty() const {
    return (size() == 0);
}

template<typename T>
size_t forward_list<T>::size() const {
    return nodes;
}

template<typename T>
void forward_list<T>::push_front(const T& value) {
    auto* nodo = new node<T>(value);
    nodo->next = head;
    head = nodo;
    ++nodes;
}

template<typename T>
T forward_list<T>::pop_front() {
    if (empty())
    {
        throw ("Invalid operation, empty list");
    }
    T value = head->data;
    node<T>* nodo = head;
    head = head->next;
    nodo->kill_self();
    --nodes;
    return value;
}

template<typename T>
T &forward_list<T>::front() {
    return head->data;
}

template<typename T>
T &forward_list<T>::back() {
    node<T>* iterable = head;
    while (iterable->next != nullptr)
    {
        iterable = iterable->next;
    }
    return iterable->data;
}
