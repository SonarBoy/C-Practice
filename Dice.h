#include <iostream>
#include <vector>
#include <string>



class Dice{

	private:
		int numberOfDice;
		int numberOfSides;

	public:
		Dice();

		void setNumberOfDice(int x);
		void setNumberOfSides(int x);

		int getNumberOfDice();
		int getNumberOfSides();

		std::string ShootOut();

		std::vector<int> Rolls();

		

};
