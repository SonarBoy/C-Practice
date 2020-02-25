#include <iostream>
using namespace std;

/*
    - Pointers are prefixed by a "*", referenced by the dereference operator.
      and merely denotes that the declared variable is a pointer.

    - Once declarde a pointer variable can be assinged the address of another
      variable using the & addressof operator.

    BIG NOTE:
        The varible name should not be prefixed by the * dereference operator 
        in the assingment statement unless the pointer is initialized immediately
        in the variable declaration itself.
*/



int main()
{
    int x = 8, y = 16;

    //Declaring the pointer to point to the memory address of x 
    int *x_ptr = &x;

    //Declaring the pointer to point to the memory address of y
    int *y_ptr = &y;


    cout << "Address of X: " << x_ptr << endl;
    cout << "Address of Y: " << y_ptr << endl;

    return 0;
}