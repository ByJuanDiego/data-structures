//
// Created by Juan Diego on 9/4/2022.
//

#ifndef LIST_BIDIRECTIONAL_NODE_H
#define LIST_BIDIRECTIONAL_NODE_H


template<typename T>
struct bidirectional_node {

private:

    void _kill_self_();

public:

    T data;
    bidirectional_node<T>* prev;
    bidirectional_node<T>* next;

    bidirectional_node();
    explicit bidirectional_node(const T& value);
    explicit bidirectional_node(const bidirectional_node<T>*& other);

    ~bidirectional_node();

};



#endif //LIST_BIDIRECTIONAL_NODE_H
