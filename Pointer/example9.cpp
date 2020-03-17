#include <iostream>
#include <string>
using namespace std;
int add(int x, int y);

/* 
    A pointer to a function like a pointer to data must always be enclosed in plain brackets
    when using the * dereference operator to avoid a compiler error. These will be followed by plan
    brackets containing any arguments to be passed to the function when using the * dereference operator.


*/

int main()
{
    int (*ptr)(int x,int y);

    int x = 16, y = 8;


    ptr = add;

    cout << x << " plus " << y << " equals ";

    cout << (*ptr)(x,y) << endl;
    return 0;


}

int add(int x, int y){
    return x + y;
}

/*
Pray for :

Ms Rodriquez's kid.
Quaden for getting bullied and Brandon Farbstien
For when i took solace in the devil because i was getting bullied so much in school.

*/