//implementation file for Double

#include "Double.h"

/*
Constructor
Input: Initialize table size and 
Output: Sets table sze and collision count
*/
template <typename Key, typename Value>
DoubleProbingHash<Key, Value>::DoubleProbingHash(int tbSize, int doubles){
    this->dF = doubles;
    this->table.resize(tbSize);
    this->collisions = 0;
}

/*
Destructor
Input: N/A
Output: N/A
*/
template <typename Key, typename Value>
DoubleProbingHash<Key, Value>::~DoubleProbingHash(){
    for (const auto& p : this->table)
        delete p;
}


/*
Hash Key second time
Input: 1st hashed key
Output: 2nd hashed key
*/
template <typename Key, typename Value>
int DoubleProbingHash<Key, Value>::rehash(const Key& key){
    int index = this->hash(key);

    return dF-(index % dF);
}

/*
Finds key in Hash Table and perform Double Probing
Input: Key
Output: Index of respective key in Hash Table
*/
template <typename Key, typename Value>
int DoubleProbingHash<Key, Value>::lookUp(const Key& key){
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

        index = (j * rehash(key) + startIndex);
        index %= (this->table.size());

        if (index == startIndex){
            return (this->table.size() + 1);
        }
    }
}


