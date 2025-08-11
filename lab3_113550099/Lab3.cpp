#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include "Gomoku.h"

#define CONFIGURE "configure.txt"

using namespace std;

bool checkFileExist(const string &fileName){
    struct stat fileInfo;
    return (stat(fileName.c_str(), &fileInfo) == 0);
}

int configure(vector<string> &InputPath){
    ifstream conf(CONFIGURE);
    if(!conf.is_open()) {
        fprintf(stderr, "configure error\n");
        return -1;
    }

    string filepath;
    while(conf >> filepath) {
        InputPath.push_back(filepath);
    }
    conf.close();

    return 0;
}

int main() {
    vector<string>InputPath;
    if(configure(InputPath) != 0) {
        fprintf(stderr, "configure failed\n");
        return -1;
    }

    int fileIndex;
    cout<<"Input Index: ";
    while((cin >> fileIndex)) {
        if(checkFileExist(InputPath[fileIndex - 1])) {
            Gomoku gomoku;
            gomoku.OpenFile(InputPath[fileIndex - 1]);
            gomoku.Play();
        }
        else {
            fprintf(stderr, "File not existed\n");
        }
        cout<<"Input Index: ";
    }
}