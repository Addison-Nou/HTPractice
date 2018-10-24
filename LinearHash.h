#pragma once
#include <string>

using namespace std;

class LinearHash{
    int size;
    float alpha;
    
    public:
        LinearHash(int size, float alpha);
        void LHInsert(int key);
        int LHSearch(int key);
        int getNumAtBucket(int bucket);
        string LHConstructProbePath(int key);
};