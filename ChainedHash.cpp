#include "ChainedHash.h"
#include <iostream>
#include <list>

using namespace std;

list<int> *hashTable;

ChainedHash::ChainedHash(int size){
    hashTable = new list<int>[size];    //Creating the hash table
    this->size = size;
}

void ChainedHash::CHInsert(int key)
{
    int bucket = key%size;   //index of the place we want to insert
    hashTable[bucket].push_back(key);   //insert the key at the location of the bucket
}

int ChainedHash::CHSearch(int key){
    int bucket = key%size;
    list <int> :: iterator i;
    int indexOf = 0;
    for (i = hashTable[bucket].begin(); i != hashTable[bucket].end(); i++){  //Check the hash table at the bucket from beginning to end for the key
        if (*i == key){
            cout << "Found index: " << indexOf << endl; 
            return indexOf;
        }
        indexOf++;
    }
}