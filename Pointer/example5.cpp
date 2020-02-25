#include <iostream> 
using namespace std;

int main(){

    int numberedArray[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10} ;

    int *pointerRunner = numberedArray;

    cout << "Address of the Pointer: "<< &pointerRunner <<endl;

    while(pointerRunner != NULL){

        cout << "Value: " << *pointerRunner << endl;
        pointerRunner++;
    }



}