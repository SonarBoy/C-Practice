#include <iostream>
#include "node.cpp"
using namespace std;

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

//DELETION OF A NODE AT A GIVEN POSITION.
void deleteNode(struct Node **head_ref, int position)
{
    //If the list is empty just return null
    if(*head_ref == NULL)
        return;


    //Here we creat a temp holder for the node to 
    //be able to reference it later without messing up the array.
    struct Node* temp = *head_ref;

    //If we are just removing the head then all we need to do 
    //is free up the position that head is attached to. 
    //We would just take the next of temp which in this case would be 
    //NULL, reassing it to the head and then 
    //free it up
    if(position == 0)
    {
        *head_ref = temp -> next;
        free(temp);
        return;
    }


    //Here we are just running though the next pointers to find the correct 
    //position to delete the node. We assing the next value for the temp variable
    //based on the itteration of the position and the fact that its not null.
    for(int runner = 0; temp != NULL && runner < position - 1; runner++)
    {
        temp = temp -> next;
    }


    //If we go out of bounds with the position
    if(temp == NULL || temp -> next == NULL){
        return;
    }

    //Create a new item that references the nodes pointer 
    //two spaces down.
    struct Node *nextItem = temp -> next -> next;

    //Free up the node one space down.
    free(temp -> next);

    //the head value point to the nodes after the deleteion.
    //temp -> next -> next;
    temp -> next = nextItem;


}

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
        cout << endl;
    } 
} 
  



int main(){

    struct Node* head = NULL;

    for(int runner = 0; runner < 10; runner++){
        push(&head,runner);
    }
    
    printList(head);

    cout << "After deletion: " << endl;
    deleteNode(&head,3);

    printList(head);

    return 0;
}