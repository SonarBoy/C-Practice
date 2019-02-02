#include <iostream>
using namespace std;

int main(){

	int topNumber;

	cout << "Enter a top number: " << "\n" << "\a";
	cin >> topNumber;

 
	for(int runner = 0; runner <= topNumber; runner++){

		if(runner % 2 == 0){
			cout << runner << " is divisible by 2.";
		}else if (runner % 3 == 0){
			cout << runner << " is divisible by 3.";
		}else if (runner % 5 == 0){
			cout << runner << " is divisible by 5.";
		}else if (runner % 7 == 0){
			cout << runner << " is divisible by 7.";
		}

		cout << "\n";
	}



}