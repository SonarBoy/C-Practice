#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
//Queue elements after sortedIndex are
//already sorted. This function returns 
//index of minimum elements from front to sortedIndex

/*
Input : 
-------------
11  5  4  21    min index = 2
-------------
-------------
11  5  21  4    after inserting 4
-------------
-------------
11  5  21  4    min index = 1
-------------
-------------
11  21  4  5   after inserting 5
-------------

-------------
11  21  4  5   min index = 0
-------------

-------------
21  4  5  11   after inserting 11
-------------

-------------
21  4  5  11   min index = 0
-------------

-------------
4  5  11  21   after inserting 21
-------------
Output : 4 5 11 21
*/

int minIndex(queue<int> &q, int sortedIndex){

    int min_index = -1;
    int min_val = INT_MAX;
    int queueSize = q.size();

    for(int i = 0; i < queueSize; i++){


         int current = q.front();
         q.pop();

        //we add the condition i <= sortedIndex
        //because we dont want to traverse
        //on the sorted part of the queue,
        //which is the right part.
        if(current <= min_val && i <= sortedIndex){
            min_index = i;
            min_val = current;
        }

        q.push(current);

    }

    return min_index;
}


//Adds minimun element to the back
void insertMinToRear(queue<int> &q, int min_index){

    int min_val;
    int queueSize = q.size();

    for(int runner = 0; runner < queueSize; runner++ ){

        int current = q.front();
        q.pop();

        if(runner != min_index){
            q.push(current);
        }else{
            min_val = current;
        }
    }

    q.push(min_val);
}

void sortQueue(queue<int> &q){

    for(int i = 1; i <= q.size();i++){

        int min_index = minIndex(q,q.size() - i);
        insertMinToRear(q,min_index);
    }
}


int main(){
    queue<int> q;

   q.push(30); 
  q.push(11); 
  q.push(15); 
  q.push(4); 
    

    sortQueue(q);


    while(q.empty() == false){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;

}