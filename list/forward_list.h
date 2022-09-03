//
// Created by Juan Diego on 9/2/2022.
//

#ifndef LIST_FORWARD_LIST_H
#define LIST_FORWARD_LIST_H

#include "node.cpp"
#include <cstdlib>

template <typename T>
class forward_list {

private:

    node<T>* head;
    node<T>* tail;
    size_t nodes;

public:

    forward_list();
    ~forward_list();
    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;
    void push_front(const T& value);
    T pop_front();
    [[nodiscard]] T& front();
    [[nodiscard]] T& back();
};


#endif //LIST_FORWARD_LIST_H
