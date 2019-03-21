//File Import call
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	cout << "Hello World" << endl;

	//ofstream: object for writing output to file.
	//ifstream: object for retrieving input from file.
	// * Similar to CIN and COUT.

	//Declares the ofstream object with the name Test.txt
	//in the current directroy.
	ofstream first_File ("Test.txt");

	//Preventative Exception Handling:
	//Check if the file is there before you try to open it 
	//dummy.


	if(!first_File){
		cout << "Error Opening the File." << endl;
		return -1;

	}

	//Write and close the file.
	first_File << "This is an Attempt!" << endl;
	first_File.close();

	return 0;
}