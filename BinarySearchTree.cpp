//
// Created by ruben on 4/5/19.
//

#include "BinarySearchTree.h"

UTEC::Nodo::Nodo(const Location& data):data{data}, right{nullptr}, left{nullptr} {}

UTEC::BinarySearchTree::BinarySearchTree():root{nullptr} {}

void UTEC::BinarySearchTree::insert(UTEC::Location data) {
    Nodo* temp = new Nodo(data);
    if ((root->right==nullptr)&&(root->left== nullptr)){
        root->right = temp;
        root->left = temp;
    } else if (root->right->data.get_id()>temp->data.get_id()){
        
    }
}
