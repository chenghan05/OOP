#ifndef __POLYFACTORIZATION_H__
#define __POLYFACTORIZATION_H__

#include <iostream>
#include <vector>

using namespace std;

// =============================================
// ** ATTENTION: YOU CANNOT MODIFY THIS FILE. **
// =============================================

enum DiscriminantType {
    REAL_ROOTS,
    COMPLEX_ROOTS
};

class PolyFactorization {
private:

    /*Ascending order*/
    int m_data[3];

    /*
    =======================================================================================
        negativeB: The negated value of `b`, used in the quadratic formula.
        discriminant: The discriminant determines the nature of the roots.
        denominator: The denominator in the quadratic formula.
        sqrtOutside: The extracted factor from the square root.
        discriminantFactors: Stores the prime factorization of the discriminant.
    =======================================================================================
    */
    int negativeB;
    int discriminant;
    int denominator;
    int sqrtOutside;

    vector<int> discriminantFactors;

public:
    PolyFactorization(): m_data{0} {}
    PolyFactorization(int c0, int c1, int c2): m_data{c0, c1, c2} {}

    /*
    =======================================================================================
        CheckDiscriminant(): Checks whether real roots exist. 
                            Returns REAL_ROOTS if real roots are present; otherwise, returns COMPLEX_ROOTS.
        SolveQuadratic(): Solves the quadratic equation.
        CalcPrimeFactorization(): Performs prime factorization on the discriminant.
        CalcGCD(a, b): Computes the greatest common divisor (GCD) using the Euclidean algorithm.
        PrintSolution(): Prints the result.
    =======================================================================================
    */
    DiscriminantType CheckDiscriminant();
    void SolveQuadratic();
    void CalcPrimeFactorization();
    int CalcGCD(int a, int b);
    void PrintSolution();
};


#endif