#pragma once

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    public:
        LinkedList();
        void addNode();
        void deleteNode();
};