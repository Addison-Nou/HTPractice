#include "LinearHash.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int* hashTable;

LinearHash::LinearHash(int size, float alpha){
    this->alpha = alpha;
    hashTable = new int[size];
    this->size = size;
    for (int i = 0; i < size; i++)
        hashTable[i] = -1;    //Set all elements in array to null
}

void LinearHash::LHInsert(int key){

    for (int i = 0; i < size; i++){
        int bucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;
        if (hashTable[bucket] == -1){
            hashTable[bucket] = key;
            return;
        }
    }
}

int LinearHash::LHSearch(int key){
    int bucket = (int)(floor(size * (fmod((key * alpha), 1)))) % size;
    if (hashTable[bucket] != key){ //If the key is not in the bucket
        for (int i = 0; i < size; i++){
            int nextBucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;    //Next bucket
            if (hashTable[bucket] == key)  //If the bucket value equals the key
                cout << "Linear Hash search found key at bucket: " << bucket << endl;
                return bucket;  //return the index of the bucket
        }
    } else {    //If the key is at the bucket, return it
        cout << "Linear Hash search found key at bucket: " << bucket << endl;
        return bucket;
    }
}

int LinearHash::getNumAtBucket(int bucket){
    return hashTable[bucket];
}

string LinearHash::LHConstructProbePath(int key){

    string path = "";
    
    for (int i = 0; i < size; i++){
        int bucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;
        if (hashTable[bucket] == -1){
            return path;
        }
        path = path + to_string(bucket) + " ";
    }
}