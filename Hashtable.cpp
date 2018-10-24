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
    

    ifstream input ("input.txt");   //Declaring input

    if (input.is_open()){   //If the file is open, then read from it
        cout << "File is open." << endl;

        input >> p;    //Grabbing input for 'p'
        cout << "Number of slots in hash table: " << p << endl;

        input >> alpha;     //Grabbing input for 'alpha'
        cout << "Alpha: " << alpha << endl;

        input >> n;     //Grabbing input for 'n'
        cout << "Number of keys to be inserted: " << n << endl;

        //Creating hash tables
        ChainedHash chash = ChainedHash(p);
        LinearHash lhash = LinearHash(p, alpha);
        DoubleHash dhash = DoubleHash(p);

        //Perform hashing for each key
        for (int i = 0; i < n; i++){
            
            input >> key;   //Grabbing input for current key
            cout << "Current key: " << key << endl;     //cout to terminal for debugging

            //Chained Hashing
            chash.CHInsert(key);

            //Linear Hash
            lhash.LHInsert(key);

            //Double Hash
            dhash.DHInsert(key);

        }

        input >> k1;    //Grabbing input for k1

        input.close();  //Closing the input
        
        cout << "Value of k1: " << k1 << endl;      //cout to terminal for debugging

        //************Creating Chain output file************

        ofstream output; //naming output

        output.open("ChainOutput.txt"); //Creating new text file for chain output
        cout << "Chain output file open" << endl;   //cout to terminal for debugging

        //Outputting values
        for (int i = 0; i < p; i++){    //Iterating through the hash table
            output << i << ":\t";
            for (int j = 0; j < chash.getListSize(i); j++){     //For each bucket in the hash table, go through the connected linked list
                output << chash.getNumAtIndex(i, j) << " ";     //Output the number at each linked list index
            }
            output << endl;
        }

        //Searching for bucket containing given input
        cout << "Searching for: " << k1 << endl;    //cout for debugging

        //Chained Hashing search
        int CHSearchOutput = chash.CHSearch(k1);    //Declaring/grabbing search output variable

        cout << "Chained search: " << CHSearchOutput << endl;   //cout for debugging
        output << CHSearchOutput;   //Writing search value to output file

        output.close(); //Closing text file

        //************Creating Linear Hash output file************

        output.open("LinearOutput.txt");    //Opening new text file for linear output
        cout << "Linear output file open" << endl;      //cout for debuggihng
        
        //Outputting values
        for (int i = 0; i < p; i++){    //For each bucket in the hash table, output the value
            output << i << ":\t";       //Formatting
            if (lhash.getNumAtBucket(i) != -1){
                output << lhash.getNumAtBucket(i) << endl;  //If the bucket isn't empty, then output the value in the bucket
            } else
                output << endl; //else print a new line
        }

        //Outputting sequence of probes for requested key
        output << lhash.LHConstructProbePath(k1);

        output.close(); //Closing text file

        //************Creating Double Hash output file************

        output.open("DoubleOutput.txt");    //Opening new text file for Double Hash output
        cout << "Double output file open" << endl;  //cout for debugging
        
        
        //Outputting values
        for (int i = 0; i < p; i++){    //For each bucket in the hash table, output the value
            output << i << ":\t";       //Formatting
            if (dhash.getNumAtBucket(i) != -1){
                output << dhash.getNumAtBucket(i) << endl;      //If the vucket isn't empty, output the value in the bucket
            } else
                output << endl;     //else print a new line
        }

        //Outputting sequence of probes for requested key
        output << dhash.DHConstructProbePath(k1);
        output.close(); //Closing the output

        cout << "Program complete" << endl; //cout for debugging
    }
}