//
// Created by Juan Diego on 9/4/2022.
//

#include "bidirectional_list.h"
#include "bidirectional_iterator.h"


template<typename T>
T& bidirectional_list<T>::_index_(const index_t &index) const{
    if (index < 0 || index > size()-1){
        throw std::invalid_argument("Invalid operation, index exceeds the number of list elements");
    }
    bidirectional_node<T>* iterable = head;
    for (index_t i=0; i<index; ++i){
        iterable = iterable->next;
    }
    return iterable->data;
}



template<typename T>
bidirectional_list<T>::bidirectional_list()
: nodes(0), head(nullptr), tail(nullptr)
{
}

template<typename T>
bidirectional_list<T>::bidirectional_list(const std::initializer_list<T> &list)
: nodes(0), head(nullptr), tail(nullptr)
{
    for  (const T& element: list){
        this->push_back(element);
    }
}

template<typename T>
bidirectional_list<T>::~bidirectional_list() {
    clear();
}

template<typename T>
bool bidirectional_list<T>::empty() const {
    return head == nullptr;
}

template<typename T>
size_t bidirectional_list<T>::size() const {
    return nodes;
}

template<typename T>
void bidirectional_list<T>::push_front(const T& value) {
    auto* node = new bidirectional_node<T>(value);
    if (empty()){
        head = tail = node;
    } else{
        node->next = head;
        head->prev = node;
        head = node;
    }
    ++nodes;
}

template<typename T>
void bidirectional_list<T>::push_back(const T &value) {
    auto* node = new bidirectional_node<T>(value);
    if (empty()){
        head = tail = node;
    } else{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    ++nodes;
}

template<typename T>
T bidirectional_list<T>::pop_front() {
    T value;
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    } else if (size() == 1){
        value = head->data;
        delete head;
        head = tail = nullptr;
    } else{
        value = head->data;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    --nodes;
    return value;
}

template<typename T>
T bidirectional_list<T>::pop_back() {
    T value;
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    } else if (size() == 1){
        value = tail->data;
        delete tail;
        head = tail = nullptr;
    } else{
        value = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    --nodes;
    return value;
}

template<typename T>
T &bidirectional_list<T>::front() {
    return head->data;
}

template<typename T>
T &bidirectional_list<T>::back() {
    return tail->data;
}

template<typename T>
T bidirectional_list<T>::front() const {
    return head->data;
}

template<typename T>
T bidirectional_list<T>::back() const {
    return tail->data;
}

template<typename T>
T &bidirectional_list<T>::operator[](index_t index) {
    return _index_(index);
}

template<typename T>
T bidirectional_list<T>::operator[](index_t index) const {
    return _index_(index);
}

template<typename T>
void bidirectional_list<T>::clear() {
    while (head != nullptr){
        bidirectional_node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    nodes = 0;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const bidirectional_list<U> &list) {
    for (const U& element: list){
        os << element << " ";
    }
    return os;
}

template<typename T>
typename bidirectional_list<T>::iterator bidirectional_list<T>::begin() {
    return bidirectional_list::iterator(head);
}

template<typename T>
typename bidirectional_list<T>::iterator bidirectional_list<T>::end() {
    return bidirectional_list::iterator(tail->next);
}

template<typename T>
bidirectional_iterator<T>& bidirectional_iterator<T>::operator++() {
    if (current == nullptr){
        throw std::invalid_argument("Invalid operation, the current node is the end of the list");
    }
    current = current->next;
    return (*this);
}

template<typename T>
bidirectional_iterator<T> &bidirectional_iterator<T>::operator--() {
    current = current->prev;
    return (*this);
}

template<typename T>
T &bidirectional_iterator<T>::operator*() {
    return current->data;
}

template<typename T>
T bidirectional_iterator<T>::operator*() const {
    return current->data;
}

template<typename T>
bool bidirectional_iterator<T>::operator==(const bidirectional_iterator<T> &other) const {
    return &current->data == &other.current->data;
}
