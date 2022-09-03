//
// Created by Juan Diego on 9/2/2022.
//

#include "forward_list.h"
#include <stdexcept>

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
    if (empty()) {
        return true;
    }
    node<T>* iterable = head;
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
    auto* nodo = new node<T>(value);
    if (empty()){
        head = tail = nodo;
    } else{
        nodo->next = head;
        head = nodo;
    }
    ++nodes;
}

template<typename T>
void forward_list<T>::push_back(const T &value) {
    auto* nodo = new node<T>(value);
    if (empty()){
        head = tail = nodo;
    } else{
        tail->next = nodo;
        tail = nodo;
    }
    ++nodes;
}

template<typename T>
T forward_list<T>::pop_front() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    }
    T value = head->data;
    node<T>* nodo = head;
    head = head->next;
    nodo->kill_self();
    --nodes;
    return value;
}

template<typename T>
T forward_list<T>::pop_back() {
    if (empty()){
        throw std::invalid_argument("Invalid operation, empty list");
    } else if (size() == 1){
        T value = tail->data;
        tail->kill_self();
        --nodes;
        return value;
    } else{
        T value = tail->data;
        node<T>* iterable = head;
        while (iterable->next != tail){
            iterable = iterable->next;
        }
        tail->kill_self();
        tail = iterable;
        tail->next = nullptr;
        --nodes;
        return value;
    }
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
void forward_list<T>::clear() {
    while (head != nullptr){
        node<T>* temp = head;
        head = head->next;
        temp->kill_self();
    }
    nodes = 0;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const forward_list<U> &list) {
    node<U>* iterable = list.head;
    while (iterable != nullptr){
        os << iterable->data << " ";
        iterable = iterable->next;
    }
    return os;
}
