//
// Created by Juan Diego on 9/2/2022.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H


template <typename T>
struct node {
    node<T>* prev;
    node<T>* next;
    T data;

    node();
    explicit node(const T& value);
    void kill_self();
};



#endif //LIST_NODE_H
