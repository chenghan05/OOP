#include "Polynomial.h"

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Polynomial::Polynomial() {
    m_data = std::vector<int>(SIZE, 0);
}

Polynomial::Polynomial(const vector<int>& coeffs) : m_data(coeffs) {
    while (m_data.size() > 1 && m_data.back() == 0) {
        m_data.pop_back();
    }
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    // TODO: Add two polynomials by summing coefficients of the same degree
    vector<int> v;
    int size = m_data.size() >= other.m_data.size() ? m_data.size() : other.m_data.size();
    for (int i = 0; i < size; i++) {
        if (i < m_data.size() && i < other.m_data.size()) {
            v.push_back(m_data[i] + other.m_data[i]);
        }else if (i < m_data.size()) {
            v.push_back(m_data[i]);
        }
        else {
            v.push_back(other.m_data[i]);
        }
    }
/*    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
*/
    return Polynomial(v);
}


Polynomial Polynomial::operator-(const Polynomial& other) const {
    // TODO: Subtract two polynomials by subtracting coefficients of the same degree
    vector<int> v;
    int size = m_data.size() >= other.m_data.size() ? m_data.size() : other.m_data.size();
    for (int i = 0; i < size; i++) {
        if (i < m_data.size() && i < other.m_data.size()) {
            v.push_back(m_data[i] - other.m_data[i]);
        }
        else if (i < m_data.size()) {
            v.push_back(m_data[i]);
        }
        else {
            v.push_back(other.m_data[i]);
        }
    }

    /*    for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << endl;
    */
    return Polynomial(v);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    // TODO: Multiply two polynomials using coefficient convolution
    int size = m_data.size() + other.m_data.size() - 1;
    vector<int> v;
    for (int i = 0; i < size; i++) {
        v.push_back(0);
    }
    int putidx = 0;
    for (int i = 0; i < m_data.size(); i++) {
        for (int j = 0; j < other.m_data.size(); j++) {
            putidx = i + j;
            v[putidx] += m_data[i] * other.m_data[j];
        }
    }
    /*    for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << endl;
    */
    return Polynomial(v);
}

ostream& operator<<(ostream& out, const Polynomial& p) {
    // TODO: Format and output the polynomial in standard mathematical form (e.g., 3x^2 + 2x + 1)
    //       Skip zero terms, handle signs, and simplify powers like x^1 to x, x^0 to constant.
    int first = 0;
    for (int i = p.m_data.size()-1; i >= 0; i--) {
        if (p.m_data[i] != 0) {
            if (!first) {
                if (p.m_data[i] < 0) {
                    out << "-";
                }
            }
            if (first) {
                if (p.m_data[i] > 0) {
                    out << " + ";
                }
                else if(p.m_data[i] < 0){
                    out << " - ";
                }
            }
            first = 1;
            if (i == 0) {
                if (p.m_data[i] > 0) {
                    out << p.m_data[i];
                }
                else if (p.m_data[i] < 0) {
                    out << p.m_data[i] * -1;
                }
            }
            else {
                if (p.m_data[i] > 1) {
                    out << p.m_data[i];
                }
                else if(p.m_data[i] < -1){
                    out << p.m_data[i] * -1;
                }
                out << "x";
                if (i > 1)out << "^" << i;
            }
        }
    }
    if (!first)out << 0;
    return out;
}
