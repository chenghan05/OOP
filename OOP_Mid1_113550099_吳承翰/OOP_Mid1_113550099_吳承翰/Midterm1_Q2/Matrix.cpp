#include "Matrix.h"
#include <fstream>
#include <iostream>

using namespace std;

void Matrix::clear() {
    if(m_data != nullptr) {
        for(int i = 0; i < row_size; ++i) {
            delete[] m_data[i];
        }
        delete[] m_data;
        m_data = nullptr;
    }
}

Matrix::~Matrix() {
    clear();
}

void Matrix::init() {
    m_data = new int*[row_size];
    for(int i = 0; i < row_size; ++i)
        m_data[i] = new int[col_size];
    
    for(int i = 0; i < row_size; ++i) {
        for(int j = 0; j < col_size; ++j) {
            m_data[i][j] = 0;
        }
    }
}

void Matrix::print() {
    cout << "[";
    for(int i = 0; i < row_size; ++i) {
        cout << "[";
        for(int j = 0; j < col_size; ++j) {
            cout << m_data[i][j];
            if(j + 1 != col_size)
                cout << ", ";
        }
        cout << "]";
        if(i + 1 != row_size) {
            cout << ",";
        }
    }
    cout << "]\n";
}

void Matrix::printPoly() {
    std::cout << poly << '\n';
}

void Matrix::setIdentity() {
    // TODO: Set matrix to Identity matrix
    if (row_size == col_size && row_size != 0) {
        for (int i = 0; i < row_size; ++i) {
            for (int j = 0; j < col_size; ++j) {
                m_data[i][j] = 0;
            }
        }
        for (int i = 0; i < row_size; i++) {
            m_data[i][i] = 1;
        }
    }

}

Matrix Matrix::evaluate() {
    // TODO: Compute P(A) = a0*I + a1*A + a2*A^2 + ... using the stored Polynomial calculated by Part2
    Matrix M = Matrix(row_size, col_size, poly);
    vector<int> v = poly.getData();
    for (int i = 0; i < v.size(); i++) {
        M += ((*this ^ i) * v[i]);
    }
    return M;
}

Matrix Matrix::operator^(const int& exp) {
    // TODO: Perform matrix exponentiation
    if (exp == 0) {
        Matrix M = Matrix(row_size, col_size, poly);
        M.setIdentity();
        return M;
    }
    Matrix M = Matrix(row_size, col_size, poly);
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            M.m_data[i][j] = m_data[i][j];
        }
    }
    for (int i = 1; i < exp; i++) {
        M *= *this;
    }
    return M;
}

Matrix& Matrix::operator+=(const Matrix& mat) {
    // TODO: Add another matrix to this matrix element-wise (in-place)
    if (this->row_size != mat.row_size || this->col_size != mat.col_size) {
        cerr << "size error" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            m_data[i][j] += mat.m_data[i][j];
        }
    }
    // Note: Return by reference so the result can be further modified (e.g., chained +=)
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& mat) {
    // TODO: Multiply this matrix by another matrix and store the result (in-place)
    if (this->col_size != mat.row_size) {
        cerr << "size error" << endl;
        exit(EXIT_FAILURE);
    }
    Matrix M = Matrix(this->row_size, mat.col_size, poly);
    for (int i = 0; i < this->row_size; i++) {
        for (int j = 0; j < mat.col_size; j++) {
            M.m_data[i][j] = 0;
            for (int k = 0; k < this->col_size; k++) {
                M.m_data[i][j] += this->m_data[i][k] * mat.m_data[k][j];
            }
        }
    }

    for (int i = 0; i < row_size; ++i) {
        delete[] m_data[i];
    }
     delete[] m_data;
    m_data = nullptr;

    col_size = mat.col_size;

    m_data = new int* [row_size];
    for (int i = 0; i < row_size; ++i)
    m_data[i] = new int[col_size];

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            m_data[i][j] = M.m_data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const int& coef) {
    // TODO: Return a new matrix with each element multiplied by the scalar coefficient
    Matrix M = Matrix(row_size, col_size, poly);
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            M.m_data[i][j] = m_data[i][j] * coef;
        }
    }
    return M;
}

ifstream& operator>>(ifstream& in, Matrix& mat) {
    mat.init();
    int value;
    for(int i = 0; i < mat.row_size; ++i) {
        for(int j = 0; j < mat.col_size; ++j) {
            if (!(in >> value)) {
                cerr << "Error Position:(" << i << ", " << j << ")" << std::endl;
                return in;
            }
            mat.m_data[i][j] = value;
        }
    }
    return in;
}

ofstream& operator<<(ofstream& out,const Matrix& mat) {
    out << "[";
    for (int i = 0; i < mat.row_size; ++i) {
        out << "[";
        for (int j = 0; j < mat.col_size; ++j) {
            out << mat.m_data[i][j];
            if (j + 1 != mat.col_size)
                out << ", ";
        }
        out << "]";
        if (i + 1 != mat.row_size)
            out << ",";
    }
    out << "]\n";
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

