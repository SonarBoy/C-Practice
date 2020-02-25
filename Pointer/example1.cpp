//Example of the Address of Operator.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    string str = "Something to say";
    double big;

    cout << "Use of the & operator." << endl;
    cout << "Address of int &: " << &num << endl;
    cout << "Address of string &: " << &str << endl;
    cout << "Address of double &: " << &big << endl;

}