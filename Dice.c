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

