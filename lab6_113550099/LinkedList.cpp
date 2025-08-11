#include <iostream>

#include "LinkedList.h"

using namespace std;


LinkedList::~LinkedList() {
    //  TODO: Implement deconstructor
    clear();
}


void LinkedList::insertNode(int _value) {
    //  TODO: Insert a new node with the given value at the end of the linked list
    Node* newnode = new Node(_value, nullptr);
    if (head == nullptr) {
        head = newnode;
        tail = head;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void LinkedList::insertedSort(int _value) {
    //  TODO: Insert a new node in sorted order
    Node* newnode = new Node(_value, nullptr);
    if (head == nullptr) {
        head = newnode;
        tail = head;
        return;
    }

    Node* pre= head;
    Node* node = head->next;

    if (_value < head->value){
        newnode->next = head;
        head = newnode;
        return;
    }

    while (_value > node->value && node->next != nullptr) {
        pre = node;
        node = node->next;
    }

    if (_value > node->value && node->next == nullptr) {
        node->next = newnode;
        tail = newnode;
    }
    else if (_value <= node->value) {
        pre->next = newnode;
        newnode->next = node;
    }
    else {
        cout << "wrong insertedsoort happen!\n";
    }
}

void LinkedList::sort() {
    //  TODO: Sort the entire linked list in ascending order using insertion sort
    //  Hint: use function insertedNode()
    if (head == nullptr)return;
    Node* pre = head;
    Node* node = head->next;

    while (node != nullptr) {
        if (node->value < pre->value) {
            Node* temp = node;
            pre->next = node->next;
            insertedSort(node->value);
            node = pre->next;
            delete temp;
        }
        else {
            pre = node;
            node = node->next;
        }
    }
    tail = pre;
}

void LinkedList::clear() {
    //  TODO: Delete all nodes and reset the linked list
    Node* node = head;
    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

bool LinkedList::deleteNode(int _value) {
    //  TODO: Implement this function to delete the node with the specified value from the linked list
    if (head == nullptr)return 0;
    bool de = false;
    Node* pre = head;
    Node* node = head;

    while(head != nullptr && _value == node->value) {
        if(head == tail) tail = head->next;
        head = head->next;
        delete node;
        node = head;
        de = true;
    }
    if(de)return de;

    node = head->next;

    while (node != nullptr) {
        if (_value == node->value) {
            de = true;
            if (node == tail) {
                tail = pre;
            }
            pre->next = node->next;
            Node* temp = node;
            delete temp;
            node = pre->next;
        }
        else {
            pre = pre->next;
            node = node->next;
        }
    }
    return de;
}

void LinkedList::mergeLinkedList(LinkedList &linkedList2) {
    //  TODO: Implement this function to merge another linked list into this linked list
    if (linkedList2.head == nullptr)return;
    Node* node1 = head;
    Node* node2 = linkedList2.head;
    if (head == nullptr){
        while (node2) {
            insertNode(node2->value);
            node2 = node2->next;
        }
        return;
    }
    while (node1 && node2) {
        if (node1->value < node2->value) {
            node1 = node1->next;
        }
        else {
            insertedSort(node2->value);
            node2 = node2->next;
        }
    }
    while (node2) {
        insertedSort(node2->value);
        node2 = node2->next;
    }
}

void LinkedList::printLinkedList(ofstream& out) {
    //  TODO: Print all values in the linked list to the output stream
    //  Note: If the linked-list is empty, output "The List is Empty.\n"
    Node* node = head;
    if (!head) {
        //cout << "The List is Empty.\n";
        out << "The List is Empty.\n";
        return;
    }
    else {
        while (node != nullptr) {
            if (node != head) {
                //cout << " -> ";
                out << " -> ";
            }
            //cout << node->value;
            out << node->value;
            node = node->next;
        }
        //cout << "\n";
        out << "\n";
    }
}
