#include "DoubleHash.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Note: DoubleHash is more or less a copy of LinearHash, with differentiating hash algorithm
DoubleHash::DoubleHash(int size){
    this->hashTable = new int[size];    //Creating hash table
    this->size = size;                  //Inputting value of size into new LHash
    for (int i = 0; i < size; i++)      //Iterating through hash table and setting initial values to -1 for 'empty bucket' checking
        hashTable[i] = -1;    //Set all elements in array to null
}

void DoubleHash::DHInsert(int key){
    for (int i = 0; i < size; i++){     //Iterate through the hash table
        int bucket = ((key % size) + i * (1 + (key % (size - 2)))) % size;  //Hashing algorithm
        if (hashTable[bucket] == -1){   //If the bucket is empty
            hashTable[bucket] = key;    //Insert the key into the bucket
            return;                     //Return to exit the loop
        }
    }
}

int DoubleHash::DHSearch(int key){
    for (int i = 0; i < size; i++){
        int bucket = ((key % size) + i * (1 + (key % (size - 2)))) % size;    //Hash algorithm
        if (hashTable[bucket] == key){  //If the bucket value equals the key
            cout << "Double Hash search found key at bucket: " << bucket << endl;   //cout for debug
            return bucket;  //return the index of the bucket
        }
    }
}

//Getter to return the value at the desired bucket
int DoubleHash::getNumAtBucket(int bucket){
    return hashTable[bucket];
}

//Modified DHInsert to return a string instead of void
string DoubleHash::DHConstructProbePath(int key){

    string path = "";   //Instantiating new string
    
    for (int i = 0; i < size; i++){     //Iterate through the hash table
        int bucket = ((key % size) + i * (1 + (key % (size - 2)))) % size;  //Hashing algorithm
        if (hashTable[bucket] == key){      //If the desired key has been found
            path = path + to_string(bucket);    //Add the final bucket to the path
            return path;                        //Return the path
        }
        path = path + to_string(bucket) + " ";  //else add the bucket to the path and continue the loop
    }
}