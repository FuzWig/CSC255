#ifndef HASHINTERFACE_H
#define HASHINTERFACE_H
#include <vector>

using namespace std;

/*
Constructor
Input: setkey 
Output: set value
*/
template <typename Key, typename Value>
struct Record{
    Key key;
    Value value;

    Record(const Key& key1, const Value& value1){
        this->key = key1;
        this->value = value1;
    }
};

template <typename Key, typename Value>
class HashInterface
{
    public:
        int collisions;            
        vector<Record<Key, Value>*> table;

        Value* get(const Key& key);

        void put(const Key& key, const Value& value);

        int getCollisions() const;

        static int hash(const Key& key);

        int hashIndex(const Key& key) const;

        virtual int lookUp(const Key& key);           //polymorphism to use respective loopUp from specific hash method

        virtual ~HashInterface() {}                  //polymorphism to use respective Hash from specific hash method
};

#include "HashInterface_im.tpp"

#endif
