//
// Created by Juan Diego on 9/4/2022.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "../array/circular_array.h"

template<typename T>
class stack {

private:

    circular_array<T> data;

public:

    stack() = default;                           // O(1)
    stack(const std::initializer_list<T>& list); // O(n)
    ~stack() = default;                          // O(1)
    [[nodiscard]] bool empty();                  // O(1)
    [[nodiscard]] size_t size();                 // O(1)
    void push(const T& value);                   // O(1)
    void pop();                                  // O(1)
    [[nodiscard]] T top();                       // O(1)

};

template<typename T>
stack<T>::stack(const std::initializer_list<T> &list) {
    for (const T& value : list){
        data.push_front(value);
    }
}

template<typename T>
bool stack<T>::empty() {
    return data.empty();
}

template<typename T>
size_t stack<T>::size() {
    return data.size();
}

template<typename T>
void stack<T>::push(const T &value) {
    data.push_front(value);
}

template<typename T>
void stack<T>::pop() {
    data.pop_front();
}

template<typename T>
T stack<T>::top() {
    return data[0];
}


#endif //STACK_STACK_H
