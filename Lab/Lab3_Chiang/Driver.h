#ifndef Driver_h
#define Driver_h

#include <fstream>
#include "Linear.h"
#include "Quadratic.h"
#include "Double.h"

class Driver
{
    public:
        const int tableSize = 191;
        const int doubleFactor = 181;
        ofstream outFoo1, outFoo2;
        vector<int> nums;
        
        void testFile(string inner, string outer1, string outer2);
        
        void testHash(const string& description);
        
        void testInputKey(const int key, HashInterface<int, int>& lph, HashInterface<int, int>& qph, HashInterface<int, int>& dhph);

        void testKeyValue(string description, HashInterface<int, int>& hashTable, const int key, const int value);

        void testTable(string order, string prober, HashInterface<int, int>& hh);
};

#endif
