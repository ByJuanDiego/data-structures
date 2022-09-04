//
// Created by Juan Diego on 9/2/2022.
//

#ifndef LIST_FORWARD_NODE_H
#define LIST_FORWARD_NODE_H


template <typename T>
struct forward_node {

private:

    void _kill_self_();

public:

    forward_node<T>* next;
    T data;

    forward_node();
    ~forward_node();
    explicit forward_node(const T& value);

};



#endif //LIST_FORWARD_NODE_H
