#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void interLeaveQueue(queue<int>& q){

    if(q.size() % 2 != 0){
        cout << "Input even number of integers" << endl;
    }

    //Initialize an empty stack of int type
    stack<int> s;
    int halfSize = q.size() / 2;


    //Push first half elements into the stack
    for(int runner = 0; runner < halfSize; runner++){
        s.push(q.front());
        q.pop();
    }


    //enqueue back the stack elements
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }


    //dequeue the first hald elements of queue
    //and enqueue them back 
    for(int runner = 0; runner < halfSize; runner++){
        q.push(q.front());
        q.pop();
    }


    //Again push the first hald elements into the queue
    for(int runner = 0; runner < halfSize; runner++){
        s.push(q.front());
        q.pop();
    }

    //Interleave the elements of queue and stack 
    while(!s.empty()){

        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();

    }

}

int main(){
    queue<int> q;

    //After the interleave
    //11 15 12 16 13 17 14 18

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);


    interLeaveQueue(q);

    int length = q.size();


    for(int runner = 0; runner < length; runner++){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}