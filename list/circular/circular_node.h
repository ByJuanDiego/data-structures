//
// Created by Juan Diego on 9/7/2022.
//

#ifndef LIST_CIRCULAR_NODE_H
#define LIST_CIRCULAR_NODE_H


template<typename T>
struct circular_node{

private:

    void _kill_self_();

public:

    T data;
    circular_node<T>* prev;
    circular_node<T>* next;

    circular_node();
    explicit circular_node(const T& data);
    circular_node(const circular_node<T>& other);

    ~circular_node();
};


template<typename T>
void circular_node<T>::_kill_self_() {
    next = prev = nullptr;
}

template<typename T>
circular_node<T>::circular_node()
: next(this), prev(this), data(T())
{
}

template<typename T>
circular_node<T>::circular_node(const T &data)
: next(nullptr), prev(nullptr), data(data)
{
}

template<typename T>
circular_node<T>::circular_node(const circular_node<T> &other)
: next(other.next), prev(other.prev), data(other.data)
{
}

template<typename T>
circular_node<T>::~circular_node() {
    _kill_self_();
}



#endif //LIST_CIRCULAR_NODE_H
