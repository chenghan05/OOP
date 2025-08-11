#ifndef __DATECALCULATOR_H
#define __DATECALCULATOR_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class DateCalculator{
    private:
        vector<int> year;
        vector<int> month;
        vector<int> day;
        vector<char> op;
        vector<int> d;

        int size; // number of dates
    public:
        DateCalculator(): size(0){}
        

        void readFile(string filename);
        void writeFile(string filename);
        void calculate();
        int getDayInMonth(int year,int month);
        void addDays(int &year, int &month, int &day, int days);
        void minusDays(int &year, int &month, int &day,int days);
        bool isLeapYear(int year);
};


#endif // __DATECALCULATOR_H