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


struct LinkedList{

    Node* head;
    LinkedList(){
        head = NULL;
    }

    void reverse(){
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while(current != NULL){

            next = current -> next;

            current -> next = prev;

            prev = current;
            current = next;
        }

        head = prev;
        
    }


    void print(){
        struct Node* temp = head;

        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    void push(int data){
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
};

void reverse(struct Node **head){
        Node* current = *head;
        Node *prev = NULL, *next = NULL;

        while(current != NULL){

            next = current -> next;

            current -> next = prev;

            prev = current;
            current = next;
        }

        *head = prev;
        
}


int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL;

    push(&head,20); 
    push(&head,4); 
    push(&head,15); 
    push(&head,85); 
  
    cout << "Given linked list\n"; 
    printList(head); 
  
    reverse(&head); 


  
    cout << "\nReversed Linked list \n"; 
    printList(head); 
    
    return 0; 
} 