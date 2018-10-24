#include <iostream>
#include <fstream>
#include "ChainedHash.h"
#include "LinearHash.h"
#include "DoubleHash.h"

using namespace std;

int main()
{
    int p; //number of slots in the hash table
    int n; //number of keys to be inserted into the hash table
    float alpha;
    int key;    //current key to insert
    int search;   //number to search for
    

    ifstream input ("input.txt");

    if (input.is_open()){
        cout << "File is open." << endl;

        input >> p;
        cout << "Number of slots in hash table: " << p << endl;

        input >> alpha;
        cout << "Alpha: " << alpha << endl;

        input >> n;
        cout << "Number of keys to be inserted: " << n << endl;

        ChainedHash chash = ChainedHash(p);

        //Perform hashing for each key
        for (int i = 0; i < n; i++){
            
            input >> key;
            cout << "Current key: " << key << endl;

            //Chained Hashing
            chash.CHInsert(key);

            //Linear Hash


            //Double Hash

        }

        input >> search;

        cout << "Searching for: " << search << endl;

        //Chained Hashing search
        int CHSearchOutput = chash.CHSearch(search);
        cout << "Chained search: " << CHSearchOutput << endl;
    }
}