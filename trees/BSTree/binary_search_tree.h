//
// Created by Juan Diego on 9/8/2022.
//

#ifndef TREES_BINARY_SEARCH_TREE_H
#define TREES_BINARY_SEARCH_TREE_H

#include <iostream>
#include "binary_search_node.h"
using std::cout;


template <typename T>
class binary_search_tree {

private:

    binary_search_node<T>* root;

public:

    binary_search_tree();

    void insert(T value, binary_search_node<T>* node);
    [[nodiscard]] bool search(T value, binary_search_node<T>* node) const;

    [[nodiscard]] T min(binary_search_node<T>* node);
    [[nodiscard]] T max(binary_search_node<T>* node);

    template<typename Function>
    void preorder(binary_search_node<T>* node);
    void postorder(binary_search_node<T>* node);
    void inorder(binary_search_tree<T>* node);

};

template<typename T>
binary_search_tree<T>::binary_search_tree()
: root(nullptr)
{
}

template<typename T>
void binary_search_tree<T>::insert(T value, binary_search_node<T>* node) {
    if (node == nullptr){
        return;
    }

    if (node->right == nullptr){
        if (value > node->data){
            node->right = new binary_search_node<T>(value);
            return;
        }
    } else if (node->left == nullptr){
        if (value < node->data){
            node->left = new binary_search_node<T>(value);
            return;
        }
    }

    if (value > node->data){
        insert(value, node->right);
    } else if (value < node->data){
        insert(value, node->left);
    }
}

template<typename T>
bool binary_search_tree<T>::search(T value, binary_search_node<T>* node) const{
    if (node == nullptr){
        return false;
    } else if (value > node->data){
        return search(value, node->right);
    } else if (value < node->data){
        return search(value, node->left);
    }
    return true;
}

template<typename T>
T binary_search_tree<T>::min(binary_search_node<T>* node) {
    if (node->left == nullptr){
        return node->data;
    }
    return min(node->left);
}

template<typename T>
T binary_search_tree<T>::max(binary_search_node<T> *node) {
    if (node->right == nullptr){
        return node->data;
    }
    return max(node->right);
}

template<typename T>
void binary_search_tree<T>::preorder(binary_search_node<T>* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

template<typename T>
void binary_search_tree<T>::postorder(binary_search_node<T>* node) {
    if (node == nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

template<typename T>
void binary_search_tree<T>::inorder(binary_search_tree<T>* node) {
    if (node == nullptr){
        return;
    }
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}


#endif //TREES_BINARY_SEARCH_TREE_H
