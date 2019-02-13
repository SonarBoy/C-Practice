#include <string>
#include <vector>
#include "Dice.h"

using namespace std;


Dice::Dice(){
	numberOfDice = 0;
	numberOfSides = 0;
}

std::string Dice::ShootOut(){
	return "Interview";
}

std::vector<int> Dice::Rolls(){
	
	std::vector<int> x;

	for(int i = 0; i <= numberOfDice; i++){
		x.push_back(rand() % numberOfSides + 1);
	}

		
	for(int i = 0; i <= x.size() - 1; i++){
		cout << "Roll Number: " << i << endl;
		cout << "Roll Value: " << x.at(i) << endl; 
	}


	return x;
	
}

void Dice::setNumberOfDice(int x){
	numberOfDice = x;
}

void Dice::setNumberOfSides(int x){
	numberOfSides = x;
}

int Dice::getNumberOfDice(){
	return numberOfDice;
}

int Dice::getNumberOfSides(){
	return numberOfSides;
}

