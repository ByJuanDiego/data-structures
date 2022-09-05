//
// Created by Juan Diego on 9/4/2022.
//

#ifndef LIST_BIDIRECTIONAL_LIST_H
#define LIST_BIDIRECTIONAL_LIST_H

#include <initializer_list>
#include "bidirectional_iterator.h"

using index_t = ssize_t;

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
    void reverse();                                                                        // O(n)
    void insert(const T& value, const index_t& index);                                     // O(n)

    template<typename U>
    friend std::ostream& operator<< (std::ostream& os, const bidirectional_list<U>& list); // O(n)

    iterator begin();                                                                      // O(1)
    iterator end();                                                                        // O(1)

    // Ejercicios
    [[nodiscard]] bidirectional_list<T> sorted_join(const bidirectional_list<T>& other);    // O(n)
    [[nodiscard]] bool is_palindrome() const;                                               // O(n)
    void sorted_insert(const T& value);                                                     // O(n)

};


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
    for (const T& element: list){
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

template<typename T>
void bidirectional_list<T>::reverse() {
    if (size() > 1){
        bidirectional_node<T>* front_node = head;
        bidirectional_node<T>* back_node = tail;
        for (index_t i=0; i<size()/2; ++i){
            T temp = front_node->data;
            front_node->data = back_node->data;
            back_node->data = temp;
            front_node = front_node->next;
            back_node = back_node->prev;
        }
    }
}

template<typename T>
void bidirectional_list<T>::insert(const T& value, const index_t & index) {
    if (index < 0 || index > size()){
        throw std::invalid_argument("Invalid operation, index out of range");
    } else if (index == 0){
        push_front(value);
    } else if (index == size()){
        push_back(value);
    } else{
        auto* node = new bidirectional_node<T>(value);
        bidirectional_node<T>* iterable = head;
        for (index_t i=0; i<index; ++i){
            iterable = iterable->next;
        }
        iterable->prev->next = node;
        node->prev = iterable->prev;
        node->next = iterable;
        iterable->prev = node;
        ++nodes;
    }
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
bool bidirectional_list<T>::is_palindrome() const {
    std::string word;
    std::string reverse_word;
    for (index_t i=0; i<size(); ++i){
        word+= std::to_string((*this)[i]);
        reverse_word+=std::to_string((*this)[size()-1-i]);
    }
    return (word == reverse_word);
}

template<typename T>
void bidirectional_list<T>::sorted_insert(const T &value) {
    auto* node = new bidirectional_node<T>(value);
    if (empty()){
        head = tail = node;
    } else if (size() == 1){
        (head->data > node->data)? (this->push_front(value)):(this->push_back(value));
    } else {
        bidirectional_node<T>* iterable = head;
        while (iterable->next != nullptr){
            if (iterable->data > node->data){
                iterable->prev->next = node;
                node->prev = iterable->prev;
                node->next = iterable;
                iterable->prev = node;
                break;
            }
            iterable = iterable->next;
        }
    }
    ++nodes;
}

template<typename T>
bidirectional_list<T> bidirectional_list<T>::sorted_join(const bidirectional_list<T> &other) {
    bidirectional_list<T> result;
    bidirectional_node<T>* node1 = this->head;
    bidirectional_node<T>* node2 = other.head;

    while (node1 != nullptr || node2 != nullptr) {
        if (node1 != nullptr && node2 != nullptr)
        {// Si ambas listas aún tienen elementos por recorrer se busca al menor para agregarlo a la lista
            result.push_back((node1->data < node2->data) ? (node1->data) : (node2->data));
            (node1->data < node2->data) ? (node1 = node1->next) : (node2 = node2->next);
        } else
        {// Si alguno de los heads de las 2 listas es NULL, se asigna directamente el valor de la lista que aún falta recorrer
            result.push_back((node1 == nullptr) ? (node2->data) : (node1->data));
            (node1 == nullptr) ? (node2 = node2->next) : (node1 = node1->next);
        }
    }
    return result;
}


#endif //LIST_BIDIRECTIONAL_LIST_H
