#include <iostream> 
using namespace std;
void triple(int *number);
/*
    C++ programs function arguments pass their data "BY VALUE" to a local variable
    inside variable the called function. This means that the function is not operating 
    on the original valie but a copy of it. Passing a pointer to the original value instead over comes this to
    allow the called function to operate on the original value.

*/

int main(){

    int num = 5; 

    int *ptr = &num; // THIS POINTER HAS THE NUMBERS LOCATION.

    cout << "num value is " << num << endl;

    triple(ptr);

    cout << "num value after triple is " << num << endl;
    



}

void triple(int *number){
    *number = *number * 3;
}
