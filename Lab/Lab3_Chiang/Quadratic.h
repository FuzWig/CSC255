#ifndef Quadratic_h
#define Quadratic_h

#include "HashInterface.h"

template <typename Key, typename Value>
class QuadraticProbingHash : public HashInterface<Key, Value>
{
    public:
        QuadraticProbingHash(int tbSize);
        
        ~QuadraticProbingHash();

        int lookUp(const Key& key);
};

#include "Quadratic_im.tpp"

#endif
