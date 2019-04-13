//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"

UTEC::Node::Node(const Location & data):data{data}, right{nullptr}, left{nullptr}{}

UTEC::LinkedList::LinkedList():head{nullptr}, tail{nullptr}{};
UTEC::LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp->right != nullptr){
        delete temp;
        temp = temp->right;
    } //std::cout<<"Destruyndo Nodo... ";
    delete temp;
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->right;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node *UTEC::LinkedList::get_head() {return head;}

UTEC::Node *UTEC::LinkedList::get_tail() { return tail;}

void UTEC::LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->right = head;
        head->left = temp;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->right = temp;
        temp->left=tail;
        tail = temp;
    }
}
void UTEC::LinkedList::print(){
    if (is_empty())std::cout<<"La lista esta vacia"<<std::endl;
    else {
        Node* temp = head;
        while (temp != tail){
            temp->data.printLocation();
            temp = temp->right;
        }
        delete temp;
    }
}
void UTEC::LinkedList::insert(int position, const Location &data) {
    Node* inserted = new Node(data);
    Node* temp = head;
    for (int i = 1; i < position; ++i) {
        temp = temp->right;
    }
    inserted->left = temp;
    inserted->right = temp->right;
    temp->right = inserted;

}

void UTEC::LinkedList::search(int position_id) {
    Node *temp = head;
    while (temp->data.get_id() != position_id) {
        temp = temp->right;
    }
    if (temp->right == nullptr) {
        std::cout << "No se encontro ninguna coicidencia en la lista" << std::endl;
    } else {
        temp->data.printLocation();
    }
}