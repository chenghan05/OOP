#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <fstream>
using namespace std;

class Matrix{
private:
    double **m_data;
    int row_size,col_size;

    void clear();
public:
    Matrix() : m_data(nullptr),row_size(0),col_size(0) {}
    Matrix(int row_size,int col_size):row_size(row_size),col_size(col_size) {
        init();
    }
    ~Matrix();
    Matrix(const Matrix&);

    void init();
    void print();
    void coef_multiple(const double& coef);

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix& operator=(const Matrix&);


    friend ifstream& operator>>(ifstream& in, Matrix& mat);
    friend ofstream& operator<<(ofstream& out, const Matrix& mat);
};

ifstream& operator>>(ifstream& in, Matrix& mat);
ofstream& operator<<(ofstream& out, const Matrix& mat);

#endif
