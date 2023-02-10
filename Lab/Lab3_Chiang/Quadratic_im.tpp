//implementation file for Quadratic

#include "Quadratic.h"

/*
Constructor
Input: Initialize table size 
Output: Sets table sze and collision count
*/
template <typename Key, typename Value>
QuadraticProbingHash<Key, Value>::QuadraticProbingHash(int tbSize)
{
    this->table.resize(tbSize);
    this->collisions = 0;
}

/*
Destructor
Input: N/A
Output: N/A
*/
template <typename Key, typename Value>
QuadraticProbingHash<Key, Value>::~QuadraticProbingHash(){
    for (const auto p : this->table){
        delete p;
    }
}

/*
Finds key in Hash Table and perform Quadratic Probing
Input: Key
Output: Index of respective key in Hash Table
*/
template <typename Key, typename Value>
int QuadraticProbingHash<Key, Value>::lookUp(const Key& key){
    const int startIndex = this->hashIndex(key);
    int index = startIndex; 
    int j = 0;

    while (true){
        const Record<Key, Value> *p = this->table[index];

        if (p == nullptr || p->key == key){
            return index;
        }

        j += 1;
        this->collisions += 1;

        index = startIndex + j * j;
        index %= this->table.size();

        if (index == startIndex){
            return (this->table.size() + 1);
        }
    }
}
