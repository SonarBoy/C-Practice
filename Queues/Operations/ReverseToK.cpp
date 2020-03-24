#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverseQueueFirstKElements(int k, queue<int>& Queue){

    if(Queue.empty() == true || k > Queue.size()){
        return;
    }

    if(k <= 0){
        return;
    }

    stack<int> Stack;


    //Push the first K elements into a Stack
    for(int runner = 0 ; runner < k; runner++){
        Stack.push(Queue.front());
        Queue.pop();
    }

    //Enqueue the contents of Stack ad the back of the queue
    while(!Stack.empty()){
        Queue.push(Stack.top());
        Stack.pop();
    }

    //Remove the remaining elements and enqueue them at the end of the queue
    for(int runner = 0; runner < Queue.size() - k; runner++){
        Queue.push(Queue.front());
        Queue.pop();
    }
}

void Print(queue<int>& Queue){

    while(!Queue.empty()){
        cout << Queue.front() << " ";
        Queue.pop();
    }
}


int main(){
    queue<int> Queue; 
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
  
    int k = 5; 
    reverseQueueFirstKElements(k, Queue); 
    Print(Queue); 
}