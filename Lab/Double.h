
#ifndef Double_h
#define Double_h

#include "HashInterface.h"

template <typename Key, typename Value>
class DoubleProbingHash : public HashInterface<Key, Value>{
public:
    int dF;

    DoubleProbingHash(int tbSize, int doubles);

    ~DoubleProbingHash();
        
    int rehash(const Key& key);    
    
    int lookUp(const Key& key);
};

#include "Double_im.tpp"

#endif