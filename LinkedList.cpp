#include <iostream>
#include "LinkedList.h"

using namespace std;

class LinkedList{
    
    Node* head, *tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void addNode(int data){
        Node* add = new Node();
        Node* curr = head;

        add->data = data;
        add->next = NULL;

        while (curr->next != NULL){ //Keep walking until we reach the end of the list
            curr = curr->next;
        }

        curr->next = add;
    };

    void deleteNode(int data){

        Node* del;
        Node* temp = head;
        Node* curr = head;

        while (curr != NULL && curr->data != data){ //If we haven't walked off the list and our current node's data doesn't hold the thing we want to delete
            temp = curr;
            curr = curr->next;
        }
        if (curr == NULL){  //we've walked off the list
            cout << "Walked off the list; The data " << data << " was not on the list." << endl;
        } else {
            del = curr;
            delete del;
            curr = curr->next;
            temp->next = curr;
            cout << "Deleted node containing " << data << "." << endl;
        }
    };

};