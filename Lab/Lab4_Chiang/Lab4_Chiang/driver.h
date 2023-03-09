#ifndef driver_h
#define driver_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Heap.h"

using namespace std;

class Driver
{
    public:
        vector<int> nums;
        ifstream ifFoo;
        ofstream outFoo;

        void process(string inner, string outer);
        void printHeap(Heap<int>& H, ofstream &O);
        
};

#endif
