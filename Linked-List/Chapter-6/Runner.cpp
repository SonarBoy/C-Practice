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





int getCount(Node* head)
{
    // Initialize count as 0
    int count = 0;

    // Initialize a node pointer, current = head.
    Node* current = head;


    // Do following while current is not NULL
    //  a) current = current -> next  
    //  b) count++;
    while(current != NULL)
    {
        count++;
        current = current -> next;
    }

    // Return count
    return count;
}

// How recursive method works
int getCount_Recursive(struct Node* head)
{
    //BOTTOM OUT CONDITION YOU END THE CALL
    if(head == NULL)
        return 0;

    //OTHERWISE YOU ARE GOING TO BE DOING THE WORK ON THE 
    //RETURN STATEMENT TO THE NEXT FUNCTION CALL.
    return 1 + getCount(head->next);
}

int super_Add_Recursive(struct Node* head)
{
    int x = 0;

    if(head == NULL){
        return 0;
    }

    return x = head-> data + super_Add_Recursive(head -> next);
}


int main(){
    struct Node* head = NULL;

    int unknown = rand() % 100;

    for(int runner = 1; runner < unknown; runner++){
        push(&head,runner);
    }

    

    cout << "Iterative count : " << getCount(head) << endl;
    cout << "Recursive count : " << getCount_Recursive(head) << endl;
    cout << "Recursive addition : " << super_Add_Recursive(head) << endl;
}