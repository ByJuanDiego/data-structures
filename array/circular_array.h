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
#include "iterator.cpp"

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

    void _assign_();
    void _resize_();
    void _copy_();

public:

    circular_array();
    circular_array(const std::initializer_list<T>& list);
    explicit circular_array(const std::initializer_list<T>& list, const size_t& capacity);
    explicit circular_array(const size_t& capacity);
    virtual ~circular_array();

    [[nodiscard]] index_t prev(const index_t& index) const;
    [[nodiscard]] index_t next(const index_t& index) const;

    [[nodiscard]] bool empty() const;
    [[nodiscard]] bool full() const;
    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t get_capacity() const;

    void push_back(const T& value);
    void push_front(const T& value);
    T pop_back();
    T pop_front();

    [[nodiscard]] T& operator[](index_t index);
    [[nodiscard]] T operator[](index_t index) const;

    [[nodiscard]] std::string to_string(const std::string& step = " ") const;

    template<typename U>
    friend std::ostream& operator << (std::ostream& os, const circular_array<U>& array);

    void clear();
    void resize(const size_t& new_size);

    [[nodiscard]] iterator begin();
    [[nodiscard]] iterator end();
};


#endif //ARRAY_CIRCULAR_ARRAY_H
