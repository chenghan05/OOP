#include "Matrix.h"
#include <fstream>
#include <iostream>

using namespace std;


void Matrix::clear(){
    //TODO: clear data of matrix
    if (m_data == nullptr)return;
    for (int i = 0; i < row_size; i++) {
        delete[] m_data[i];
    }
    delete[] m_data;
    m_data = nullptr;
}

Matrix::~Matrix(){
    //TODO: Implement deconstructor
    clear();
}

void Matrix::init(){
    //TODO: Init matrix
    if (row_size == 0 || col_size == 0)return;
    m_data = new double*[row_size];
    for (int i = 0; i < row_size; i++) {
        m_data[i] = new double[col_size] {0};
    }
}

void Matrix::print(){
    //TODO: Display matrix on terminal
    // Example: [[1,2],[3,4],[5,6]]
    cout << "[";
    for (int i = 0; i < row_size; i++) {
        if (i != 0)cout << ",";
        cout << "[";
        for (int j = 0; j < col_size; j++) {
            if (j != 0)cout << ",";
            cout << m_data[i][j];
        }
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

void Matrix::coef_multiple(const double& coef){
    //TODO: Perform scale multiple
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            m_data[i][j] *= coef;
        }
    }
}

Matrix Matrix::operator+(const Matrix& mat){
    // TODO:Perform matrix addition
     // if( some condiction){
    //     cerr << "size error" << endl;
    //     exit(EXIT_FAILURE);
    // }
    Matrix M = Matrix(this->row_size, mat.col_size);
    if (this->row_size != mat.row_size || this->col_size != mat.col_size) {
        cerr << "size error" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            M.m_data[i][j] = this->m_data[i][j] + mat.m_data[i][j];
        }
    }
    return M;
}

Matrix Matrix::operator-(const Matrix& mat){
    // TODO: Perform matrix substraction
     // if( some condiction){
    //     cerr << "size error" << endl;
    //     exit(EXIT_FAILURE);
    // }
    Matrix M = Matrix(this->row_size, mat.col_size);
    if (this->row_size != mat.row_size || this->col_size != mat.col_size) {
        cerr << "size error" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            M.m_data[i][j] = this->m_data[i][j] - mat.m_data[i][j];
        }
    }
    return M;
}

Matrix Matrix::operator*(const Matrix& mat){
    // TODO: Perform matrix multiple
    // if( some condiction){
    //     cerr << "size error" << endl;
    //     exit(EXIT_FAILURE);
    // }
    if (this->col_size != mat.row_size) {
        cerr << "size error" << endl;
        exit(EXIT_FAILURE);
    }
    Matrix M = Matrix(this->row_size, mat.col_size);
    for (int i = 0; i < this->row_size; i++) {
        for (int j = 0; j < mat.col_size; j++) {
            M.m_data[i][j] = 0;
            for (int k = 0; k < this->col_size; k++) {
                M.m_data[i][j] += this->m_data[i][k] * mat.m_data[k][j];
            }
        }
    }
    return M;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other)return *this;
    //TODO : Implement assign matrix to other matrix
    this->clear();
    this->row_size = other.row_size;
    this->col_size = other.col_size;
    this->init();
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            this->m_data[i][j] = other.m_data[i][j];
        }
    }
    return *this;
}

ifstream& operator>>(ifstream& in,Matrix& mat){
    //TODO: Load data from input.txt
    for (int i = 0; i < mat.row_size; i++) {
        for (int j = 0; j < mat.col_size; j++) {
            in >> mat.m_data[i][j];
        }
    }
    return in;
}

ofstream& operator<<(ofstream& out,const Matrix& mat){
    //TODO: Ouput data to output.txt
    //Example: [[1,2],[3,4],[5,6]]
    out << "[";
    for (int i = 0; i < mat.row_size; i++) {
        if (i != 0)out << ",";
        out << "[";
        for (int j = 0; j < mat.col_size; j++) {
            if (j != 0)out << ",";
            out << mat.m_data[i][j];
        }
        out << "]";
    }
    out << "]";
    out << endl;
    return out;
}

Matrix::Matrix(const Matrix& M) {
    row_size = M.row_size;
    col_size = M.col_size;
    init();
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            m_data[i][j] = M.m_data[i][j];
        }
    }
}

