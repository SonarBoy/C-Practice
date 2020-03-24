#include <queue>
#include <iostream>

using namespace std;

void printQueue(queue<long long int> Queue){

    while(!Queue.empty()){
        cout << Queue.front() << " ";
        Queue.pop();
    }

}

void reverseQueue(queue<long long int>& queue){

    //Base case once the queue is empty
    if(queue.empty()){
        return;
    }

    //Pop the first element to return.
    long long int data = queue.front();
    queue.pop();

    //call the function again
    reverseQueue(queue);

    //Push the data into the queue.
    queue.push(data);

}


int main(){
    
    queue<long long int> Queue;

    for(int runner = 0; runner < 10; runner++)
    Queue.push(rand() % 100);


    Queue.push(56); 
    Queue.push(27); 
    Queue.push(30); 
    Queue.push(45); 
    Queue.push(85); 
    Queue.push(92); 
    Queue.push(58); 
    Queue.push(80); 
    Queue.push(90); 
    Queue.push(100); 

    reverseQueue(Queue);
    printQueue(Queue);
}