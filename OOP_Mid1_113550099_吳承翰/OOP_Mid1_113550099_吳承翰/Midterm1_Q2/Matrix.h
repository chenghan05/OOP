#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <fstream>
#include <vector>

#include "Polynomial.h"

using namespace std;

class Matrix {
    private:
        int **m_data;
        int row_size, col_size;
        Polynomial poly;
    public:
        Matrix() : m_data(nullptr),row_size(0),col_size(0) {}
        Matrix(int row_size,int col_size, Polynomial _poly):row_size(row_size),col_size(col_size), poly(_poly) {
            init();
        }
        ~Matrix();
        Matrix(const Matrix& M);
        void init();
        void print();
        void clear();
        void printPoly();
        void setIdentity(); // TODO 
        Matrix evaluate(); // TODO 
        Matrix operator^(const int&);  // TODO
        Matrix& operator+=(const Matrix&); // TODO
        Matrix& operator*=(const Matrix&);  // TODO
        Matrix operator*(const int&);  // TODO 


        friend ifstream& operator>>(ifstream& in, Matrix& mat);
        friend ofstream& operator<<(ofstream& out, const Matrix& mat);
};

ifstream& operator>>(ifstream& in, Matrix& mat);
ofstream& operator<<(ofstream& out, const Matrix& mat);

#endif
