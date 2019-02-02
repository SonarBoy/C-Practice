#include <iostream>
using namespace std;

int main(){

	int runnerNumber = 0;
	int loopRunner = 0;

	cout << "Enter your number: " << "\n";
	cin >> runnerNumber;

	do{

		cout << "Place: " << loopRunner << "\n";

		loopRunner++;
	}while(loopRunner < runnerNumber);
}
