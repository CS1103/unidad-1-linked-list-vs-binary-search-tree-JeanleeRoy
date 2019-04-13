//
// Created by ruben on 4/5/19.
//

#include "BinarySearchTree.h"

UTEC::Nodo::Nodo(const Location& data):data{data}, right{nullptr}, left{nullptr} {}

UTEC::BinarySearchTree::BinarySearchTree():root{nullptr} {}
UTEC::BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

void UTEC::BinarySearchTree::insert(UTEC::Location& data) {
    Nodo* inserted = new Nodo(data);
    if (root == nullptr)
        root = inserted;
    else {
        Nodo* temp = root;
        while (temp != nullptr) {
            if (inserted->data.get_id() > temp->data.get_id()){
                if (temp->right == nullptr){
                    temp->right = inserted;
                    break;
                }
                else if (temp->right != nullptr) temp = temp->right;
            } else
            if (inserted->data.get_id() <= temp->data.get_id()){
                if (temp->left==nullptr){
                    temp->left = inserted;
                    break;
                }
                else if (temp->left != nullptr) temp = temp->left;
            }
        }
    }
}
void UTEC::BinarySearchTree::clear(Nodo* root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}
bool UTEC::BinarySearchTree::is_empty() {
    return (root->right== nullptr)&&(root->left== nullptr);
}
UTEC::Nodo* UTEC::BinarySearchTree::get_root() {
    return root;
}
UTEC::Nodo* UTEC::BinarySearchTree::search(int position_id) {
    Nodo* temp = root;
    while (temp != nullptr) {
        int acomparar = temp->data.get_id();
        if (acomparar == position_id)
            return temp;
        else if (position_id > acomparar)
            temp = temp->right;
        else if (position_id < acomparar)
            temp = temp->left;
        else return nullptr;
    }
}
void UTEC::BinarySearchTree::print() {
    print_nodes(root);
}
//Other functions
void UTEC::load_locations(UTEC::BinarySearchTree *linked_list, std::string file_name) {
    std::ifstream documento(file_name);
    if (documento.is_open()) {
        std::string e[7];
        std::string linea;
        std::getline(documento, linea);
        while (!documento.eof()) {
            std::getline(documento, linea);
            std::istringstream iss(linea);
            unsigned int count = 0;
            while (std::getline(iss, linea, ',')) {
                e[count] = linea;
                count++;
            }
            Location nodeValue(std::stoi(e[0]), e[1], e[2], std::stod(e[3]), std::stod(e[4]), e[5], e[6]);
            linked_list->insert(nodeValue);
        }
    }
}

void UTEC::print_nodes(UTEC::Nodo *root) {
    if (root != nullptr){
        print_nodes(root->left);
        root->data.printLocation();
        print_nodes(root->right);
    }
}