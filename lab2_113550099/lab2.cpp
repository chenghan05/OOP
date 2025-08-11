#include <iostream>
#include "PolyFactorization.h"

using namespace std;

// =============================================
// ** ATTENTION: YOU CANNOT MODIFY THIS FILE. **
// =============================================

int main() {
    int num_case;
    cin >> num_case;

    while(num_case--) {
        int m_data[3];
        cin >> m_data[2] >> m_data[1] >> m_data[0];
        PolyFactorization polyFactorization(m_data[0], m_data[1], m_data[2]);

        if(polyFactorization.CheckDiscriminant() == REAL_ROOTS) {
            polyFactorization.SolveQuadratic();
            polyFactorization.PrintSolution();
        }
        else {
            cout << "No real roots solutions\n";
        }
    }
}