#include <iostream>
#include "node.cpp"

using namespace std;

void deleteList(Node** head_ref)
{   
    //Here we dereference the head reference to get the real
    //head
    Node* current = *head_ref;
    Node* next;

    //Cycle through the pointers and free up the current pointer
    //and will stop if we hit a NULL the increment is done by updating 
    //current to the new value
    while(current != NULL)
    {
        next = current -> next;
        free(current);
        current = next;
    }

    //Deref the the head_ref to affect the real head back to the caller.
    *head_ref = NULL;
}





void push(Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data;  
      
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
      
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  



int main(){
    
    /* Start with the empty list */
    Node* head = NULL;  
      
    /* Use push() to construct below list  
    1->12->1->4->1 */
    push(&head, 1);  
    push(&head, 4);  
    push(&head, 1);  
    push(&head, 12);  
    push(&head, 1);  
      
    cout << "Deleting linked list";  
    deleteList(&head);  
      
    cout << "\nLinked list deleted";  
   
    
    return 0;
}