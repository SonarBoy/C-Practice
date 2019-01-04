#include <iostream>
#include <string>

using namespace std;


int main(){

	string variableSentence = "";
	string soughtCharater = "";

	//getLine(cin,variable) used to retrieve data from a stream
	cout << "Enter a Sentence" << "\n";
	getline(cin, variableSentence);


	cout << "Enter a Charater to search for: " << "\n";
	getline(cin, soughtCharater);	


	cout << "The length of the first Sentence is :" << variableSentence.length() << "\n";
	cout << "First Half of the Sentence: " << variableSentence.substr(0,variableSentence.length()/2) << endl;
	cout << "Second Half of the Sentence: " << variableSentence.substr(variableSentence.length()/2, variableSentence.length())<< endl;
	cout << "The Charater is at \"" << variableSentence.find(soughtCharater) << "\""<<" position."<< endl;

}