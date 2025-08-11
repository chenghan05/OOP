#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int _value, Node* _next) : value(_value), next(_next) {}
};

class LinkedList {
    private:
        Node *head, *tail;

    public:
        LinkedList() : head(nullptr), tail(nullptr) {}
        ~LinkedList();
        void insertNode(int _value);
        void insertedSort(int _value);
        void sort();
        void clear();
        bool deleteNode(int _value);
        void mergeLinkedList(LinkedList &linkedList2);
        void printLinkedList(ofstream& out);
};


#endif