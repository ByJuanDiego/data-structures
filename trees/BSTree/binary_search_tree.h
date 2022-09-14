//
// Created by Juan Diego on 9/8/2022.
//

#ifndef TREES_BINARY_SEARCH_TREE_H
#define TREES_BINARY_SEARCH_TREE_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "binary_node.h"

template <typename T>
class binary_search_tree {

private:

    binary_node<T>* root;

    [[nodiscard]] bool leaf(binary_node<T>* node);
    [[nodiscard]] bool has_right_child(binary_node<T>* node);
    [[nodiscard]] bool has_left_child(binary_node<T>* node);

    void _insert(T value, binary_node<T>* & node);
    void _remove(T value, binary_node<T>* & node);
    bool _search(T value, binary_node<T>* node) const;
    T _find(T value, binary_node<T>* node) const;

    binary_node<T>* _min_node_ptr(binary_node<T>* node);
    binary_node<T>* _max_node_ptr(binary_node<T>* node);

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
    void remove(T value);

    [[nodiscard]] bool search(T value) const;
    [[nodiscard]] T find(T value) const;

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
bool binary_search_tree<T>::leaf(binary_node<T>* node) {
    return ((node->right == nullptr) && (node->left == nullptr));
}

template<typename T>
bool binary_search_tree<T>::has_right_child(binary_node<T>* node) {
    return (node->right != nullptr);
}

template<typename T>
bool binary_search_tree<T>::has_left_child(binary_node<T>* node) {
    return (node->left != nullptr);
}

template<typename T>
void binary_search_tree<T>::_insert(T value, binary_node<T>* & node) {
    if (node == nullptr){
        node = new binary_node<T>(value);
        return;
    }

    if (!has_right_child(node)){
        if (value > node->data){
            node->right = new binary_node<T>(value);
            return;
        }
    } else if (!has_left_child(node)){
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
void binary_search_tree<T>::_remove(T value, binary_node<T>* & node) {
    if (node == nullptr){
        throw std::invalid_argument(
            "Invalid operation, the pointer is nullptr\n"
            "(probably the element to remove is not in the BST or it's empty)"
        );
    }

    if (node->data > value){
        _remove(value, node->left);
    } else if (node->data < value){
        _remove(value, node->right);
    } else {
        // Value was found

        // Evaluate how many children the node has
        if (leaf(node)){// If the node don't have any children
            delete node;
            node = nullptr;
        } else if (has_right_child(node) && !has_left_child(node)){// One right children
            binary_node<T>* temp = node;
            node = node->right;
            delete temp;
        } else if (has_left_child(node) && !has_right_child(node)) {// One left children
            binary_node<T>* temp = node;
            node = node->left;
            delete temp;
        } else {// Two children
            binary_node<T>* min_node_ptr = _min_node_ptr(node->right); // find the min in right
            T data = min_node_ptr->data;
            min_node_ptr->data = node->data;
            node->data = data;
            // Delete the duplicate from right-subtree
            _remove(value, node->right);
        }
    }
}

template<typename T>
bool binary_search_tree<T>::_search(T value, binary_node<T>* node) const{
    if (node == nullptr){
        return false;
    } else if (node->data == value){
        return true;
    } else if (value > node->data){
        return _search(value, node->right);
    } else if (value < node->data){
        return _search(value, node->left);
    }
    return false;
}

template<typename T>
T binary_search_tree<T>::_find(T value, binary_node<T>* node) const{
    if (node == nullptr){
        throw std::invalid_argument("Invalid operation, the node points to nullptr");
    } else if (node->data == value){
        return node->data;
    } else if (value > node->data){
        return _find(value, node->right);
    } else if (value < node->data){
        return _find(value, node->left);
    }
    throw std::invalid_argument("something went wrong while searching for an item");
}

template<typename T>
binary_node<T> *binary_search_tree<T>::_min_node_ptr(binary_node<T>* node) {
    if (!has_left_child(node)){
        return node;
    }
    return _min_node_ptr(node->left);
}

template<typename T>
binary_node<T> *binary_search_tree<T>::_max_node_ptr(binary_node<T>* node) {
    if (!has_right_child(node)){
        return node;
    }
    return _max_node_ptr(node->right);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::_preorder(binary_node<T>* node, const Function& process)
{// root - left - right,
    if (node == nullptr) {
        return;
    }
    process(node->data);
    _preorder(node->left, process);
    _preorder(node->right, process);
}

template<typename T>
template<typename Function>
void binary_search_tree<T>::_postorder(binary_node<T>* node, const Function& process)
{// left - right - root, recorre de abajo hacia arriba
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
// left - root - right
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
void binary_search_tree<T>::remove(T value) {
    _remove(value, root);
}

template<typename T>
bool binary_search_tree<T>::search(T value) const {
    return _search(value, root);
}

template<typename T>
T binary_search_tree<T>::find(T value) const {
    return _find(value, root);
}

template<typename T>
T binary_search_tree<T>::min() {
    binary_node<T>* node = _min_node_ptr(root);
    return node->data;
}

template<typename T>
T binary_search_tree<T>::max() {
    binary_node<T>* node = _max_node_ptr(root);
    return node->data;
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
