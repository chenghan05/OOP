#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <sys/stat.h>

using namespace std;

#define CONFIGURE "configure.txt"

bool checkFileExist(const string &checkFile);
int configure(vector<string> &inputFiles,vector<string> &outputFiles);
bool CheckAnswer(const string& filename1, const string& filename2, bool removeFile);

int main(){
    vector<string>inputPath, outputPath;
    if(configure(inputPath, outputPath) != 0) {
        fprintf(stderr, "configure failed\n");
        return -1;
    }

    int fileIndex;
    int num_operation;
    char oper;
    int row_size,col_size;
    ifstream data;
    ofstream out;
    Matrix m1,m2;

    cout<<"Input Index: ";
    while((cin >> fileIndex)) {
        if(checkFileExist(inputPath[fileIndex - 1]) && checkFileExist(outputPath[fileIndex - 1])) {
            data.open(inputPath[fileIndex - 1]);
            out.open("output.txt");

            if(!data.is_open()){
                fprintf(stderr,"Error\n");
                return -1;
            }

            data>>num_operation;
            while(num_operation--){
                data >> oper;
                switch (oper)
                {
                case '+':
                    data >> row_size >> col_size;
                    m1 = Matrix(row_size,col_size);
                    
                    data >> m1;
                    data >> row_size >> col_size;
                    m2 = Matrix(row_size,col_size);
                    data >> m2;
//                    (m1 + m2).print();
                    out << (m1+m2);
                    break;
        
                case '-':
                    data>>row_size>>col_size;
                    m1 = Matrix(row_size,col_size);
                    
                    data >> m1;
                    data >> row_size >> col_size;
                    m2 = Matrix(row_size, col_size);
                    data >> m2;
//                    (m1 - m2).print();
                    out << (m1 - m2);
                    break;
        
                case '*':
                    data >> row_size >> col_size;
                    m1 = Matrix(row_size, col_size);
                    
                    data >> m1;
                    data >> row_size >> col_size;
                    m2 = Matrix(row_size, col_size);
                    data >> m2;
//                    (m1 * m2).print();
                    out << (m1 * m2);
                    break;
        
                case 'x':
                    double coef;
                    data >> coef;
                    data >> row_size >> col_size;
                    m1 = Matrix(row_size, col_size);
                    data >> m1;
                    m1.coef_multiple(coef);
//                    m1.print();
                    out << m1;
                    break;
                default:
                    std::cerr << "Error";
                    break;
                }
            }
            data.close();
            out.close();

            cout << "[Test " << fileIndex << "] : "
                 << (CheckAnswer("output.txt", outputPath[fileIndex - 1],true) ? "True" : "False") << endl;
        }

        else{
            fprintf(stderr, "File not existed\n");
        }
        cout<<"Input Index: ";
    }

}


bool checkFileExist(const string &checkFile){
    struct stat fileInfo;
    return (stat(checkFile.c_str(), &fileInfo) == 0);
}

int configure(vector<string> &inputFiles, vector<string> &outputFiles){
    ifstream conf(CONFIGURE);
    if(!conf.is_open()) {
        fprintf(stderr, "configure error\n");
        return -1;
    }

    string inputPath, outputPath;
    while(conf >> inputPath && conf >> outputPath) {
        inputFiles.push_back(inputPath);
        outputFiles.push_back(outputPath);
    }
    conf.close();
    return 0;
}

bool CheckAnswer(const string& output, const string& sample_output, bool removeFile = true){
    string command = "fc \"" + output + "\" \"" + sample_output + "\" > nul";

    int result = system(command.c_str());
    if (result == 0)
        return true;
    else
        return false;

}
