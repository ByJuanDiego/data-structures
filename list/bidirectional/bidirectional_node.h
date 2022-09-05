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


template<typename T>
void bidirectional_node<T>::_kill_self_() {
    prev = next = nullptr;
}

template<typename T>
bidirectional_node<T>::bidirectional_node()
: data(T()), next(nullptr), prev(nullptr)
{
}

template<typename T>
bidirectional_node<T>::bidirectional_node(const T &value)
:data(value), next(nullptr), prev(nullptr)
{
}

template<typename T>
bidirectional_node<T>::bidirectional_node(const bidirectional_node<T> *&other)
: data(other->data), next(other->next), prev(other->next)
{
}

template<typename T>
bidirectional_node<T>::~bidirectional_node() {
    _kill_self_();
}


#endif //LIST_BIDIRECTIONAL_NODE_H
