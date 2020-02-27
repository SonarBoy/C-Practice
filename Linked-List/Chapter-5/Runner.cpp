#include <iostream>
#include "node.cpp"


void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  
void deleteNode(struct Node **head_ref, int key)
{   
    //This creates a two new nodes that has the value
    //of head
    struct Node* temp = *head_ref, *previous;


    //If the value of tem is the key we are going to delete
    //it right of the bat here.
    if(temp != NULL && temp -> data == key){
        *head_ref = temp -> next;
        free(temp);
        return;
    }

    //If temp is not equal to null and the key 
    //is not been found we are going to cycle through 
    //the loop until it is.
    while(temp != NULL && temp -> data != key){

        //Assinging the new value of temp to the 
        //previous value while iterating with temp -> next
        previous = temp;
        temp = temp -> next;
    }

    //If the value was not present in the linklist.
    if(temp == NULL)
    {
        return;
    }

    //Here we make the previous nodes pointer point 
    // to the next value of temp.
    previous -> next = temp -> next;

    //Finally free temp
    free(temp);
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