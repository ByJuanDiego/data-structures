//
// Created by Juan Diego on 9/2/2022.
//

#include "forward_list.h"
#include "forward_iterator.h"

#include <stdexcept>


template<typename T>
void forward_list<T>::_swap_(forward_node<T> *&a, forward_node<T> *&b) {
    T temp = a->data;
    a->data = b->data;
    b->data = temp;
}

template<typename T>
T &forward_list<T>::_index_(const index_t &index) const{
    if ((index > size()-1) || index < 0){
        throw std::invalid_argument("Invalid argument, index out of range");
    }
    forward_node<T>* iterable = head;
    for (index_t i=0; i<index; ++i){
        iterable = iterable->next;
    }
    return iterable->data;
}

template<typename T>
forward_list<T>::forward_list()
: nodes(0), head(nullptr), tail(nullptr)
{
}

template<typename T>
forward_list<T>::forward_list(const std::initializer_list<T> &list, const bool& push_front)
: nodes(0), head(nullptr), tail(nullptr)
{
    for (const T& element: list){
        (push_front)? this->push_front(element) : this->push_back(element);
    }
}

template<typename T>
forward_list<T>::~forward_list(){
    clear();
}

template<typename T>
size_t forward_list<T>::size() const {
    return nodes;
}

template<typename T>
bool forward_list<T>::empty() const {
    return (size() == 0);
}

template<typename T>
bool forward_list<T>::sorted() const {
    if (empty() || size() == 1) {
        return true;
    }
    forward_node<T>* iterable = head;
    while (iterable->next != nullptr){
        if (iterable->data > iterable->next->data){
            return false;
        }
        iterable = iterable->next;
    }
    return true;
}

template<typename T>
void forward_list<T>::push_front(const T& value) {
    auto* node = new forward_node<T>(value);
    if (empty()){
        head = tail = node;
    } else{
        node->next = head;
        head = node;
    }
    ++nodes;
}

template<typename T>
void forward_list<T>::push_back(const T &value) {
    auto* node = new forward_node<T>(value);
    if (empty()){
        head = tail = node;
    } else{
        tail->next = node;
        tail = node;
    }
    ++nodes;
}

template<typename T>
T forward_list<T>::pop_front() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    }
    T value = head->data;
    forward_node<T>* node = head;
    head = head->next;
    delete node;
    --nodes;
    return value;
}

template<typename T>
T forward_list<T>::pop_back() {
    T value;
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    } else if (size() == 1){
        value = tail->data;
        delete tail;
        tail = head = nullptr;
    } else{
        value = tail->data;
        forward_node<T>* iterable = head;
        while (iterable->next != tail){
            iterable = iterable->next;
        }
        delete tail;
        tail = iterable;
        tail->next = nullptr;
    }
    --nodes;
    return value;
}

template<typename T>
T &forward_list<T>::front() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    }
    return head->data;
}

template<typename T>
T &forward_list<T>::back() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    }
    return tail->data;
}

template<typename T>
T forward_list<T>::front() const {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    }
    return head->data;
}

template<typename T>
T forward_list<T>::back() const {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    }
    return tail->data;
}

template<typename T>
T &forward_list<T>::operator[](const index_t &index) {
    return _index_(index);
}

template<typename T>
T forward_list<T>::operator[](const index_t &index) const {
    return _index_(index);
}

template<typename T>
void forward_list<T>::sort(){
    if (empty() || size()==1){
        return;
    }
    forward_node<T>* current_node = head;
    while (!sorted()){
        forward_node<T>* current_minimum = current_node;
        forward_node<T>* current_item = current_node;

        while (current_item != nullptr){
            if (current_item->data < current_minimum->data){
                current_minimum = current_item;
            }
            current_item = current_item->next;
        }

        _swap_(current_node, current_minimum);
        current_node = current_node->next;
    }
}

template<typename T>
void forward_list<T>::clear() {
    while (head != nullptr){
        forward_node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    nodes = 0;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const forward_list<U> &list) {
    forward_node<U>* iterable = list.head;
    while (iterable != nullptr){
        os << iterable->data << " ";
        iterable = iterable->next;
    }
    return os;
}

template<typename T>
typename forward_list<T>::iterator forward_list<T>::begin() {
    return forward_iterator(head);
}

template<typename T>
typename forward_list<T>::iterator forward_list<T>::end() {
    return forward_iterator(tail->next);
}

template<typename T>
T forward_iterator<T>::operator*() const {
    return current->data;
}

template<typename T>
T &forward_iterator<T>::operator*() {
    return current->data;
}

template<typename T>
forward_iterator<T> &forward_iterator<T>::operator++() {
    if (current == nullptr){
        throw std::invalid_argument("Invalid operation, the current node is the end of the list");
    }
    this->current = current->next;
    return *this;
}

template<typename T>
bool forward_iterator<T>::operator==(const forward_iterator<T> &other) const {
    return &current->data == &other.current->data;
}
