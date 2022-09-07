//
// Created by Juan Diego on 9/7/2022.
//

#ifndef LIST_CIRCULAR_LIST_H
#define LIST_CIRCULAR_LIST_H

#include <iostream>
#include <initializer_list>
#include "circular_iterator.h"

using index_t = ssize_t;

template <typename T>
    class circular_list{

private:

    circular_node<T>* sentinel;

public:

    circular_list();                                                                  // O(1)
    circular_list(const std::initializer_list<T>& list);                              // O(n)
    ~circular_list();                                                                 // O(n)

    [[nodiscard]] bool empty() const;                                                 // O(1)
    [[nodiscard]] size_t size() const;                                                // O(n)
    void push_front(const T& value);                                                  // O(1)
    void push_back(const T& value);                                                   // O(1)

    T pop_front();                                                                    // O(1)
    T pop_back();                                                                     // O(1)

    [[nodiscard]] T& front();                                                         // O(1)
    [[nodiscard]] T& back();                                                          // O(1)
    [[nodiscard]] T front() const;                                                    // O(1)
    [[nodiscard]] T back() const;                                                     // O(1)

    void clear();                                                                     // O(n)

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, const circular_list<U>& list); // O(n)

};

template<typename T>
circular_list<T>::circular_list()
: sentinel(new circular_node<T>)
{
}

template<typename T>
circular_list<T>::circular_list(const std::initializer_list<T> &list)
: sentinel(new circular_node<T>)
{
    for (const T& element: list){
        this->push_back(element);
    }
}

template<typename T>
circular_list<T>::~circular_list() {
    clear();
}

template<typename T>
bool circular_list<T>::empty() const {
    return (sentinel->prev == sentinel->next);
}

template<typename T>
size_t circular_list<T>::size() const{
    size_t sz = 0;
    circular_node<T>* node = sentinel->next;
    while (node != sentinel){
        ++sz;
        node = node->next;
    }
    return sz;
}

template<typename T>
void circular_list<T>::push_front(const T &value) {
    auto* node = new circular_node<T>(value);
    node->next = sentinel->next;
    sentinel->next->prev = node;
    sentinel->next = node;
    node->prev = sentinel;
}

template<typename T>
void circular_list<T>::push_back(const T &value) {
    auto* node = new circular_node<T>(value);
    node->prev = sentinel->prev;
    sentinel->prev->next = node;
    node->next = sentinel;
    sentinel->prev = node;
}

template<typename T>
T circular_list<T>::pop_back() {
    circular_node<T>* node = sentinel->prev;
    if (node == sentinel){
        throw std::invalid_argument("Invalid operation, the list is empty");
    }
    T value = node->data;
    sentinel->prev = sentinel->prev->prev;
    sentinel->prev->next = sentinel;
    delete node;
    return value;
}

template<typename T>
T circular_list<T>::pop_front() {
    circular_node<T>* node = sentinel->next;
    if (node == sentinel){
        throw std::invalid_argument("Invalid operation, the list is empty");
    }
    T value = node->data;
    sentinel->next = sentinel->next->next;
    sentinel->next->prev = sentinel;
    delete node;
    return value;
}

template<typename T>
T &circular_list<T>::front() {
    return sentinel->next->data;
}

template<typename T>
T circular_list<T>::front() const {
    return sentinel->next->data;
}

template<typename T>
T & circular_list<T>::back() {
    return sentinel->prev->data;
}

template<typename T>
T circular_list<T>::back() const {
    return sentinel->prev->data;
}

template<typename T>
void circular_list<T>::clear() {
    circular_node<T>* iterable = sentinel->next;
    while (iterable != sentinel){
        circular_node<T>* node = iterable;
        iterable = iterable->next;
        delete node;
    }
    sentinel->prev = sentinel->next = sentinel;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const circular_list<U> &list) {
    circular_node<U>* node = list.sentinel->next;
    while (node != list.sentinel){
        os << node->data << " ";
        node = node->next;
    }
    return os;
}


#endif //LIST_CIRCULAR_LIST_H
