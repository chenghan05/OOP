#include "Baseball.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void Baseball::load_data(string file_path) {
    // TODO: Load data from input file.
    ifstream input(file_path);
    string s;
    while (input >> s) {
        data.push_back(s);
    }
}

int Baseball::get_PA_result(string PA_result) {
    // TODO: Converts a plate appearance (PA_result) into an integer representing base advancement:
    // - "1B" or "BB" returns 1
    // - "2B" returns 2
    // - "3B" returns 3
    // - "HR" returns 4
    // Any other result returns 0
    if (PA_result == "1B" || PA_result == "BB") {
        return 1;
    }else if (PA_result == "2B") {
        return 2;
    }else if (PA_result == "3B") {
        return 3;
    }else if (PA_result == "HR") {
        return 4;
    }else {
        return 0;
    }
    
}

void Baseball::play() {
    // TODO: Simulates a simplified baseball game:
    // - For each plate appearance, convert the result into a number indicating how many bases to advance
    // - If the result is 0 (an out), increase the out count
    // - If the result is greater than 0, place the batter on base and move all existing runners accordingly
    //   - If a runner passes home plate, a point is added
    // - When three outs are reached, reset all bases and the out count to simulate the next inning
    for (int i = 0; i < data.size(); i++) {
        converted_nums.push_back(get_PA_result(data[i]));
    }
    int out = 0;
    int inning = 0;
    int idx = 0;
    while (inning < 9 && idx < converted_nums.size()) {
        if (converted_nums[idx] == 0) {
            out++;
            if (out == 3) {
                out = 0;
                inning++;
                for (int i = 0; i < 4; i++) {
                    base[i] = 0;
                }
            }
        }
        else {
            for (int i = 3; i >= 0; i--) {
                if (base[i] > 0) {
                    if ((i + converted_nums[idx]) > 3) {
                        point++;
                        base[i]--;
                    }
                    else {
                        base[i + converted_nums[idx]]++;
                    }
                }else if (i == 0) {
                    if ((i + converted_nums[idx]) > 3) {
                        point++;
                    }
                    else {
                        base[i + converted_nums[idx]]++;
                    }
                }
            }
        }
        idx++;
    }
    
}

//Do not modify this function
void Baseball::output_result() {
    ofstream outputFile("output.txt");
    outputFile << "================================================================================================================================";
    outputFile << "\nPA:\n";
    for(int i = 0; i < data.size(); ++i) {
        outputFile << data[i] << ' ';
    }
    outputFile << "\nBase advancement:\n";
    for(int i = 0; i < converted_nums.size(); ++i) {
        outputFile << converted_nums[i] << ' ';
    }
    outputFile << "\nPoint: " << point << endl;
    outputFile << "================================================================================================================================";
}