#include "HashTable.h"

size_t HashTable:: HashFunc(const Key& key){
    size_t hashValue = 0;
    size_t size = key.size();
    for(size_t i = 0; i < size; i++){
        hashValue += static_cast<size_t>(key[i]);
    }

    return hashValue;
}