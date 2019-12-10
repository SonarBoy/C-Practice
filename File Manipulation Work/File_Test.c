#include <fstream> //File Include statement.
#include <iostream>

using namespace std;

int main(){

	//Create a file stream and write to a file.
	ofstream buckyFile;
	buckyFile.open("Test.txt");

	//Over write content of the file.
	buckyFile << "I Love tuna and tuna loves me" << endl;


	buckyFile.close();

}