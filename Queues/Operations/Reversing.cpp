#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
    enqueue(x): Add an item x to rear of queue.
    dequeue(): Remove an item from front of queue.
    empty(): Checks if a queue is empty or not.
*/



void Print(queue<int>& Queue){
    
    while(!Queue.empty()){
        cout << Queue.front() << " ";
        Queue.pop();
    }

};

void reverseQueue( queue<int>& Queue){
    
    stack<int> Stack;\

    //Push everthing on a stack from the queue
    while(!Queue.empty()){
        Stack.push(Queue.front());
        Queue.pop();
    }

    //Psuh everything on to a queue
    while(!Stack.empty()){
        Queue.push(Stack.top());
        Stack.pop();
    }
};

int main(){
    queue<int> Queue;

    queue<int> Queue2 = Queue;

    Queue.push(10);
    Queue.push(20);
    Queue.push(30);   
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    
    
    reverseQueue(Queue);
    Print(Queue);
}