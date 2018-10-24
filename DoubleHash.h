#pragma once
#include <string>

using namespace std;

class DoubleHash{
    int size;
    int* hashTable;
    
    public:
        DoubleHash(int size);
        void DHInsert(int key);
        int DHSearch(int key);
        int getNumAtBucket(int bucket);
        string DHConstructProbePath(int key);
};