//implementation file for Driver

#include <iostream>
#include <algorithm>
#include "Driver.h"

/*
Opens file and calls methods to test hashing
Intput: inner is the input filename
Output: outer is the output filename
*/
void Driver::testFile(string inner, string outer1, string outer2)
{
    int key;
    ifstream q(inner);

    cout << "Processing input: " << inner << endl;
    
    while (q >> key)                //reads txt 
    {
        nums.push_back(key);        //stores in vector
    }

    q.close();
    
    
    outFoo1.open(outer1);              //creates the respective output collision files
    outFoo2.open(outer2);              //creates the respective output tables files
    
    testHash("Random");                                          //hashes the unordered data

    sort(nums.begin(), nums.end());
    testHash("Ascending");                                          //hashes the ascending data

    sort(nums.begin(), nums.end(), greater<int>());
    testHash("Descending");                                         //hashes the descending data
    
    nums.clear();                //clear the vector for the next files

    outFoo1.close();
    outFoo2.close();
}


/*
Uses all three hash table methods
Intput: N/A
Output: Writes to output file with # of collisions for each method
*/
void Driver::testHash(const string& description){
 
    LinearProbingHash<int, int> lp(tableSize);
    QuadraticProbingHash<int, int> qp(tableSize);
    DoubleProbingHash<int, int> dh(tableSize, doubleFactor);

    outFoo1 << "*** "<< description << " Order Start *** " << "\n\n";

    for (auto& key : nums)
        testInputKey(key, lp, qp, dh);
        
    outFoo1 << "Linear    " << lp.getCollisions() << " collisions\n";
    outFoo1 << "Quadratic " << qp.getCollisions() << " collisions\n";
    outFoo1 << "Double    " << dh.getCollisions() << " collisions\n";

    outFoo1 << "\n*** " << description << " Order End *** " << "\n\n";

    testTable(description,"Linear",lp);
    testTable(description,"Quadratic", qp);
    testTable(description,"Double", dh);
}


/*
Plugs key into the hash table
Intput: key and various probing objects
Output: N/A
*/
void Driver::testInputKey(const int key, HashInterface<int, int>& lph, HashInterface<int, int>& qph, HashInterface<int, int>& dhph){
    const int value = key*2;

    testKeyValue("Linear   ", lph, key, value);
    testKeyValue("Quadratic", qph, key, value);
    testKeyValue("Double   ", dhph, key, value);

    outFoo1 << "\n";
}


/*
Test key value
Intput: Respective probing name, hash table object, key and value
Output: Notifies if values match or not
*/
void Driver::testKeyValue(string description, HashInterface<int, int>& hashTable, const int key, const int value){
    
    const int previousCollisions = hashTable.getCollisions();

    hashTable.put(key, value);

    const int* retrievedValue = hashTable.get(key);
    const string& retrievedText = retrievedValue != nullptr ? to_string(*retrievedValue) : "null";

    outFoo1 << key << " : " << value << " -> " << retrievedText << ", collisions " << (hashTable.getCollisions() - previousCollisions) << "\n";
    
    if (retrievedValue == nullptr || *retrievedValue != value) {
        outFoo1 << "Retrieved value " << retrievedText << " does not match stored value " << value << " for key " << key << "\n";
        throw runtime_error("value mismatch");
    }
}

/*
Prints key and value
Intput: Respective probing name, order, hash table object
Output: Prints the table outputs
*/
void Driver::testTable(string order, string prober, HashInterface<int, int>& hh){

    outFoo2 << "*** "<< prober <<" Probing "<< order << " Order Start *** " << "\n\n";
    outFoo2 << "print table.size()= " << tableSize<< "\n\n";
    for(int x=0; x<tableSize; x++){
        if(hh.table[x]!=0){
             outFoo2 << "index=" << x << " key=" << hh.table[x]->key << " value=" << hh.table[x]->value <<endl;
        }
    }

    outFoo2 << "\n" <<prober << " Probing "<< hh.getCollisions() << " collisions\n";
    outFoo2 << "\n*** " << prober << " Probing "<< order << " Order End *** " << "\n\n";

}