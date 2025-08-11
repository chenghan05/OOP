#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <fstream>

using namespace std;
enum Type {
    ONLY_STACK, BOTH
};
class Stack {
    private:
        int* m_data;
        int top;
        int capacity;
        ofstream* os;
    public:
        Stack() {
            top = -1;
            m_data = nullptr;
            os = nullptr;
        }
        Stack(int _capacity);
        Stack(int _capacity, ofstream* _os);
        void push(int x);
        void pop(int &x);
        bool isEmpty(Type type);
        bool isFull(Type type);
        void getTopValue(int &x);
        int size();
        void print();
};

#endif