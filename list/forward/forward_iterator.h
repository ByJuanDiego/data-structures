//
// Created by Juan Diego on 9/3/2022.
//

#ifndef LIST_FORWARD_ITERATOR_H
#define LIST_FORWARD_ITERATOR_H

template <typename T>
class node;

template <typename T>
class forward_iterator {
private:

    node<T>* current;

public:

    forward_iterator();
    explicit forward_iterator(node<T>* nodo);
    forward_iterator(const forward_iterator<T>& other);

    forward_iterator<T>& operator++();
    forward_iterator<T> operator++(int);

    bool operator== (const forward_iterator<T>& other) const;
    bool operator!= (const forward_iterator<T>& other) const;

    [[nodiscard]] T operator*() const;
    [[nodiscard]] T& operator*();
};



#endif //LIST_FORWARD_ITERATOR_H
