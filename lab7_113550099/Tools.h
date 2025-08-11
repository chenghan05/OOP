#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <sys/stat.h>

using namespace std;


bool checkFileExist(const string& checkFile);
int configure(vector<string>& inputFiles, vector<string>& outputFiles, const string configureName);
bool checkAnswer(const string& filename1, const string& filename2);

bool checkFileExist(const string& checkFile) {
    struct stat fileInfo;
    return (stat(checkFile.c_str(), &fileInfo) == 0);
}

int configure(vector<string>& inputFiles, vector<string>& outputFiles, const string configureName) {
    ifstream conf(configureName);
    if (!conf.is_open()) {
        fprintf(stderr, "configure error\n");
        return -1;
    }

    string inputPath, outputPath;
    while (conf >> inputPath && conf >> outputPath) {
        inputFiles.push_back(inputPath);
        outputFiles.push_back(outputPath);
    }
    conf.close();
    return 0;
}
