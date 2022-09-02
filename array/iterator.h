//
// Created by Juan Diego on 9/2/2022.
//

#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

#include <cstddef>
using index_t =  std::size_t;

template <typename T>
class array_iterator{

    using data_ptr = T*;

private:

    index_t current;
    data_ptr data;
    size_t* capacity;

public:

    array_iterator();
    array_iterator(const index_t& idx, data_ptr& data, size_t& capacity);
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
};



#endif //ARRAY_ITERATOR_H
