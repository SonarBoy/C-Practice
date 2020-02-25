#include <iostream>
#include <string>
using namespace std;

/* 
    In this example we declare multiple pointers and then 
    declare an array object that is of type pointers to house all of them.
*/

int main()
{
    int intArray[5] = {1,2,3,4,5};

    int *ptr0 = &intArray[0];
    int *ptr1 = &intArray[1];
    int *ptr2 = &intArray[2];
    int *ptr3 = &intArray[3];
    int *ptr4 = &intArray[4];


    int *ptrs[5] = {ptr0,ptr1,ptr2,ptr3,ptr4};

    for(int runner = 0; runner < 5; runner++){
        cout << "The value stored at " << ptrs[runner];
        cout << " is " << *ptrs[runner] << endl;
    }



}