#include <iostream>

/*
    Rear [9] [8] [7] [6] [5] [4] [3] [2] [1] Front

    enQueue() = adds elements to the rear.
    deQueue() = removes elements from the front.
*/

using namespace std;

struct QNode{
    int data;
    QNode* next;

    QNode(int d){
        data = d;
        next = NULL;
    }
};

struct Queue{
    QNode *front, *rear;

    Queue(){
        front = rear = NULL;
    }

    void enQueue(int input){

        //Create a new Linked List Node
        QNode* temp = new QNode(input);

        //If queue is empty, then
        //new node is front and rear both.
        if(rear == NULL){
            front = rear = temp;
            return;
        }

        //Add the new Node at
        //the end of queue and change rear
        rear -> next = temp;
        rear = temp;
    }

    void deQueue(){

        // If queue is empty, return NULL.
        if(front == NULL){
            return;
        }

        // Store previous front and
        // move front one node ahead
        QNode* temp = front;
        front = front -> next;


        // If front becomes NULL, then 
        // change rear also as NULL 

        //This basically means there are no elements in 
        // the queue
        if(front == NULL){
            rear = NULL;
        }

        delete(temp);
    }
};

int main(){

    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);

    cout << "Queue Front: " << (q.front)-> data << endl;
    cout << "Queue Front: " << (q.rear)-> data << endl;
}