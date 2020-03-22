#include <iostream>
#include <string>
//May need to remove later after use
#include <stack>

using namespace std; 

struct Queue{
    stack<int> s1, s2;

    void enQueue(int x){

        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }


    int deQueue()
    {
        if(s1.empty()){
            //cout << "Q is Empty";
            return 0;
        }

        int x = s1.top();
        s1.pop();
        return x;
    }

};

int main(){
    Queue x;
    x.enQueue(1);
    x.enQueue(2);
    x.enQueue(3);
    x.enQueue(4);
    x.enQueue(5);
    x.enQueue(6);

    int runner = 1;

    while(runner != 0){

    runner = x.deQueue();

    if(runner != 0)
    cout << "First Element out: " << runner << endl;
    }


};