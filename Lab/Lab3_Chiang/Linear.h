#ifndef Linear_h
#define Linear_h

#include "HashInterface.h"

template <typename Key, typename Value>
class LinearProbingHash : public HashInterface<Key, Value>
{
    public:
        LinearProbingHash(int tbsize);
        
        ~LinearProbingHash();
        
        int lookUp(const Key& key);
};

#include "Linear_im.tpp"

#endif
