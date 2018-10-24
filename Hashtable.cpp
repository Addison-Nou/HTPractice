#include <iostream>
#include <fstream>
#include "ChainedHash.h"
#include "LinearHash.h"
#include "DoubleHash.h"
#include <string>

using namespace std;

int main()
{
    int p; //number of slots in the hash table
    int n; //number of keys to be inserted into the hash table
    float alpha;
    int key;    //current key to insert
    int k1;   //number to use in later functions
    

    ifstream input ("input.txt");

    if (input.is_open()){
        cout << "File is open." << endl;

        input >> p;
        cout << "Number of slots in hash table: " << p << endl;

        input >> alpha;
        cout << "Alpha: " << alpha << endl;

        input >> n;
        cout << "Number of keys to be inserted: " << n << endl;

        //Creating hash tables
        ChainedHash chash = ChainedHash(p);
        LinearHash lhash = LinearHash(p, alpha);

        //Perform hashing for each key
        for (int i = 0; i < n; i++){
            
            input >> key;
            cout << "Current key: " << key << endl;

            //Chained Hashing
            chash.CHInsert(key);

            //Linear Hash
            lhash.LHInsert(key);

            //Double Hash

        }

        input >> k1;
        cout << "Value of k1: " << k1 << endl;

        //************Creating Chain output file************

        ofstream output; //naming output

        output.open("ChainOutput.txt");
        cout << "Chain output file open" << endl;

        //Outputting values
        for (int i = 0; i < p; i++){
            output << i << ":\t";
            for (int j = 0; j < chash.getListSize(i); j++){ //For each bucket in the hash table, go through the linked list
                output << chash.getNumAtIndex(i, j) << " ";
                //cout << chash.getNumAtIndex(i, j) << " ";
            }
            output << endl;
        }

        //Searching for bucket containing given input

        cout << "Searching for: " << k1 << endl;

        //Chained Hashing search
        int CHSearchOutput = chash.CHSearch(k1);

        cout << "Chained search: " << CHSearchOutput << endl;
        output << CHSearchOutput;

        output.close();

        //************Creating Linear Hash output file************

        output.open("LinearOutput.txt");
        cout << "Linear output file open" << endl;
        
        //Outputting values
        for (int i = 0; i < p; i++){    //For each bucket in the hash table, output the value
            output << i << ":\t";
            if (lhash.getNumAtBucket(i) != -1){
                output << lhash.getNumAtBucket(i) << endl;
            } else
                output << endl;
        }

        //Outputting sequence of probes for requested key
        output << lhash.LHConstructProbePath(k1);

        output.close();

        cout << lhash.getNumAtBucket(0) << endl;
        cout << lhash.getNumAtBucket(1) << endl;
        cout << lhash.getNumAtBucket(5) << endl;
        cout << lhash.getNumAtBucket(10) << endl;
    }
}