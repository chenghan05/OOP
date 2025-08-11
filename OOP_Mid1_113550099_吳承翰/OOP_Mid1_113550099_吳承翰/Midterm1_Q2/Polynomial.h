#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define SIZE 11

#include <iostream>
#include <vector>

using namespace std;


class Polynomial {
    private:
        vector<int> m_data;
    public:
        Polynomial();
        Polynomial(const vector<int>& coeffs);
        
        Polynomial operator*(const Polynomial&) const; // TODO 
        Polynomial operator+(const Polynomial&) const; // TODO
        Polynomial operator-(const Polynomial&) const; // TODO
        
        friend ostream& operator<<(ostream& out, const Polynomial& p); // TODO

        vector<int>& getData() { return m_data; }
    };

ostream& operator<<(ostream& out, const Polynomial& p);

#endif