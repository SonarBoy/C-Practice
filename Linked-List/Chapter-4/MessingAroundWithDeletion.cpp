#include <iostream>
#include "node.cpp"
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

int main(){
    

    Node* head = NULL;

    int number = 0;
    int marker = 0;
    
    while(true){

    int runner = 0;


    cout << endl << "Enter a number of elements to insert: " << endl;
    cin >> number;
    cout << endl;
    cout << endl << "Enter the mod of elements you want to mark: " << endl;
    cin >> marker;
    cout << endl;
    




    for(int runner = 0; runner < number; runner++){

        //appendWithMarker(&head,rand() % 100,marker);
        //append(&head,rand() % 100);
        append(&head,100);

    }

    cout << "Print: " << endl;
    printList(head);

    cout << endl;
    cout << endl;

    deleteNode(&head,marker);

    cout << endl;
    cout << endl;    

    cout << "Print: " << endl;
    printList(head);

    cout << "Number Of Ouccorences of the Marker: " << counterInt(&head,100);
    ;

    runner = 0;
    number = 0;
    marker = 0;
    }


}