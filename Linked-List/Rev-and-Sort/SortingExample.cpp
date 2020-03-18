// C++ program for Quick Sort on Singly Linled List 
#include <iostream> 
#include <cstdio> 
using namespace std; 
  
/* a node of the singly linked list */
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
    printf("\n"); 
} 
  
// Returns the last node of the list 
struct Node *getTail(struct Node *cur) 
{ 
    while (cur != NULL && cur->next != NULL) 
        cur = cur->next; 
    return cur; 
} 




//https://www.youtube.com/watch?v=Hoixgm4-P4M

struct Node *partition(struct Node *head,struct Node *end, struct Node **newHead, struct Node **newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;


    // During partition, both the head and end of the list change 
    // which is updated in the newHead and newEnd variables 
    while(cur != pivot){

        if(cur -> data < pivot -> data)
        {
            //This executes if the first node has a value less than the new head.
            if((*newHead) == NULL){
                (*newHead) = cur;
            }

            prev = cur;
            cur = cur -> next;
        }else{
            //If the current node is less than the pivot.

            // Move cur node to next of tail, and change tail 
            if(prev){
                prev-> next = cur->next;
            }

            struct Node *tmp = cur -> next;
            cur -> next = NULL;
            tail-> next = cur;
            tail = cur;
            cur = tmp;
        }

    }

    //If the Pivot data is the smallest element the pivot becomes the head. 
    if((*newHead) == NULL){
        (*newHead) = pivot; 
    }

    //Update the newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}

//here the sorting happens exclusive of the end node
struct Node *quickSortRecur(struct Node *head, struct Node *end)
{

    if(!head || head == end){
        return head;
    }

    Node *newHead = NULL, *newEnd = NULL;


    // Partition the list, newHead and newEnd will be updated 
    // by the partition function 
    struct Node *pivot = partition(head,end,&newHead,&newEnd);

    // Set the node before the pivot node as NULL 
    if(newHead != pivot){
        struct Node *tmp = newHead;
        while(tmp -> next != pivot){
            tmp = tmp -> next;
        }

        tmp-> next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);


        // Change next of last node of the left.
        tmp = getTail(newHead);
        tmp -> next = pivot;
    }

    // Recur for the list after the pivot element 
    pivot->next = quickSortRecur(pivot->next, newEnd); 

    return newHead;
}

void quickSort(struct Node **headRef) 
{ 
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef)); 
    return; 
} 

int main() 
{ 
    struct Node *a = NULL; 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 4); 
    push(&a, 3); 
    push(&a, 30); 
  
    cout << "Linked List before sorting \n"; 
    printList(a); 
  
    quickSort(&a); 
  
    cout << "Linked List after sorting \n"; 
    printList(a); 
  
    return 0; 
} 