//
// Created by Juan Diego on 9/2/2022.
//

#ifndef ARRAY_CIRCULAR_ITERATOR_H
#define ARRAY_CIRCULAR_ITERATOR_H

#include <iostream>
#include <cstddef>
using index_t =  ssize_t;

template <typename T>
class circular_array;

template <typename T>
class array_iterator{

private:

    index_t current;
    circular_array<T>* array;

public:

    array_iterator();
    explicit array_iterator(circular_array<T>* array, const index_t& index);
    array_iterator(const array_iterator<T>& other);

    array_iterator<T>& operator++();
    array_iterator<T>& operator--();
    array_iterator<T> operator++(int);
    array_iterator<T> operator--(int);

    [[nodiscard]] T operator*() const;
    [[nodiscard]] T& operator*();

    bool operator== (const array_iterator<T>& other) const;
    bool operator!= (const array_iterator<T>& other) const;
    bool operator < (const array_iterator<T>& other) const;
    bool operator<= (const array_iterator<T>& other) const;

    template<typename U>
    friend std::ostream& operator << (std::ostream& os, const array_iterator<U>& iterator);
};



#endif //ARRAY_CIRCULAR_ITERATOR_H
