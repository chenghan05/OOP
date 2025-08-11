#include <iostream>

#include "DateCalculator.h"

using namespace std;



int main(){
    DateCalculator dateCalculator;

    // You can modify the filename
    dateCalculator.readFile("Hidden_Input.txt");
    dateCalculator.calculate();

    // You can modify the filename
    dateCalculator.writeFile("Hidden_Output.txt");
}