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
    hashTable[bucket].push_front(key);   //insert the key at the location of the bucket
}

int ChainedHash::CHSearch(int key){
    int bucket = key%size;
    list <int> :: iterator i;
    int indexOf = 0;
    for (i = hashTable[bucket].begin(); i != hashTable[bucket].end(); i++){  //Check the hash table at the bucket from beginning to end for the key
        if (*i == key){
            //cout << "Chaining Search found index at bucket [" << bucket << "], list index [" << indexOf << "]" << endl; 
            return bucket;
        }
        indexOf++;
    }
}

int ChainedHash::getListSize(int n){
    //cout << "Size of list: " << hashTable[n].size();
    //cout << endl;
    return hashTable[n].size();
}

int ChainedHash::getNumAtIndex(int bucket, int n){
    //cout << "Grabbing int at bucket " << bucket << ", index " << n << endl;
    list <int> :: iterator i;
    i = hashTable[bucket].begin();
    std::advance(i, n);
    //cout << "Int at bucket " << bucket << ", index " << n << ": " << *i << endl;
    return *i;
}