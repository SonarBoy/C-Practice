#include <iostream>
#include "Node.cpp"
using namespace std;

void push(struct Node** head_ref, int new_data){

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;

}

void append(struct Node** head_ref, int new_data){

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node -> data = new_data;
    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last -> next != NULL){
        last = last -> next;
    }

    last -> next = new_node;
    return;
}

void deleteNode(struct Node **head_ref, int position){

    if(*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    if(position == 0){
        *head_ref = temp -> next;
        free(temp);
        return;
    }

    for(int runner = 0; temp != NULL && runner < position - 1; runner++){
        temp = temp -> next;
    }

    if(temp == NULL || temp -> next == NULL){
        return;
    }

    struct Node *nextItem = temp -> next -> next;

    free(temp -> next);

    temp -> next = nextItem;
}


int counterInt(struct Node **head_ref,int number){

    int counter = 0;
    if(*head_ref == NULL){
        return -1;
    }

    struct Node* temp = *head_ref;

    while(temp != NULL){

        if(temp -> data == number){
            counter++;
        }
        temp = temp -> next;
    }

    return counter;
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


//The function removes duplicates from a sorted linked list
/*
* Time Complexity: O(n) where n is number of nodes in the given linked list.
*/
void removeDuplicates(Node* head)
{   
    //Declare Pointer to Traverse the linked list
    Node* current = head;

    // the next pointer of a node to be deleted
    Node* next_next;

    //List is empty
    if(current == NULL)
    return;

    //While you can still find values in the list
    while(current -> next != NULL)
    {   
        //Compares the current with the next node
        if(current -> data == current -> next -> data){

            //!Get the next next's nodes value 
            //!Free the next node
            //!reattach the remaining node.
            next_next = current->next->next;
            free(current -> next);
            current -> next = next_next;
        }else{

        //Advance the loop
        current = current -> next;
        }     
    }
}

//The function removes duplicates froma sorted array recursivly
void removeDuplicatesRecursively(Node* head){

    //Pointer to store the pointer of a node
    Node* to_free;

    //If the list is empty.
    if(head == NULL)
    return;


    //Traverse the list till last node 
    if(head->next != NULL){

        //if the next element has the same value
        //as the current value
        if(head -> data == head -> next -> data){

                to_free = head -> next;
                head -> next = head->next->next;
                free(to_free);
                removeDuplicatesRecursively(head);
        }else{
            removeDuplicatesRecursively(head -> next);
        }
        
    }
}



void removeDuplicatesUnsorted(struct Node * start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while(ptr1 != NULL && ptr1 -> next != NULL){
        ptr2 = ptr1;

        while(ptr2 -> next != NULL){

            if(ptr1 -> data == ptr2 -> next -> data){

                dup = ptr2 -> next;
                ptr2 -> next = ptr2 -> next -> next;
                delete(dup);
            }
            else{
                ptr2 = ptr2 -> next;
            }

            
        }

        ptr1 = ptr1 -> next;
    }
}









int main(){

    Node* head = NULL;

    push(&head, 20);  
    push(&head, 13);  
    push(&head, 13);  
    push(&head, 11);  
    push(&head, 11);  
    push(&head, 11);

    cout<<"Linked list before duplicate removal ";  
    printList(head);  

    removeDuplicatesUnsorted(head); 

    cout<<"\nLinked list after duplicate removal ";      
    printList(head);   

}