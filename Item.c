#include <string>
#include <vector>
#include "Item.h"

using namespace std;


Item::Item(void)
{
	Position = 0;
}

std::string Item::ShootOut(){
	return "Hocus Pocus!";
}

void Item::setBlast(int x){
	Position = x;
}

int Item::getBlast(){
	return Position;
}