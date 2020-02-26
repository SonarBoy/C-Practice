#include <iostream>
#include <string>
#include "Dice.h"

using namespace std;

int main(){
	
	Dice x = Dice();
	int n_Position = 0;
	string faces ;
	string times ;

	string roll = "";
	

	cout << "Enter the Dice you want to roll: ";
	cin >> roll;

	n_Position = roll.find('d');

	faces = roll.substr(0,roll.find("d"));
	//sscanf(faces, "%d", &fac); 
	
	times = roll.substr(roll.find("d") + 1,roll.length());
	//sscanf(times, "%d", &tim); 
	
	x.setNumberOfDice(stoi(times));
	x.setNumberOfSides(stoi(faces));

	x.Rolls();

	//cout << "Faces: " << faces << endl;
	//cout << "Times: " << times << endl;
	//cout << "N at: " << n_Position << endl;
	//cout << "Test" << (fac * tim) << endl;
}