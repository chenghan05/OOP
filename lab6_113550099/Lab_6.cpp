#include <iostream>
#include <fstream>
#include <vector>

#include "LinkedList.h"
#include "Tools.h"

using namespace std;

void test();

int main() {
    //test();
    //return 0;
    vector<string> inputPath, outputPath;
    if(configure(inputPath, outputPath, "./configure.txt") != 0) {
        fprintf(stderr, "configure failed\n");
        return -1;
    }

    int fileIndex;
    int num, value;
    string oper;
    ifstream data;
    ofstream out;

    cout << "Input Index: ";
    while((cin >> fileIndex)) {
        LinkedList linkedList1, linkedList2;
        if(checkFileExist(inputPath[fileIndex - 1]) && checkFileExist(outputPath[fileIndex - 1])) {
            data.open(inputPath[fileIndex - 1]);
            out.open("output.txt");

            while(data >> oper) {
                if(oper == "list1") {
                    data >> num;
                    for(int i = 0; i < num; ++i) {
                        data >> value;

                        linkedList1.insertNode(value);
                    }

                    out << "Initial LinkedList 1: ";
                    linkedList1.printLinkedList(out);
                    out << "\n";
                }
                else if(oper == "insert") {
                    data >> num;

                    linkedList1.insertNode(num);

                    out << "Insert " << num << "\n\n";
                    
                    out << "LinkedList 1: ";
                    linkedList1.printLinkedList(out);
                    out << "\n";
                }
                else if(oper == "delete") {
                    data >> num;
                    if(linkedList1.deleteNode(num)) {
                        out << "delete " << num << "\n\n";
                    }
                    else {
                        out << "No Found number.\n\n";
                    }
                }
                else if(oper == "list2") {
                    data >> num;
                    for(int i = 0; i < num; ++i) {
                        data >> value;

                        linkedList2.insertNode(value);
                    }
                    
                }
            }
            out << "LinkedList 1 Before Sort: ";
            linkedList1.printLinkedList(out);
            out << "\n";

            linkedList1.sort();
                    
            out << "LinkedList 1 After Sort: ";
            linkedList1.printLinkedList(out);
            out << "\n";

            out << "LinkedList 2 Before Sort: ";
            linkedList2.printLinkedList(out);
            out << "\n";
            
            linkedList2.sort();

            out << "LinkedList 2 After Sort: ";
            linkedList2.printLinkedList(out);
            out << "\n";

            linkedList1.mergeLinkedList(linkedList2);
            
            out << "After Merge: ";
            linkedList1.printLinkedList(out);
            out << "\n";

            data.close();
            out.close();

            if(checkAnswer("output.txt", outputPath[fileIndex - 1]))
                cout<<"True\n";
            else
                cout<<"False\n";
        }
        else {
            std::cout << "Not Found File.\n";
        }
        cout << "Input Index: ";
    }
}


///*
void test(){
    LinkedList linkedList1;
    LinkedList linkedList2;
    int num, value;
    string oper;
    ofstream out("haha");

    while (cin >> oper) {
        if (oper == "c")break;
        if (oper == "list1") {
            cin >> num;
            for (int i = 0; i < num; ++i) {
                cin >> value;

                linkedList1.insertNode(value);
            }

            cout << "Initial LinkedList 1: ";
            linkedList1.printLinkedList(out);
            cout << "\n";
        }
        else if (oper == "insert") {
            cin >> num;

            linkedList1.insertNode(num);

            cout << "Insert " << num << "\n\n";

            cout << "LinkedList 1: ";
            linkedList1.printLinkedList(out);
            cout << "\n";
        }
        else if (oper == "delete") {
            cin >> num;
            if (linkedList1.deleteNode(num)) {
                cout << "delete " << num << "\n\n";
            }
            else {
                cout << "No Found number.\n\n";
            }
        }
        else if (oper == "list2") {
            cin >> num;
            for (int i = 0; i < num; ++i) {
                cin >> value;

                linkedList2.insertNode(value);
            }

            cout << "Initial LinkedList 2: ";
            linkedList2.printLinkedList(out);
            cout << "\n";
        }
        else if (oper == "one") {
            cout << "LinkedList 1 Before Sort: ";
            linkedList1.printLinkedList(out);
            cout << "\n";
            linkedList1.sort();
            cout << "LinkedList 1 After Sort: ";
            linkedList1.printLinkedList(out);
            cout << "\n";
        }
        else if (oper == "two") {
            cout << "LinkedList 2 Before Sort: ";
            linkedList2.printLinkedList(out);
            cout << "\n";

            linkedList2.sort();

            cout << "LinkedList 2 After Sort: ";
            linkedList2.printLinkedList(out);
            cout << "\n";
        }
        else if(oper == "three") {
            linkedList1.mergeLinkedList(linkedList2);

            cout << "After Merge: ";
            linkedList1.printLinkedList(out);
            cout << "\n";
        }
    }
    cout << "LinkedList 1 Before Sort: ";
    linkedList1.printLinkedList(out);
    cout << "\n";
    
    linkedList1.sort();

    cout << "LinkedList 1 After Sort: ";
    linkedList1.printLinkedList(out);
    cout << "\n";

    cout << "LinkedList 2 Before Sort: ";
    linkedList2.printLinkedList(out);
    cout << "\n";

    linkedList2.sort();

    cout << "LinkedList 2 After Sort: ";
    linkedList2.printLinkedList(out);
    cout << "\n";

    linkedList1.mergeLinkedList(linkedList2);

    cout << "After Merge: ";
    linkedList1.printLinkedList(out);
    cout << "\n";
}
//*/
