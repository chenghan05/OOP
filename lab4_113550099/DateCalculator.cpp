#include "DateCalculator.h"
#include <cstring>
using namespace std;

/*
    vector<int> year;
    vector<int> month;
    vector<int> day;
    vector<char> op;
    vector<int> d;
    int size; // number of dates
*/

void DateCalculator::readFile(string filename){
    // TODO: Read dates from the input file 
    ifstream input(filename);
    string date, temp;
    char Operator;
    int days;
    input >> size;
    //while (input >> year >> slash >> month >> slash >> day)
    for (int i = 0; i < size; i++) {
        input >> date >> Operator >> days;
        temp = date.substr(0, date.find("/"));
        year.push_back(stoi(temp));
        //cout << _Year << " " << date << endl;//   Find year

        date = date.substr(date.find("/")+1);
        temp = date.substr(0, date.find("/"));
        month.push_back(stoi(temp));
        //cout << _Month << " " << date << endl;//  Find month

        date = date.substr(date.find("/")+1);
        temp = date.substr(0, date.find(" "));
        day.push_back(stoi(temp));
        //cout << _Day << " " << date << endl;//    Find day

        op.push_back(Operator);
        d.push_back(days);
    }
    input.close();
}

void DateCalculator::writeFile(string filename){
    // TODO: Write dates to the output file
    ofstream output(filename);
    output << setfill('0');
    cout << setfill('0');
    for (int i = 0;i < size; i++) {
        output << setw(4) << year[i] << "/";
        output << setw(2) << month[i] << "/";
        output << setw(2) << day[i] << endl;

        cout << setw(4) << year[i] << "/";
        cout << setw(2) << month[i] << "/";
        cout << setw(2) << day[i] << endl;
    }
    output.close();
}

void DateCalculator::calculate(){
    // TODO: Calculate the date (add or minus days)
    // Please use a Member Function Pointer to call either addDays or minusDays
    for (int i = 0; i < size; i++) {
        void (DateCalculator::*function)(int&,int&,int&,int) = (op[i] == '+') 
                                                                ? &DateCalculator::addDays 
                                                                : &DateCalculator::minusDays;
        (this->*function)(year[i], month[i], day[i], d[i]);
    }
    
}

int DateCalculator::getDayInMonth(int year, int month){
    // TODO: Return the number of days in the month
    // Please using switch case to return the number of days in the month
    switch (month) {
        //TODO
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
        break;
    case 2:
        return isLeapYear(year) ? 29 : 28;
        break;
    case 4: case 6: case 9: case 11:
        return 30;
        break;
    }

}

void DateCalculator::addDays(int &year, int &month, int &day, int days){
    // TODO: Add days to the current date
    int leftdays;
    while (days > 0) {
        leftdays = getDayInMonth(year, (month % 12 == 0) ? 12 : month) - day + 1;
        if (days >= leftdays) {
            days -= leftdays;
            month++;
            day = 1;
            if (month == 13) {
                month = 1;
                year++;
            }
        }
        else {
            day += days;
            days = 0;
        }
    }
}

void DateCalculator::minusDays(int& year, int& month, int& day, int days) {
    // TODO: Minus days from the current date
    while (days > 0) {
        if (days >= day) {
            days -= day;
            month--;
            if (month == 0) {
                month = 12;
                year--;
            }
            day = getDayInMonth(year, (month % 12 == 0) ? 12 : month);
        }
        else {
            day -= days;
            days = 0;
        }
    }
}

bool DateCalculator::isLeapYear(int year){
    // TODO: Determine if the year is a leap year
    // If it is a leap year return true, otherwise return false
    if ( (year % 4 == 0) && ( !(year % 100 == 0) || (year % 400 == 0) ) )
        return 1;
    else
        return 0;
}
