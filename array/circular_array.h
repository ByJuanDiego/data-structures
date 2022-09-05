//
// Created by Juan Diego on 9/1/2022.
//

#ifndef ARRAY_CIRCULAR_ARRAY_H
#define ARRAY_CIRCULAR_ARRAY_H
#define DEFAULT_SIZE 50

#include <stdexcept>
#include <initializer_list>
#include "circular_iterator.h"

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

    void _assign_();                                                                       // O(n)
    void _resize_();                                                                       // O(n)
    void _copy_();                                                                         // O(n)

public:

    circular_array();                                                                      // O(1)
    circular_array(const std::initializer_list<T>& list);                                  // O(n)
    explicit circular_array(const std::initializer_list<T>& list, const size_t& capacity); // O(n)
    explicit circular_array(const size_t& capacity);                                       // O(n)
    virtual ~circular_array();                                                             // O(n)

    [[nodiscard]] index_t prev(const index_t& index) const;                                 // O(1)
    [[nodiscard]] index_t next(const index_t& index) const;                                 // O(1)

    [[nodiscard]] bool empty() const;                                                       // O(1)
    [[nodiscard]] bool full() const;                                                        // O(1)
    [[nodiscard]] size_t size() const;                                                      // O(1)
    [[nodiscard]] size_t get_capacity() const;                                              // O(1)

    void push_back(const T& value);                                                         // O(n)
    void push_front(const T& value);                                                        // O(n)
    T pop_back();                                                                           // O(1)
    T pop_front();                                                                          // O(1)

    [[nodiscard]] T& operator[](index_t index);                                             // O(1)
    [[nodiscard]] T operator[](index_t index) const;                                        // O(1)

    [[nodiscard]] std::string to_string(const std::string& step = " ") const;               // O(n)

    template<typename U>                                                                    // O(n)
    friend std::ostream& operator << (std::ostream& os, const circular_array<U>& array);

    void clear();                                                                           // O(1)
    void resize(const size_t& new_size);                                                    // O(n)

    [[nodiscard]] iterator begin();                                                         // O(1)
    [[nodiscard]] iterator end();                                                           // O(1)
};


template<typename T>
void circular_array<T>::_assign_()
{
    front = back = -1;
    data = new T[capacity];
}

template<typename T>
circular_array<T>::circular_array()
: capacity(DEFAULT_SIZE), front(), back()
{
    _assign_();
}

template<typename T>
circular_array<T>::circular_array(const std::initializer_list<T>& list)
: capacity(std::distance(list.begin(), list.end())), front(), back()
{
    _assign_();
    for (const T& element: list){
        this->push_back(element);
    }
}

template<typename T>
circular_array<T>::circular_array(const std::initializer_list<T> &list, const size_t& capacity)
: capacity(capacity), front(), back()
{
    _assign_();
    for (const T& element: list){
        this->push_back(element);
    }
}


template<typename T>
circular_array<T>::circular_array(const size_t &capacity)
: capacity(capacity), front(), back()
{
    _assign_();
}

template<typename T>
circular_array<T>::~circular_array()
{
    delete [] data;
}


template<typename T>
bool circular_array<T>::empty() const
{
    return (front == -1);
}

template<typename T>
index_t circular_array<T>::prev(const index_t& index) const
{
    if (empty() || index < 0)
    {
        throw std::invalid_argument("Invalid operation, index out of range");
    }
    return (index == 0)? (capacity-1) : (index-1);
}

template<typename T>
index_t circular_array<T>::next(const index_t& index) const
{
    if (empty() || index < 0)
    {
        throw std::invalid_argument("Invalid operation, index out of range");
    }
    return (index + 1) % capacity;
}

template<typename T>
size_t circular_array<T>::size() const
{
    if (empty())
    {
        return 0;
    }
    return (front <= back)? (back - front + 1) : (capacity - front + back + 1);
}

template<typename T>
size_t circular_array<T>::get_capacity() const{
    return capacity;
}

template<typename T>
void circular_array<T>::push_back(const T& value)
{
    if (full()){
        _resize_();
        back = next(back);
    } else if (empty()){
        front = back = 0;
    } else{
        back = next(back);
    }
    data[back] = value;
}

template<typename T>
void circular_array<T>::push_front(const T& value)
{
    if (full()){
        _resize_();
        front = prev(front);
    } else if (empty()){
        front = back = 0;
    } else{
        front = prev(front);
    }
    data[front] = value;
}


template<typename T>
bool circular_array<T>::full() const {
    return !(empty()) && (next(back) == front);
}

template<typename T>
T circular_array<T>::pop_back() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, the array is empty");
    }

    T temp = data[back];
    if (size() == 1){
        back = front = -1;
    } else{
        back = prev(back);
    }
    return temp;
}

template<typename T>
T circular_array<T>::pop_front() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, the array is empty");
    }

    T temp = data[front];
    if (size() == 1){
        back = front = -1;
    } else{
        front = next(front);
    }
    return temp;
}

template<typename T>
T& circular_array<T>::operator[](index_t index){
    if (index > capacity){
        throw std::invalid_argument("Invalid operation, index out of range");
    }
    return data[(front + index) % capacity];
}

template<typename T>
T circular_array<T>::operator[](index_t index) const{
    if (index > capacity){
        throw std::invalid_argument("Invalid operation, index out of range");
    }
    return data[(front + index) % capacity];
}


template<typename T>
std::string circular_array<T>::to_string(const std::string& step) const{
    std::string result;
    for (int i=0; i<size(); i++){
        result += std::to_string((*this)[i]) + step;
    }
    return result;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const circular_array<U> &array) {
    for (size_t i=0; i<array.size(); ++i){
        os << array[i] << " ";
    }
    return os;
}

template<typename T>
void circular_array<T>::clear() {
    front = back = -1;
}

template<typename T>
typename circular_array<T>::iterator circular_array<T>::begin() {
    return iterator(this, 0);
}

template<typename T>
typename circular_array<T>::iterator circular_array<T>::end() {
    return iterator(this, -1);
}

template<typename T>
void circular_array<T>::_resize_() {
    size_t sz = size();
    capacity = capacity * 2;
    _copy_();
    front = 0;
    back = static_cast<index_t>(sz)-1;
}

template<typename T>
void circular_array<T>::resize(const size_t &new_size) {
    size_t sz = size();
    capacity = new_size;
    _copy_();
    front = 0;
    back = static_cast<index_t>(sz)-1;
}

template<typename T>
void circular_array<T>::_copy_() {
    T* new_data = new T[capacity];
    for (int i=0; i<size(); ++i){
        new_data[i] = (*this)[i];
    }
    delete [] data;
    data = new_data;
}

template<typename T>
array_iterator<T> &array_iterator<T>::operator++() {
    if (current == array->size()-1){
        current = -1;
    } else {
        current = array->next(current);
    }
    return (*this);
}

template<typename T>
array_iterator<T> &array_iterator<T>::operator--() {
    if (current > 0){
        current = array->prev(current);
    } else {
        current = array->size()-1;
    }
    return (*this);
}

template<typename T>
T &array_iterator<T>::operator*() {
    return array->operator[](current);
}

template<typename T>
T array_iterator<T>::operator*() const {
    return array->operator[](current);
}

#endif //ARRAY_CIRCULAR_ARRAY_H
