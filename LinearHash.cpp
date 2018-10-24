#include "LinearHash.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

LinearHash::LinearHash(int size, float alpha){  //Constructur for linear hash
    this->alpha = alpha;                //Inputting value of alpha into new LHash
    this->hashTable = new int[size];    //Creating hash table
    this->size = size;                  //Inputting value of size into new LHash
    for (int i = 0; i < size; i++)      //Iterating through hash table and setting initial values to -1 for 'empty bucket' checking
        hashTable[i] = -1;    //Set all elements in array to null
}

void LinearHash::LHInsert(int key){

    for (int i = 0; i < size; i++){     //Iterate through the hash table
        int bucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;    //Hashing algorithm
        if (hashTable[bucket] == -1){   //If an empty space is found
            hashTable[bucket] = key;    //Insert the key
            return; //return to break out of loop
        }
    }
}

int LinearHash::LHSearch(int key){
    for (int i = 0; i < size; i++){
        int bucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;    //Next bucket
        if (hashTable[bucket] == key){  //If the bucket value equals the key
            cout << "Linear Hash search found key at bucket: " << bucket << endl;   //Error checking
            return bucket;  //return the index of the bucket
        }  
    }
}

//Getter to return the value at the desired bucket
int LinearHash::getNumAtBucket(int bucket){
    return hashTable[bucket];
}

//Modified LHInsert to return a string instead of void
string LinearHash::LHConstructProbePath(int key){

    string path = "";   //New string
    
    for (int i = 0; i < size; i++){     //Iterate through the hash table
        int bucket = (int)((floor(size * (fmod((key * alpha), 1)))) + i) % size;    //Hashing algorithm
        if (hashTable[bucket] == key){      //If the bucket is equal to the key
            path = path + to_string(bucket);    //add the bucket index to the path
            return path;                        //return the path
        }
        path = path + to_string(bucket) + " ";  //else, add the bucket index to the path and continue the loop
    }
}