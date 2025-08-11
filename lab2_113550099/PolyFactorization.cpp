#include "PolyFactorization.h"

using namespace std;

DiscriminantType PolyFactorization::CheckDiscriminant() {
    // TODO: Use the Conditional Operator in this function.
    return (m_data[1] * m_data[1] - 4 * m_data[2] * m_data[0] >= 0)
           ?REAL_ROOTS
           :COMPLEX_ROOTS;
}

void PolyFactorization::SolveQuadratic() {
    // TODO: Use m_data to compute the quadratic roots.
    // Note: You can solve this problem using GCD and Prime Factorization.
    negativeB = -1 * m_data[1];
    denominator = 2 * m_data[2];
    CalcPrimeFactorization();
    int gcd = CalcGCD(CalcGCD(negativeB, sqrtOutside), denominator);
    negativeB /= gcd;
    denominator /= gcd;
    sqrtOutside /= gcd;
}

void PolyFactorization::CalcPrimeFactorization() {
    // TODO: Complete the function using while loop or for loop.
    discriminant = m_data[1] * m_data[1] - 4 * m_data[2] * m_data[0];
    sqrtOutside = discriminant ? 1 : 0;
    int i = 2;
    while (i * i <= discriminant) {
        if (discriminant % (i * i) == 0) {
            discriminant /= (i * i);
            sqrtOutside *= i;
        }
        else {
            i++;
        }
    }
}

int PolyFactorization::CalcGCD(int a, int b) {
    // TODO: Implement GCD using the Euclidean Algorithm.
    if (a == 0) {
        return b == 0 ? 0 : b;
    }
    if (b == 0)return a;
    a = (a < 0 ? -1 * a : a);
    b = (b < 0 ? -1 * b : b);
    int temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void PolyFactorization::PrintSolution() {
    // TODO: Print the quadratic equation solution.
    if (discriminant == 1) {
        cout << "Answer 1: ";
        int gcd = CalcGCD(negativeB + sqrtOutside, denominator);
        int num = (negativeB + sqrtOutside) / gcd;
        denominator /= gcd;
        cout << num;
        if (denominator != 1)cout << " / " << denominator;
        cout << endl;
        cout << "Answer 2: ";
        num = (negativeB - sqrtOutside) / gcd;
        cout << num;
        if (denominator != 1)cout << " / " << denominator;
        cout << endl;
    }
    else {
        cout << "Answer 1: ";
        if (negativeB != 0 && discriminant != 0) {
            cout << "( ";
            cout << negativeB;
            cout << " + ";
            if (sqrtOutside != 1)cout << sqrtOutside;
            cout << "sqrt(" << discriminant << ") )";
        }
        else if (negativeB != 0) {
            cout << negativeB;
        }
        else if (discriminant != 0) {
            if (sqrtOutside != 1)cout << sqrtOutside;
            cout << "sqrt(" << discriminant << ")";
        }
        if (denominator != 1)cout << " / " << denominator;
        cout << endl;

        cout << "Answer 2: ";
        if (negativeB != 0 && discriminant != 0) {
            cout << "( ";
            cout << negativeB;
            cout << " - ";
            if (sqrtOutside != 1)cout << sqrtOutside;
            cout << "sqrt(" << discriminant << ") )";
        }
        else if (negativeB != 0) {
            cout << negativeB;
        }
        else if (discriminant != 0) {
            cout << "-";
            if (sqrtOutside != 1)cout << sqrtOutside;
            cout << "sqrt(" << discriminant << ")";
        }
        if (denominator != 1)cout << " / " << denominator;
        cout << endl;
    }
}