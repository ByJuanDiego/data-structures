//
// Created by Juan Diego on 9/4/2022.
//

#ifndef LIST_BIDIRECTIONAL_ITERATOR_H
#define LIST_BIDIRECTIONAL_ITERATOR_H

template <typename T>
class bidirectional_node;

template <typename T>
class bidirectional_iterator {

private:

    bidirectional_node<T>* current;

public:

    bidirectional_iterator();
    explicit bidirectional_iterator(bidirectional_node<T>* node);
    bidirectional_iterator(const bidirectional_iterator<T>& other);

    bidirectional_iterator<T>& operator++();
    bidirectional_iterator<T>& operator--();
    bidirectional_iterator<T> operator++(int);
    bidirectional_iterator<T> operator--(int);

    [[nodiscard]] T& operator*();
    [[nodiscard]] T operator*() const;

    bool operator == (const bidirectional_iterator<T>& other) const;
    bool operator != (const bidirectional_iterator<T>& other) const;

};


#endif //LIST_BIDIRECTIONAL_ITERATOR_H
