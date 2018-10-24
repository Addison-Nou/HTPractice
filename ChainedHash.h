#pragma once

class ChainedHash{
    int size;
    public:
        ChainedHash(int size);
        void CHInsert(int key);
        int CHSearch(int key);
        int getListSize(int n);
        int getNumAtIndex(int bucket, int n);
};