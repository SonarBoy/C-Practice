#include <string>
#include <vector>


class Item{
	
	private: 
		int Position;

	public:
		Item();
		void setPosition(int x){Position = x;};
		int getPosition(){return Position;};
		std::string ShootOut();
			


};