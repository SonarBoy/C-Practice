/*  
Priority Queue's 
- Priority Queue is an extension of queue with following properties.


    1) Every item has a priority associated with it.

    2) An element with high priority is dequeued before an element
    with low priority.

    3) If two elements have the same priority, they are served 
    according to their order in the queue.

Some of the operations that they follow:
 
    insert(item, priority): Inserts an item with given priority.

    getHighestPriority(): Returns the highest priority.

    deleteHighestPriority(): Removes the highest priority item.


Applications of Priority Queue:

    1) CPU Scheduling.
    2) Graph algorithms like Dijkstra's shortest path algorithm.
    3) All queue applications where priority is involved.

Operations on Priority Queue:

    push(): This function is used to insert a new data element
    into the queue.

    pop(): This function removes the element with the highest priority 
    element in the queue without removing it from the queue.

*/

#include <iostream>
using namespace std;

typedef struct node{
    int data;

    //Lower value indicates higher priority.
    int priority;

    struct node* next;

} Node;

//Function to create a new Node
Node* newNode(int d, int p){

    Node* temp = (Node*)malloc(sizeof(Node));

    temp -> data = d;
    temp -> priority = p;
    temp -> next = NULL;

    return temp;
}

//Return the value at head.
int peek(Node** head){
    return (*head) -> data;
}

//Removes the element with the highest priority
// from the list.
void pop(Node** head){

    Node* temp = *head;
    (*head) = (*head) -> next;
    free(temp);

}

//Function to push according to priority.
void push(Node** head, int d, int p){

    Node* start = (*head);

    //Create new Node
    Node* temp = newNode(d,p);

    //Special case: The head of list has lesser
    // priority than new node. So insert new node 
    // before head node and change head node.

    if((*head) -> priority > p){

        //Insert New Node before head.
        temp -> next = *head;
        (*head) = temp;

    }else{
        
        //Traverse the list and find a 
        //position to insert new node

        while(start -> next != NULL && start -> next -> priority < p){
            start = start -> next;
        }

        //Either at the ends of the list 
        // or at required position

        temp -> next = start -> next;
        start -> next = temp;
    }
}

int isEmpty(Node** head){
    return (*head) == NULL;
}


int main(){

    Node* pq = newNode(4,1);

    push(&pq, 5,2);
    push(&pq, 6,3);
    push(&pq, 7,9);
    push(&pq, 7,0);
    push(&pq, 7,2);

    while(!isEmpty(&pq)){
        printf("%d", peek(&pq));
        pop(&pq);
    }

    return 0;

}





