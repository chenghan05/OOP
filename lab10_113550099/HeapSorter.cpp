#include "HeapSorter.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void HeapSorter::loadData(const string& line) {
    data.clear();
    stringstream ss(line);
    int x;
    while (ss >> x) data.push_back(x);
}

void HeapSorter::buildMinHeapTopDown() {
    // TODO: Insert elements one by one and adjust upward to build a min-heap
    // Hint: use heapifyUp(std::vector<int>& heap, int i)
    vector<int> heap;
    //heap.push_back(0);
    heap.push_back(data[0]);
    for (int i = 1; i < data.size(); i++) {
        heap.push_back(data[i]);
        heapifyUp(heap, i);
    }
    //heap.erase(heap.begin());
    data = heap;
    //cout << "build by top down\n";
    //print();
}

void HeapSorter::buildMinHeapBottomUp() {
    // TODO: Adjust each non-leaf node downward from the middle to build a min-heap
    //int idx = data.size() / 2;
    int idx = data.size() / 2 - 1;
    //data.push_back(data[0]);
    for (int i = idx; i >= 0; i--) {
        heapifyDown(i, data.size());
    }
    //data.erase(data.begin());
}

void HeapSorter::heapSortInPlace() {
    // TODO: Repeatedly remove the root and rebuild the min-heap to sort the array
    vector<int> sorted;
    sorted.push_back(data[0]);
    data.erase(data.begin());
    while (!data.empty()) {
        buildMinHeapTopDown();
        sorted.push_back(data[0]);
        data.erase(data.begin());
    }
    data = sorted;
}

void HeapSorter::heapifyUp(std::vector<int>& heap, int i) {
    // TODO: Move the value at index i upward if it's smaller than its parent
    while (heap[i] < heap[ (i-1) /2] && i != 0) {
        int tmp = heap[i];
        heap[i] = heap[ (i-1) / 2];
        heap[ (i-1) / 2] = tmp;
        i = (i-1) / 2;
    }
/*
    while (heap[i] < heap[i / 2] && i != 1) {
        int tmp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = tmp;
        i /= 2;
    }
*/
}

void HeapSorter::heapifyDown(int i, int heapsize) {
    // TODO: Move the value at index i downward if it's larger than its children
    if (2 * i + 2 < data.size()) {
        if (data[2 * i + 1] < data[i] && data[2 * i + 1] <= data[2 * i + 2]) {
            int tmp = data[i];
            data[i] = data[2 * i + 1];
            data[2 * i + 1] = tmp;
            heapifyDown(2 * i + 1, heapsize);
        }
        else if (data[2 * i + 2] < data[i] && data[2 * i + 2] <= data[2 * i + 1]) {
            int tmp = data[i];
            data[i] = data[2 * i + 2];
            data[2 * i + 2] = tmp;
            heapifyDown(2 * i + 2, heapsize);
        }
    }
    else if (2 * i + 1 < data.size()) {
        if (data[i] > data[2 * i + 1]) {
            int tmp = data[i];
            data[i] = data[2 * i + 1];
            data[2 * i + 1] = tmp;
            heapifyDown(2 * i + 1, heapsize);
        }
    }
/*
    if(2 * i + 1 < data.size()) {
        if (data[2 * i] < data[i] && data[2 * i] <= data[2*i+1]) {
            int tmp = data[i];
            data[i] = data[2 * i];
            data[2 * i] = tmp;
            heapifyDown(2 * i, heapsize);
        }
        else if (data[2 * i + 1] < data[i] && data[2 * i + 1] <= data[2*i]) {
            int tmp = data[i];
            data[i] = data[2 * i + 1];
            data[2 * i + 1] = tmp;
            heapifyDown(2 * i + 1, heapsize);
        }
    }else if (2 * i < data.size()) {
        if (data[i] > data[2 * i]) {
            int tmp = data[i];
            data[i] = data[2 * i];
            data[2 * i] = tmp;
            heapifyDown(2 * i, heapsize);
        }
    }
*/
}

void HeapSorter::heapifyUp(int i) {
    heapifyUp(data, i);
}


void HeapSorter::print(ofstream& out) const {
    for (int val : data)
        out << val << " ";
    out << "\n";
}

void HeapSorter::print() {
    for (int val : data)
        cout << val << " ";
    cout << "\n";
}

const vector<int>& HeapSorter::getHeap() const {
    return data;
}