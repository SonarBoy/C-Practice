#include <iostream> 
using namespace std;
void show(string str[]);
/*
    Besides being able to access the value of a variable via a pointer
    a pointer can also be used to change the value inside a variable

    use the variable pointer name with the * dereference operator to assing 
    a new value of the appropriate data type.

*/


int main()
{
    string strArray[] ={"One","Two","Three","Four","Five"};

    string *ptr = strArray;

    *ptr = "First";

    ptr += 2;

    *ptr = "BEST";




    show(strArray);



}


void show(string str[]){
    cout << "Strings Are: " << endl;
    for(int runner = 0; runner < 5; runner++){
        cout << str[runner] << " " << endl;
    }
}