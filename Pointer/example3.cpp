#include <iostream>
using namespace std;

/*
    When the * operator is used in the variable declartion 
    it indicates that the variable is being declared as a pointer.

    However when a * operator appears before a pointer variable else
    where in a program it references the data stored at the address assigned to
    that pointer.

    int *pntr; declaration of pointer

    pntr = 3; assingment of the pointer

    cout << *pntr; value that the pointer is pointing to.

*/


int main()
{
    int x = 8;
    int y = 16;

    int *x_ptr;
    int *y_ptr;

    x_ptr = &x;
    y_ptr = &y;


    cout << "Address of X: " << x_ptr << endl;
    cout << "Value of X: " << *x_ptr << endl;
    cout << endl;
    cout << "Address of Y: " << y_ptr << endl;
    cout << "Value of Y: " << *y_ptr << endl;



}