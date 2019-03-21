#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){

	string str;
	ifstream myFile("File_Work_Dummy.txt");

	if(!myFile){
		cout<< "Error opening output file" << endl;
		return -1;
	}

	while(!myFile.eof()){
		getline(myFile,str);
		cout << str << endl;
	}

	myFile.close();
	return 0;

}