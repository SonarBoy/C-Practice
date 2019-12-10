#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

int main(){
	

	Item x = Item();

	x.setPosition(10);
	x.ShootOut();

	cout << "Potency " << x.getPosition() << endl;
	cout << "The Rate is : " << x.ShootOut();

	return 0;
}

	/*
	Element access:
	operator[]
    Access element (public member function )

	at
    Access element (public member function )

	front
    Access first element (public member function )

	back
    Access last element (public member function )

	data	
    Access data (public member function )


	Modifiers:
	assign
    Assign vector content (public member function )

	push_back
    Add element at the end (public member function )

	pop_back
    Delete last element (public member function )

	insert
    Insert elements (public member function )

	erase
    Erase elements (public member function )

	swap
    Swap content (public member function )

	clear
    Clear content (public member function )

	emplace
    Construct and insert element (public member function )

	emplace_back
    Construct and insert element at the end (public member function )
    */