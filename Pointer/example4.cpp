#include <iostream>
using namespace std;

/*
    Once a pointer variable has been created with an assinged 
    address it can be reassinged another address or moved 
    using arithmetic.

    ++ increment
    -- decrement

    Will move the pointer along to the next or previous address 
    for that data type.

*/



int main()
{
    int nums[] = {1,2,3};

    int *ptr = nums; //assigns the address of the first element to the array.

    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

    ptr++;
    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

    ptr++;
    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

    ptr--;
    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

    ptr--;
    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

    ptr--;
    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

    ptr = NULL;
    cout << "ptr address: " << ptr << " value: " << *ptr << endl;

}