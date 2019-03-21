#include <fstream>
#include <iostream>

using namespace std;

int main(){

	char charater;

	//File Stream to read in file
	ifstream objectFile("File_Work_Dummy.txt");

	if(!objectFile){
		cout << "*Error*" << endl;
		return -1;
	}

	//While the file object has not reached the end
	//get the current charater that the cursor is on and
	//send it to COUT.
	while(! objectFile.eof()){
		objectFile.get(charater);
		cout << charater;
	}

	objectFile.close();
	return 0;
}