//
// Created by Juan Diego on 9/1/2022.
//

#ifndef ARRAY_CIRCULAR_ARRAY_H
#define ARRAY_CIRCULAR_ARRAY_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <initializer_list>
#include "circular_iterator.cpp"

template <typename T>
class circular_array {

public:

    typedef array_iterator<T> iterator;
    friend class array_iterator<T>;

private:

    T* data = nullptr;
    size_t capacity;
    index_t front;
    index_t back;

    void _assign_(); // O(n)
    void _resize_(); // O(n)
    void _copy_();   // O(n)

public:

    circular_array();                                                                      // O(1)
    circular_array(const std::initializer_list<T>& list);                                  // O(n)
    explicit circular_array(const std::initializer_list<T>& list, const size_t& capacity); // O(n)
    explicit circular_array(const size_t& capacity);                                       // O(n)
    virtual ~circular_array();                                                             // O(n)

    [[nodiscard]] index_t prev(const index_t& index) const; // O(1)
    [[nodiscard]] index_t next(const index_t& index) const; // O(1)

    [[nodiscard]] bool empty() const;          // O(1)
    [[nodiscard]] bool full() const;           // O(1)
    [[nodiscard]] size_t size() const;         // O(1)
    [[nodiscard]] size_t get_capacity() const; // O(1)

    void push_back(const T& value);             // O(n)
    void push_front(const T& value);            // O(n)
    T pop_back();                               // O(1)
    T pop_front();                              // O(1)

    [[nodiscard]] T& operator[](index_t index);      // O(1)
    [[nodiscard]] T operator[](index_t index) const; // O(1)

    [[nodiscard]] std::string to_string(const std::string& step = " ") const; // O(n)

    template<typename U> // O(n)
    friend std::ostream& operator << (std::ostream& os, const circular_array<U>& array);

    void clear();                        // O(1)
    void resize(const size_t& new_size); // O(n)

    [[nodiscard]] iterator begin();      // O(1)
    [[nodiscard]] iterator end();        // O(1)
};


#endif //ARRAY_CIRCULAR_ARRAY_H
