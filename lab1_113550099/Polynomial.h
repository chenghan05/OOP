#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

class Polynomial{
public:
    
    /*Ascending order*/
    int m_data[5];

    Polynomial():m_data{0} {}
    Polynomial(int a,int b,int c):m_data{c,b,a,0,0} {}

    void print();
    void add(Polynomial);
    void multiple(Polynomial);
};
#endif