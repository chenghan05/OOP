#include "Polynomial.h"
#include <iostream>

using namespace std;

int main(){
    int num_case;
    cin>>num_case;
    
    while(num_case--){
        char command;
        cin>>command;
        int coefft;
        Polynomial p1,p2;
        switch (command)
        {
        case '+':
            for(int i=0 ;i<6 ; i++){
                cin >> coefft;
                (i > 2) ? (p2.m_data[5 - i] = coefft) : (p1.m_data[2 - i] = coefft);
            }
            p1.add(p2);
            /*TODO: Add something here*/
            break;
        case '*':
            for (int i = 0;i < 6; i++) {
                cin >> coefft;
                (i > 2) ? (p2.m_data[5 - i] = coefft) : (p1.m_data[2 - i] = coefft);
            }
            p1.multiple(p2);
            /*TODO: Add something here*/
            break;
        case 'p':
            for (int i = 0;i < 3; i++) {
                cin >> p1.m_data[2 - i];
            }
            p1.print();
            /*TODO: Add something here*/
            break;
        /*Deal with other cases*/
        default:
			cout << "wrong input!" << endl;
			break;
        }
    }
}