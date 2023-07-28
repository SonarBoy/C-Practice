
#include <iostream>
#include <string>

using namespace std;

void recurseExampleTail(int n){

    if(n > 0){       
        cout << n << endl;
        recurseExampleTail(n - 1);
    }

};

void recurseExampleHead(int n){

    if(n > 0){       
        recurseExampleHead(n - 1);
        cout << n << endl;
    }

};

void recurseExampleTree(int n){
    if(n > 0 ){
        cout << n << endl;
        recurseExampleTree(n - 1);
        recurseExampleTree(n - 1);
    }
}

int main(){


    int value = 3;

    cout <<  "Recursion with print first: " <<endl;
    recurseExampleTail(value);

    cout << endl;

    cout <<  "Recursion with call first: " <<endl;
    recurseExampleHead(value);

    cout << endl;

    cout <<  "Recursion with call Tree: " <<endl;
    recurseExampleTree(value);


    return 0;
}