//
// Created by Juan Diego on 9/2/2022.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H


template <typename T>
struct node {

private:

    void _kill_self_();

public:
    node<T>* prev;
    node<T>* next;
    T data;

    node();
    ~node();
    explicit node(const T& value);

};



#endif //LIST_NODE_H
