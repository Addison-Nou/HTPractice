#include "LinearHash.h"
#include <iostream>
#include <cmath>

using namespace std;

class LinearHash{

    int* hashTable;
    int size;
    float alpha;

    LinearHash(int size, float alpha){
        this->alpha = alpha;
        hashTable = new int[size];
        this->size = size;
        for (int i = 0; i < size; i++)
            hashTable[i] = NULL;    //Set all elements in array to 0
    }

    int LHInsert(int key)
    {
        int bucket = (int)(floor(size * (fmod((key * alpha), 1)))) % size;
        if (hashTable[bucket] != NULL){ //If there is already a value in the bucket
        for (int i = bucket; i < size; i++){
            int nextBucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;    //Next bucket
            if (hashTable[bucket] == NULL)  //If the bucket is empty
                hashTable[bucket] = key;    //Insert key into the empty bucket
        }
            //There is no empty space; cannot insert key
            cout << "All buckets full, cannot insert " << key << endl;
        }
    }

    int LHSearch(){
        
    }

};