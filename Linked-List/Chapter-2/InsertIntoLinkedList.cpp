#include <iostream>
#include "node.cpp"

using namespace std;


/* Inserting into Linked Lists.

The push function inserts a new node at the head of the 
list. NOTE: The push() must receive a pointer to the head 
pointer because push must change the head pointer to point 
to the new node.


*/

void push(Node** head_ref,int new_data){

    //Allocate the new Node.
    Node* new_node = new Node();

    //Put the data into the new node
    new_node -> data = new_data;

    //Make next of the new node as head
    new_node -> next = (*head_ref);

    //Move the head to point to the new node. 
    //Which would be the next item in the linked list.
    (*head_ref) = new_node;

}

void insertAfter(struct Node* prev_node, int new_data){

    //Check to see if the previous node is null
    //and if it is break out of the function.
    if(prev_node == NULL){
        cout << "the given previous node cannot be NULL" << endl;
        return;
    }

    //Allocate the new node.
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    //Put in the data.
    new_node->data = new_data;

    //Make the next of the prevoius node be 
    //the next of the new node.
    new_node -> next = prev_node -> next;

    //move the next of the previous node to be 
    //the next value of the new node.
    prev_node -> next = new_node;

}



void append(struct Node** head_ref, int new_data)
{
    //Allocate the new Node
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    //Used in the later step to determine if 
    //its going to be the last node.
    struct Node *last = *head_ref; 

    //Assign data to the new node.
    new_node -> data = new_data;

    //Assing the next value of the node in this case its null
    //because we are appending to the list.
    new_node -> next = NULL;

    //If the linkedlist is empty then make the new node as the head.
    if(*head_ref == NULL)
    {  
        *head_ref = new_node;
        return;
    }


    //This loop cycles through to find the last value.
    while(last -> next != NULL){
        last = last->next;
    }   

    //Assign the last value to the new node
    last -> next = new_node;
    return;
}

void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}  
  



int main()
{
    Node* head = NULL;

    append(&head, 999); //Since the list is empty we just add to the head.
    push(&head,999); // add to the head.
    push(&head,999); // add to the head.

    cout << "Created Linked list is: " << endl;  
    printList(head);  
    cout << endl;
    
    //Here we just add to the top again but in reverse order.
    for(int runner = 0;runner < 10;runner++){
        push(&head,runner);
    }

    cout << "Created Linked list is: " << endl;  
    printList(head);  
    cout << endl;

    //Here we add to the back in reverse order.
    for(int runner = 0;runner < 10;runner++){
        append(&head,runner);
    }

    cout << "Created Linked list is: " << endl;  
    printList(head);  
    cout << endl;

    //Creating a new node so we can add it anywhere to the list.
    Node* inserter = head;

    //Here we increment the value to where it should be pointing to. 
    for(int runner = 0; runner < 15; runner++){
        inserter = inserter -> next;
    }

    cout << "Created Linked list is: " << endl;  
    printList(head);  
    cout << endl;

    //Finally we insert the element.
    insertAfter(inserter, 8888);

    cout<<"Created Linked list is: ";  
    printList(head);  
    cout << endl;

}