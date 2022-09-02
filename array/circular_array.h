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

private:

    T* data = nullptr;
    size_t capacity;
    index_t front;
    index_t back;

    void _assign_();
    void _resize_();
    void _copy_();
    [[nodiscard]] index_t prev(const index_t& idx) const;
    [[nodiscard]] index_t next(const index_t& idx) const;

public:

    circular_array();
    circular_array(const std::initializer_list<T>& list);
    explicit circular_array(const std::initializer_list<T>& list, const size_t& capacity);
    explicit circular_array(const size_t& capacity);
    virtual ~circular_array();

    [[nodiscard]] bool empty() const;
    [[nodiscard]] bool full() const;
    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t get_capacity() const;

    void push_back(const T& value);
    void push_front(const T& value);
    T pop_back();
    T pop_front();

    [[nodiscard]] T& operator[](index_t idx);
    [[nodiscard]] T operator[](index_t idx) const;

    [[nodiscard]] std::string to_string(const std::string& step = " ") const;

    template<typename U>
    friend std::ostream& operator << (std::ostream& os, const circular_array<U>& array);

    void clear();
    void resize(const size_t& new_size);

    [[nodiscard]] iterator begin();
    [[nodiscard]] iterator end();
};

template<typename T, typename Function>
void for_adapter(circular_array<T>& array, const Function& function) {
    for (int i=0; i<array.size(); i++){
        function(array[i]);
    }
}

template<typename T, typename Function>
void for_adapter_ptr(circular_array<T>& array, const Function& function){
    for (circular_array<int>::iterator it = array.begin(); it != array.end(); it++){
        function(*it);
    }
    function(*array.end());
}


#endif //ARRAY_CIRCULAR_ARRAY_H
