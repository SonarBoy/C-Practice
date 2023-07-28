#include <iostream>
#include <string>

using namespace std;


int function(int num){

    if(num > 100){
        cout << "Returning " << num << " - " << " 10" << endl;
        return num - 10;
    }else{
        cout << num << endl;
        return function(function(num + 11));
    }
}



int main(){

    cout << "Enter a Number: " << endl;
    int number = 0;

    cin >> number;

    int output = function(number);

    cout << "Returned: " << output << endl;




    return 0;
}