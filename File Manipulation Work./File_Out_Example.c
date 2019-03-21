#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){

	/*Appending to a file
	Modes = Types of ways you can open a file
	Operations = The things you can do in those modes

	{ios::out = open a file to write output}
	{ios::in = open a file to read input}
	{ios::app = open a file to append output at the end
	of any existing content}
	{ios::trunc = truncate the existing file} *DEFAULT BEHAVIOUR*
	{ios::ate = open a file witout truncating and allow data to
	be written anywhere in the file}
	{ios::binary = treat the file as binary format rather than 
	text the data may be stored in a non text format}
	*/


	ofstream myFile ("File_Work_Dummy.txt", ios::out);

	if(!myFile){
		cout << "Error in Processing";
		return -1;
	}


	myFile << "This is a test from the File_Out_Example" << endl;
	myFile.close();


	return 0;
}