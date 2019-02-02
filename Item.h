#include <string>
#include <vector>


class Item{
	
	private: 
		int Position;

	public:
		Item();
		void setPosition(int x){Position = x;};
		int getPosition(){return Position;};

		void setBlast(int x);
		int getBlast();

		std::string ShootOut();
			


};