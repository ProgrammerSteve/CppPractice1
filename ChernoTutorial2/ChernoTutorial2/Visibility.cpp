// 3 basic visibility modifiers
//Private, protected, public

#include <iostream>
#include<string>


//By default, members in a class are private
//unless otherwise specified.
//In structs, the default is public
class EntityVis
{
//Using this would not change the code
private:
	int X, Y;
	void Print(){}
protected:
	//Is passed down and can be
	//accessed by the derived class methods
	int Z = 2;
public:
	EntityVis()
	{
		X = 0;
		Print();
	}
};

struct EntityVisStruct
{
//Using this would not change the code
//public:
	int X, Y;
};

class PlayerVis: public EntityVis
{
public:
	PlayerVis()
	{
		Z = 2;
	}
};

int main6()
{
	EntityVis entity;
	//X is private and can't be accessed directly
	//entity.X = 2;
	std::cin.get();
	return 0;
}
