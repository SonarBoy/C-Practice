#include <iostream>
#include "node.cpp"

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 

void printNthFromLast(struct Node* head, int n)
{
    //Here we declare our counter variables
    //Where len will be the length of the list
    //Where temp will be our reference to the head.
    int len = 0;
    struct Node* temp = head;


    //Cycle through the list to get the count of the list
    while(temp != NULL)
    {
        temp = temp -> next;
        len++;
    }

    //If the len calculated is not greater than the index 
    //that we want to find then we return notthing
    if(len < n){
        return;
    }

    //Rereference the temp to run through the list.
    temp = head;    

    //(len - n + 1) references the nth node from the head of the list.
    //in Chapter 8 we did the exact same thing with the recursive method.
    for(int runner = 1; runner < len - n + 1;runner++){
            temp = temp -> next;
    }

    cout << temp -> data;

    return;

}


void printNthFromLast_Recursive(struct Node* head, int n)
{
    static int i = 0;

    //If the head is equal to null we know that we have gone
    //to far
    if(head == NULL)
    {
        return;
    }
    
    //Here we just simply cycle though the linked list by calling the function
    //because head is not equal NULL;
    printNthFromLast_Recursive(head->next,n);

    //If the int that we declared which is static meaning that we are 
    //the memory is allocated only once so each pass through we are incrementing it
    //when the two numbers are equal we will print out the result.
    if(++i == n)
    {
        printf("%d", head->data);
    }

}


void printNthFromLast_Pointer(struct Node *head, int n)
{   
    //Declare the two pointer variables.
    struct Node *main_ptr = head;
    struct Node *ref_ptr = head;

    int count = 0;

    
    if(head != NULL)
    {
        //The first loop will iterate through the counter.
        while(count < n)
        {
            if(ref_ptr == NULL)
            {
                printf("%d is greater than the no. of nodes in list", n); 
                return;
            }
        

            ref_ptr = ref_ptr -> next;
            count++;
        }

        //Cycles through the rest of the linked list to find the last
        //element.
        while(ref_ptr != NULL)
        {
            main_ptr = main_ptr -> next;
            ref_ptr = ref_ptr -> next;
        }

        printf("Node no. %d from last is %d ", n, main_ptr->data); 
    }

}


int main()
{

    struct Node* head = NULL; 
  
    
    // create linked 35->15->4->20 
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 
  
    printNthFromLast_Recursive(head, 4); 
    

    //struct Node* head = NULL; 
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 
  
    printNthFromLast_Pointer(head, 4); 
     
    
    
}