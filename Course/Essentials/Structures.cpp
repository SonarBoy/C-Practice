
#include <iostream>
#include <string>

struct Rectangle{
    int length;
    int breath;

    char x;
};

struct ComplexNumber{
    int real;
    int imaginary;
};





using namespace std;

int main(){

    struct Rectangle r = {10,5};

    r.length = 12;
    r.breath = 10;

    cout << r.length * r.breath << endl;
    cout << "Size Of R1: " << sizeof(r);

    return 0;

}
