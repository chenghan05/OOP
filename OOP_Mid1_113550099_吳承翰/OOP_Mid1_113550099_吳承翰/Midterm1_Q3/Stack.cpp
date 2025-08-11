#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

Stack::Stack(int _capacity) : capacity(_capacity), os(nullptr) {
    // TODO: Initialize the stack (allocate memory and set top index to -1)
    m_data = new int[capacity];
    top = -1;
}

Stack::Stack(int _capacity, ofstream* _os) : capacity(_capacity), os(_os) {
    // TODO: Initialize the stack (allocate memory and set top index to -1)
    m_data = new int[capacity];
    top = -1;
}

void Stack::push(int x) {
    // TODO: Add the element x to the top of the stack if it is not full.
    if (!isFull(ONLY_STACK)) {
        top++;
        m_data[top] = x;
    }
}

void Stack::pop(int &x) {
    // TODO: Remove the top element from the stack and store it in x if it's not empty. Return -1 if the stack is empty.
    if (isEmpty(ONLY_STACK)) {
        x = -1;
    }
    else {
        getTopValue(x);
        top--;
    }
}

bool Stack::isEmpty(Type type) {
    // Return true if the stack is empty. Only print "The stack is Empty." with the type 'ONLY_STACK'.

    bool result = (size() <= 0);
    if(result && type == ONLY_STACK) {
        *os << "The stack is Empty.\n";
    }

    return result;
}

bool Stack::isFull(Type type) {
    // TODO: Return true if the stack is full. Only print "The stack is Full." with the type 'ONLY_STACK'.
    bool result = (size() >= capacity);
    if (result && type == ONLY_STACK) {
        *os << "The stack is Full.\n";
    }

    return result;
}

void Stack::getTopValue(int &x) {
    // Retrieve the top element of the stack without removing it. Return -1 if the stack is empty.

    x = (isEmpty(ONLY_STACK)) ? -1 : m_data[top];
}

int Stack::size() {
    // Return the current number of elements in the stack
    return top + 1;
}

void Stack::print() {

    if (!isEmpty(ONLY_STACK)) {
        for (int i = top; i >= 0; --i) {
            *os << m_data[i] << ' ';
        }
        *os << '\n';
    }
}