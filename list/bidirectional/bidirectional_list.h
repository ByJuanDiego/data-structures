//
// Created by Juan Diego on 9/4/2022.
//

#ifndef LIST_BIDIRECTIONAL_LIST_H
#define LIST_BIDIRECTIONAL_LIST_H

#include "bidirectional_node.cpp"
#include "bidirectional_iterator.cpp"
#include <stdexcept>
#include <cstdlib>
#include <initializer_list>

using index_t = size_t;

template<typename T>
class bidirectional_list {

public:

    using iterator = bidirectional_iterator<T>;

private:

    bidirectional_node<T>* head;
    bidirectional_node<T>* tail;
    size_t nodes;
    T& _index_(const index_t& index) const;

public:

    bidirectional_list();                                                                  // O(1)
    bidirectional_list(const std::initializer_list<T>& list);                              // O(n)
    ~bidirectional_list();                                                                 // O(n)

    [[nodiscard]] bool empty() const;                                                      // O(1)
    [[nodiscard]] size_t size() const;                                                     // O(1)

    void push_front(const T& value);                                                       // O(1)
    void push_back(const T& value);                                                        // O(1)

    T pop_front();                                                                         // O(1)
    T pop_back();                                                                          // O(1)

    [[nodiscard]] T& front();                                                              // O(1)
    [[nodiscard]] T& back();                                                               // O(1)
    [[nodiscard]] T front() const;                                                         // O(1)
    [[nodiscard]] T back() const;                                                          // O(1)

    [[nodiscard]] T& operator[](index_t index);                                            // O(n)
    [[nodiscard]] T operator[](index_t index) const;                                       // O(n)

    void clear();                                                                          // O(n)

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, const bidirectional_list<U>& list); // O(n)

    iterator begin();                                                                      // O(1)
    iterator end();                                                                        // O(1)

};


#endif //LIST_BIDIRECTIONAL_LIST_H
