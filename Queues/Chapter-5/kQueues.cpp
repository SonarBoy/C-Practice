//How to efficiently implement K Queues in a single array?


#include <iostream>
#include <climits>

using namespace std;
/*
For example, consider k as 2 and array size n as 6. Let we 
enqueue 3 elements to first and do not enqueue anything to 
the second queue.

When we enqueue the 4th element to the first queue, there 
will be overflow even if we have space for 3 more elements 
in the array.


front[]: This is of size k and stores indexes of front
elements in all queues.

rear[]: This is of size k and stores indexes of next item
for all items in array arr[]

next[]: This is of size n and stores indexes of next item
for all items in array arr[];


*/
class kQueues{

    //Array of size of n to store actual content
    //to be stored in queue.
    int *array;

    //Array of size k to sotre indexes of front
    //elements of the queue
    int *front;

    //Array of size k to store indexes of rear
    //elements of queue
    int *rear;

    //Array of size n to store next entry in all 
    //queues
    int *next;
    int n, k;
    int free;

public:

    //constructor to create k queue in an array
    //of size n
    kQueues(int k, int n);


    //Item is the item
    //qn is the queue number 
    void enqueue(int item,int qn);

    //A utility function to check if there is 
    // space available
    bool isFull() { return (free == -1); }

    //To enqueue an item in queue number 'qn'
    int dequeue(int qn);

    // TO check whether queue number 'qn' is 
    //empty or not
    bool isEmpty(int qn) { return (front[qn] == -1); }
};

//Constructor to create k queues 
//In an array of size n
kQueues::kQueues(int k1,int n1)
{
    k = k1; 
    n = n1;

    array = new int[n];

    //Array that holds the queues
    front = new int[k];
    rear = new int[k];

    //Queue array
    next = new int[n];


    //Initialize all the queues as empty
    for(int runner = 0; runner < k;runner++){
        front[runner] = -1;
    }

    //Initialize all spaces as free
    free = 0;
    for(int runner = 0; runner < n - 1; runner++){
        next[runner] = runner + 1;
    }

    // -1 is used to indicate end of free list
    next[n - 1] = -1;


}

void kQueues::enqueue(int item, int qn){

    if(isFull()){
        cout << "\n Queue Overflow \n";
        return;
    }

    int i = free;

    //Update index of free slot to index of 
    //next slot in free list.
    free = next[i];

    if(isEmpty(qn)){
        front[qn] = i;
    }else{
        next[rear[qn]] = i;
    }

    next[i] = -1;

    //update next of rear and then rear for
    // queue number 'qn'
    rear[qn] = i;

    // Put the item in array 
    array[i] = item;
}

int kQueues::dequeue(int qn){

    if(isEmpty(qn)){
        cout << "\nQueue Underflow\n"; 
        return INT_MAX;
    }

    // Find index of front item in queue number 
    int i = front[qn];

    // Change top to store next of previous top 
    front[qn] = next[i];

     // Attach the previous front to the beginning of free list 
    next[i] = free;
    free = i;

    // Return the previous front item 
    return array[i];
}

int main(){

    int numberOfQueues = 0, numberOfSpaces = 0;


	cout << "Enter the number of Queues: ";
	cin >> numberOfQueues;

	cout << "Enter the number of Spaces you want in each queue: ";
	cin >> numberOfSpaces;

    //4 queues and 4 total elements
    kQueues ks(numberOfQueues, numberOfSpaces);

    ks.enqueue(0, 0);
	ks.enqueue(0, 1);
    ks.enqueue(2, 1);
	ks.enqueue(0, 2);
	ks.enqueue(0, 3);



    for(int runner = 0; runner < numberOfQueues ;runner++){
		for(int innerRunner = 0; innerRunner < numberOfSpaces ;innerRunner++){
			cout << "Dequeued element from queue "<< runner<<  "  is " << ks.dequeue(innerRunner) << endl;
		}

		cout << endl;
	}



    /*
    ! THIS IS IF YOU WANT ALL POSSIBLE QUEUES TO HAVE THE SAME NUMBER OF ELEMENTS
	kQueues ks(numberOfQueues, numberOfSpaces * numberOfQueues);

	for(int runner = 0; runner < numberOfQueues ;runner++){
		for(int innerRunner = 0; innerRunner < numberOfSpaces ;innerRunner++){
			ks.enqueue(rand() % 100,innerRunner);
		}
		cout << endl;
	}



	for(int runner = 0; runner < numberOfQueues ;runner++){
		for(int innerRunner = 0; innerRunner < numberOfSpaces ;innerRunner++){
			cout << "Dequeued element from queue "<< runner<<  "  is " << ks.dequeue(innerRunner) << endl;
		}

		cout << endl;
	}

	
	
	ks.enqueue(0, 0);
	ks.enqueue(0, 0);
	ks.enqueue(0, 0);
	ks.enqueue(0, 0);

	ks.enqueue(0, 1);
	ks.enqueue(0, 1);
	ks.enqueue(0, 1);
	ks.enqueue(0, 1);

	ks.enqueue(0, 2);
	ks.enqueue(0, 2);
	ks.enqueue(0, 2);
	ks.enqueue(0, 2);

	ks.enqueue(0, 3);
	ks.enqueue(0, 3);
	ks.enqueue(0, 3);
	ks.enqueue(0, 3);



	while (!ks.isEmpty(0)) {
		cout << "Dequeued element from queue " << 0 << "  is " << ks.dequeue(0) << endl;
	}

	while (!ks.isEmpty(1)) {
		cout << "Dequeued element from queue " << 1 << "  is " << ks.dequeue(1) << endl;
	}


	while (!ks.isEmpty(2)) {
		cout << "Dequeued element from queue " << 2 << "  is " << ks.dequeue(2) << endl;
	}


	while (!ks.isEmpty(3)) {
		cout << "Dequeued element from queue " << 3 << "  is " << ks.dequeue(3) << endl;
	}

    */

	/*
	for(int runner = 0; runner < (numberOfQueues - 1);runner++){
		for(int innerRunner = 0; innerRunner < (numberOfSpaces - 1);innerRunner++){
			ks.enqueue(rand() % 100,innerRunner);
		}
		cout << endl;
	}



	 for(int runner = 0; runner < numberOfQueues ;runner++){
		for(int innerRunner = 0; innerRunner < numberOfSpaces ;innerRunner++){
			cout << "Dequeued element from queue "<< innerRunner<<  "  is " << ks.dequeue(innerRunner) << endl;
		}

		cout << endl;
	}

	*/
}