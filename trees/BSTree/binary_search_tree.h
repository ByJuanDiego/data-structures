//
// Created by Juan Diego on 9/8/2022.
//

#ifndef TREES_BINARY_SEARCH_TREE_H
#define TREES_BINARY_SEARCH_TREE_H

#include <initializer_list>
#include <algorithm>
#include "binary_node.h"

template <typename T>
class binary_search_tree {

private:

    binary_node<T>* root;

    void _insert(T value, binary_node<T>* & node);
    bool _search(T value, binary_node<T>* node) const;

    T _min(binary_node<T>* node);
    T _max(binary_node<T>* node);

    template <typename Function>
    void _preorder(binary_node<T>* node, const Function& process);

    template<typename Function>
    void _postorder(binary_node<T>* node, const Function& process);

    template<typename Function>
    void _inorder(binary_node<T>* node, const Function& process);

public:

    binary_search_tree();
    binary_search_tree(std::initializer_list<T> list);

    void insert(T value);
    [[nodiscard]] bool search(T value) const;

    [[nodiscard]] T min();
    [[nodiscard]] T max();

    template <typename Function>
    void preorder(const Function& process);

    template<typename Function>
    void postorder(const Function& process);

    template<typename Function>
    void inorder(const Function& process);

};

template<typename T>
binary_search_tree<T>::binary_search_tree()
: root(nullptr)
{
}

template<typename T>
binary_search_tree<T>::binary_search_tree(std::initializer_list<T> list):
binary_search_tree()
{
    for (T element: list){
        this->_insert(element, root);
    }
}

template<typename T>
void binary_search_tree<T>::_insert(T value, binary_node<T>* & node) {
    if (node == nullptr){
        node = new binary_node<T>(value);
        return;
    }

    if (node->right == nullptr){
        if (value > node->data){
            node->right = new binary_node<T>(value);
            return;
        }
    } else if (node->left == nullptr){
        if (value < node->data){
            node->left = new binary_node<T>(value);
            return;
        }
    }

    if (value > node->data){
        _insert(value, node->right);
    } else if (value < node->data){
        _insert(value, node->left);
    }
}

template<typename T>
bool binary_search_tree<T>::_search(T value, binary_node<T>* node) const{
    if (node == nullptr){
        return false;
    } else if (value > node->data){
        return _search(value, node->right);
    } else if (value < node->data){
        return _search(value, node->left);
    }
    return true;
}

template<typename T>
T binary_search_tree<T>::_min(binary_node<T>* node) {
    if (node->left == nullptr){
        return node->data;
    }
    return _min(node->left);
}

template<typename T>
T binary_search_tree<T>::_max(binary_node<T> *node) {
    if (node->right == nullptr){
        return node->data;
    }
    return _max(node->right);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::_preorder(binary_node<T>* node, const Function& process) {
    if (node == nullptr) {
        return;
    }
    process(node->data);
    _preorder(node->left, process);
    _preorder(node->right, process);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::_postorder(binary_node<T>* node, const Function& process) {
    if (node == nullptr){
        return;
    }
    _postorder(node->left, process);
    _postorder(node->right, process);
    process(node->data);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::_inorder(binary_node<T>* node, const Function& process) {
    if (node == nullptr){
        return;
    }
    _inorder(node->left, process);
    process(node->data);
    _inorder(node->right, process);
}

template<typename T>
void binary_search_tree<T>::insert(T value) {
    _insert(value, root);
}

template<typename T>
bool binary_search_tree<T>::search(T value) const {
    return _search(value, root);
}

template<typename T>
T binary_search_tree<T>::min() {
    return _min(root);
}

template<typename T>
T binary_search_tree<T>::max() {
    return _min(root);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::preorder(const Function &process) {
    _preorder(root, process);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::postorder(const Function &process) {
    _postorder(root, process);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::inorder(const Function &process) {
    _inorder(root, process);
}


#endif //TREES_BINARY_SEARCH_TREE_H
