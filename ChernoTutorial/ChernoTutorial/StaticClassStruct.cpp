//Using the static keyword on a variable within a class
//means there's going to be one instance of that variable
//across all classes. There's no point in referring to the
//variable from a class instance, since it's the same for
//all instances of that class


//For static methods you get the same effect where you
//don't get access to the class instance. A static method
//can be called without a class instance. And inside a static
//method you cannot write code that refers to a class
//instance since you do not have that instance to refer to.


#include <iostream>

struct Entity
{
	static int x, y;
	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
	static void Print2()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

//setting the static variables from
//the Entity class
//If we don't do this, we get the linking error:
//Unresolved external symbol "public: static int Entity::x"
//Unresolved external symbol "public: static int Entity::y"
// We have to define those static variables somewhere
int Entity::x;
int Entity::y;

int mainStaticClassStruct() {
	Entity e;
	e.x = 2;
	e.y = 3;

	//Initializer Error when using intializer to define a static variable
	//Entity e1 = { 5,8 };

	Entity e1;
	//e1.x = 5;
	//e1.y = 8;
	// 
	//No point in referring to static variables from
	//an instance and can be accessed as such:
	Entity::x = 5;
	Entity::y = 8;


	e.Print2();
	//The static method Print2 is able to print variables x and y since they are also static
	//Static methods cannot access nonstatic variables since it can't access class instances
	Entity::Print2();
	std::cin.get();

	//We get 5,8  5,8 printed twice since e1.x e1.y sets the value
	//for the static variable which is shared among all instances


	//This is the equivalent of the code above:
	//Entity::x = 5;
	//Entity::y = 8;
	//Entity::x = 5;
	//Entity::y = 8;
	//Entity::Print2();
	//Entity::Print2();
	//std::cin.get();

	return 0;
}