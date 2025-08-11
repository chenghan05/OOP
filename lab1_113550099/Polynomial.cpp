#include "Polynomial.h"
#include <iostream>

using namespace std;

void Polynomial::print(){
    int first = 0;
    for (int i = 4; i >= 0; i--) {
        if (m_data[i] > 0) {
            if(first)cout << "+";
        }
        if (m_data[i] != 0) {
            first = 1;
            if (i == 0) {
                cout << m_data[i];
            }
            else {
                if (m_data[i] > 1 || m_data[i] < -1) {
                    cout << m_data[i];
                }
                cout << "x";
                if (i > 1)cout << "^" << i;
            }
        }
    }
    if (!first)cout << 0;
    cout << endl;
    /*
     *  TODO: Print the polynomial.
     */
}

void Polynomial::add(Polynomial poly){
    for (int i = 0; i < 3; i++) {
        this->m_data[i] += poly.m_data[i];
    }
    this->print();
    /*
     *  TODO: Add two polynomial and print the result.
     */
}

void Polynomial::multiple(Polynomial poly){
    int temp[5] = {0,0,0,0,0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i + j] += this->m_data[i] * poly.m_data[j];
        }
    }
    for (int i = 0; i < 5; i++) {
        this->m_data[i] = temp[i];
    }
    this->print();
    /*
     *  TODO: Multiply two polynomial and print the result.
     */
}