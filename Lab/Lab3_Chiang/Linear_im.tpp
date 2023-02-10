//implementation file for Linear

#include "Linear.h"

/*
Constructor
Input: Initialize table size 
Output: Sets table sze and collision count
*/
template <typename Key, typename Value>
LinearProbingHash<Key, Value>::LinearProbingHash(int tbsize){
    this->table.resize(tbsize);
    this->collisions = 0;
}

/*
Destructor
Input: N/A
Output: N/A
*/
template <typename Key, typename Value>
LinearProbingHash<Key, Value>::~LinearProbingHash(){
    for (const auto& p : this->table)
        delete p;
}

/*
Finds key in Hash Table and perform Linear Probing
Input: Key
Output: Index of respective key in Hash Table
*/
template <typename Key, typename Value>
int LinearProbingHash<Key, Value>::lookUp(const Key& key){
    const int startIndex = this->hashIndex(key);
    int index = startIndex;

    while (true){
        const Record<Key,Value> *p = this->table[index];

        if (p == nullptr || p->key == key){
            return index;
        }

        this->collisions += 1;
        index += 1;
        index %= this->table.size();

        if (index == startIndex){
            return (this->table.size() + 1);
        }
    }
}
