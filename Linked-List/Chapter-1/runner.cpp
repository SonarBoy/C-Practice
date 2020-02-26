#include <iostream>
#include "node.cpp"

using namespace std;



void printList(Node* n){
    while(n != NULL){
        cout << n -> data << " " << endl;
        cout << &n -> data << endl;
        n = n -> next;
    }
}




int main(){

    cout << "Simple Linked List Example: " << endl;

    /*
    Three blocks have been allocated and we have pointers to 
    those blocks. 

    Data is random because we have not assinged anything yet.
    */

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head -> data = 1; //Assign data in the first node.
    head -> next = second; //Link to second node.

    second -> data = 2; //Assign data in the third node.
    second -> next = third; //Link to third node.

    third -> data = 3;
    third -> next = NULL;


    printList(head);

}