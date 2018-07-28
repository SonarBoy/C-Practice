#include <iostream>
using namespace std;

int main(){

	char charater = 'x';
	long long_Digit = 12.90;
	string basic_String = "";


	cout << "Char Size: " << sizeof(charater) << "\n";
	cout << "Long Size: " << sizeof(long_Digit) << "\n";

	cout << "Enter a String: " << "\n";
	cin >> basic_String;
	cout << "String Size: " << sizeof(basic_String) << "\n";



	return 0;
}