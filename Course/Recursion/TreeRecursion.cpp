#include <iostream>
#include <string>

using namespace std;


int function(int num){

    if(num > 0){

        cout << "Number: " << num << endl;
        function(num - 1);
        function(num - 1);

    }

    return 0;
}



int main(){

    cout << "Enter a Number: " << endl;
    int number = 0;

    cin >> number;

    int output = function(number);

    cout << "Returned: " << output << endl;




    return 0;
}