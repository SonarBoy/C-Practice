#include <iostream>
#include "node.cpp"

using namespace std;

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

bool search(Node* head, int x)
{    
    //Create a new pointer to the head for itteration
    Node* current = head;

    //While the current node is not equal to null we run
    //the loop
    while(current != NULL)
    {   
        //If the data is the same as the key exit.
        if(current -> data == x){
            return true;
        }

        //Itterate through the linked list
        current = current -> next;
    }

    return false;
}

bool search_Recursive(struct Node* head, int x)
{
    if(head == NULL){
        return false;
    }

    if(head -> data = x){
        return true;
    }

    //SEE HOW THE ITERATION IS DONE IN THE FUCNTION CALL
    //TO THE NEXT FUNCTION
    return search_Recursive(head->next,x);
}

int main()
{   
    struct Node* head = NULL;

    int x = 8;


    int unknown = rand() % 100;

    for(int runner = 1; runner < unknown; runner++){
        push(&head,runner);
    }

    search(head, x)? cout << "Yes" : cout << "No";  
    search(head, x)? cout << "Yes" : cout << "No";  

    return 0;
}