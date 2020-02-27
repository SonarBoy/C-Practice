#include <iostream>
#include "node.cpp"

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 


int GetNth(Node* head,int index)
{
    Node* current = head;

    int count = 0;

    while(current != NULL)
    {
        if(count == index){
            return(current -> data);
        }
        count++;
        current = current -> next;
    }

    return 0;
}


int GetNth_Recursive(Node* head, int index)
{   
    //Any variable that is declared in the top of the function 
    //should usually play into the bottoming out point 
    int holder = 0;

    //Holder must equal the index because its the index we are counting 
    //down from 
    if(holder == index){
        return head -> data;
    }

    //We say -1 to the index because we are going down the list to the element
    //not incrementing it to the element
    return  GetNth_Recursive(head -> next,index - 1);
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
  

int main()
{

      struct Node* head = NULL; 
     
    /* Use push() to construct below list 
     1->12->1->4->1  */
    push(&head, 1); 
    push(&head, 4); 
    push(&head, 1); 
    push(&head, 12); 
    push(&head, 1);   
     
    /* Check the count function */
    printf("Element at index 3 is %d", GetNth_Recursive(head, 3));   
    cout << endl;
    printList(head);
    
}