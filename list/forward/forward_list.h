//
// Created by Juan Diego on 9/2/2022.
//

#ifndef LIST_FORWARD_LIST_H
#define LIST_FORWARD_LIST_H

#include "node.cpp"
#include <cstdlib>
#include <iostream>
#include <initializer_list>

template <typename T>
class forward_list {

private:

    node<T>* head;
    node<T>* tail;
    size_t nodes;

public:

    forward_list();                    // O(1)
    forward_list(const std::initializer_list<T>& list, const bool& push_front = true); // O(n)
    ~forward_list();                   // O(n)

    [[nodiscard]] size_t size() const; // O(1)
    [[nodiscard]] bool empty() const;  // O(1)
    [[nodiscard]] bool sorted() const; // O(n)

    void push_front(const T& value);   // O(1)
    void push_back(const T& value);    // O(1)

    T pop_front();                     // O(1)
    T pop_back();                      // O(n)

    [[nodiscard]] T& front();          // O(1)
    [[nodiscard]] T& back();           // O(1)

    void clear();                      // O(n)

    template<typename U>               // O(n)
    friend std::ostream& operator<< (std::ostream& os, const forward_list<U>& list);

};


#endif //LIST_FORWARD_LIST_H
