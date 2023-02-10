//implementation file for Hash

#include "HashInterface.h"
using namespace std;


/*
Gets corresponding value based on key
Input: key
Output: value or null
*/
template <typename Key, typename Value>
Value* HashInterface<Key, Value>::get(const Key& key){
    int index = lookUp(key);

    if (index > table.size()){
        return nullptr;
    }

    Record<Key,Value> *p = table[index];
    return p ? &(p->value):nullptr;
}

/*
Puts corresponding key and valye to hash table
Input: key and value
Output: puts in hash
*/
template <typename Key, typename Value>
void HashInterface<Key, Value>::put(const Key& key, const Value& value){
    int index = lookUp(key);

    if (index > table.size()){
        throw runtime_error("Table is full");
    }

    Record<Key, Value> *p = table[index];

    if (p == nullptr){
        table[index] = new Record<Key, Value>(key, value);
    }
    else{
        p->value = value;
    }
}

/*
Get collisions
Input: N/A
Output: returns # of collisions
*/
template <typename Key, typename Value>
int HashInterface<Key, Value>::getCollisions() const{
    return collisions;
}

/*
hash function
Input: key
Output: key
*/
template <typename Key, typename Value>
int HashInterface<Key, Value>::hash(const Key& key){
    return (key >> 8) | ((key& 0xff) << 16);
}

/*
hash index
Input: key
Output: hashed index of key
*/
template <typename Key, typename Value>
int HashInterface<Key, Value>::hashIndex(const Key& key) const {
    const int index = hash(key);
    return index % table.size();
}

/*
Look for key in hash table
Input: key
Output: index of key
*/
template <typename Key, typename Value>
int HashInterface<Key, Value>::lookUp(const Key& key){
    return 0;   
}
