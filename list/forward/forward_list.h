//
// Created by Juan Diego on 9/2/2022.
//

#ifndef LIST_FORWARD_LIST_H
#define LIST_FORWARD_LIST_H

#include "forward_node.cpp"
#include "forward_iterator.cpp"
#include <cstdlib>
#include <iostream>
#include <initializer_list>

using index_t = size_t;

template <typename T>
class forward_list {

public:

    using iterator = forward_iterator<T>;

private:

    forward_node<T>* head;
    forward_node<T>* tail;
    size_t nodes;
    void _swap_(forward_node<T>*& a, forward_node<T>*& b);                           // O(1)
    T& _index_(const index_t& index) const;                                          // O(n)

public:

    forward_list();                                                                  // O(1)
    forward_list(const std::initializer_list<T>& list, const bool& push_front=true); // O(n)
    ~forward_list();                                                                 // O(n)

    [[nodiscard]] size_t size() const;                                               // O(1)
    [[nodiscard]] bool empty() const;                                                // O(1)
    [[nodiscard]] bool sorted() const;                                               // O(n)

    void push_front(const T& value);                                                 // O(1)
    void push_back(const T& value);                                                  // O(1)

    T pop_front();                                                                   // O(1)
    T pop_back();                                                                    // O(n)

    [[nodiscard]] T& front();                                                        // O(1)
    [[nodiscard]] T& back();                                                         // O(1)
    [[nodiscard]] T front() const;                                                   // O(1)
    [[nodiscard]] T back() const;                                                    // O(1)

    [[nodiscard]] T& operator[](const index_t& index);                               // O(n)
    T operator[](const index_t& index) const;                                        // O(n)

    // internally uses an implementation of selection sort
    void sort();                                                                     // O(n²)
    void clear();                                                                    // O(n)

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, const forward_list<U>& list); // O(n)

    iterator begin();                                                                // O(1)
    iterator end();                                                                  // O(1)

};


#endif //LIST_FORWARD_LIST_H
