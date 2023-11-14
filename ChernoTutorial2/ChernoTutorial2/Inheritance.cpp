#include <iostream>

class Entity4
{
public:
	//4 bytes of memory each
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};


//Player shares a lot of similarity to the Entity class
//but includes the Name variable. Instead of repeating code
//We can extend the Entity class to Player
//class Player
//{
//	float X, Y;
//	const char* Name;
//	void Move(float xa, float ya)
//	{
//		X += xa;
//		Y += ya;
//	}
//	void PrintName()
//	{
//		std::cout << Name << std::endl;
//	}
//};



//There are three types of inheritance in c++: public, private, and protected
//In this case, we are using public, where Entity4 is the base class and Player the derived class
// 
// 
//all the public members of the base class (Entity4 in this case) 
//become public members of the derived class (Player).
//It means that the public members of Entity4, like X, Y, and Move(), 
//will retain their accessibility and visibility as public members in the Player class.
//
//
//If you were to use private instead (class Player : private Entity4)
//all the public members of Entity4 would become private members in Player, 
// meaning they would not be directly accessible from the Player objects.
//
//Using protected inheritance would make the public members of Entity4 protected members of Player, 
// allowing them to be accessed only within Player and its derived classes.
class Player2: public Entity4
{
public:
	//4 bytes of memory
	const char* Name;
	Player2() {
		Name = "Bob";
	}
	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};

int main4()
{
	Player2 player;

	std::cout << "Base Class size: "<<sizeof(Entity4)<<" bytes" << std::endl;
	std::cout << "Derived Class size: " << sizeof(Player2) << " bytes" << std::endl << std::endl;
	std::cout << "(Base public memebers)------------------------------------------------" << std::endl;
	std::cout << "X Variable size: " << sizeof(player.X) << " bytes" << std::endl;
	std::cout << "Y Variable size: " << sizeof(player.Y) << " bytes" << std::endl << std::endl;
	std::cout << "(Derived public members)----------------------------------------------" << std::endl;
	std::cout << "Name Variable size: " << sizeof(player.Name) << " bytes" << std::endl << std::endl;
	std::cout << std::endl;

	//Accessing X,Y, and Move method from base class
	std::cout << player.X << ", " << player.Y << std::endl;
	player.Move(5, 5);
	std::cout << player.X << ", " << player.Y << std::endl;
	player.X = 2;
	std::cout << player.X << ", " << player.Y << std::endl;
	//Using a method for the Player class
	player.PrintName();
	return 0;
}

//Private: Members declared as private are only accessible within the class they are defined in. 
// They are not accessible from outside the class, not even by derived classes. 
// Private members are encapsulated within the class, ensuring that they can only be accessed 
// or modified through public member functions (getters and setters) provided by the class.

//Protected members, on the other hand, are similar to private members 
// in that they are not accessible from outside the class. 
// However, they are accessible in derived classes.
// This means that derived classes can access and use protected members directly. 
//Protected members facilitate inheritance by allowing derived classes to access 
// these members while keeping them hidden from the outside world.


//In other words, protected members act like private except that they can be inherited


//Private members of a class are not directly accessible in derived classes. 
// This is a fundamental aspect of encapsulation in object-oriented programming, 
// ensuring that the internal state of a class is not directly accessible from outside the class.