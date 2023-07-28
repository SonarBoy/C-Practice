#include <iostream>
#include <string>

using namespace std;

struct Rectangle{
    int length;
    int breath;
};


int main(){

    //Pointers are use for 
    /* 
    1) Accessing the HEAP memory 
    2) Accessing resources that are outsibe the program
    3) Parameter passing
    */

    int a = 10;

    // Declairs a pointer
    int *pointer;

    //Here we are getting the address of the variable a
    //This points to the address of variable a in memory
    pointer = &a;

    cout << "The Address of A: "<< pointer << endl;
    cout << "The Value (Dereferenced Address) of A: "<< *pointer << endl;


    int array[5] = {2,4,6,8,10};
    int *arrayPointer;

    /* You have two options when talking about the pointer of an array
    you can either point to the address of the first element of the
    in the example below */
    arrayPointer = array;

    /* Or you can point to a particular indx of the array like so*/
    //arrayPointer = &array[3];



    cout << "The Address of Array: "<< arrayPointer << endl;
    cout << "The Value (Dereferenced Address) of Array: "<< *arrayPointer << endl;

    cout << endl;
    for(int indx = 0; indx < 5; indx++){
        cout << "Pointer address for indx " << indx  << " " << &array[indx] << endl;
        cout << "Pointer retrieved value " << arrayPointer[indx] << endl;
    }

    /* Creating an array in the heap via memory allocation  or malloc*/
    int *memPointer;
    // CREATED FOR C
    //memPointer = (int*)malloc(5*sizeof(int));
    memPointer = new int[5];

    memPointer[0] = 17;
    memPointer[1] = 45;
    memPointer[2] = 23;
    memPointer[3] = 48;
    memPointer[4] = 99;

    cout << endl;
    for(int indx = 0; indx < 5; indx++){
        cout << "Pointer address for indx " << indx  << " " << &memPointer[indx] << endl;
        cout << "Pointer retrieved value " << memPointer[indx] << endl;
    }

    // When you are allocating memory in C++ to free it up use 
    delete [ ] memPointer;

    // Freeing memeory in C you use 
    // free(memPointer); 

    cout << endl;
    //All pointers take the same size
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << "Integer pointer size: " << sizeof(p1) << endl;
    cout << "Char pointer size: " << sizeof(p2) << endl;
    cout << "Float pointer size: " << sizeof(p3) << endl;
    cout << "Double pointer size: " << sizeof(p4) << endl;
    cout << "Rectangle pointer size: " << sizeof(p5) << endl;

    return 0;
}