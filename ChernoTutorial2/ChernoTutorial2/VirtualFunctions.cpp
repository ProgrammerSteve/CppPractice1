#include<iostream>

// virtual functions allow us or override methods in subclasses
// suppose there are two classes: A,B
// class A is the base class
// class B is the derived class

// If we create a method in the A class and mark it as virtual
// We have the option of overriding the method in the B class
// so it'll do something else

//The 2 runtime costs of using virtual functions
//1: Additional memory required to create the V-table
//2: Performance penalty of going through the V-table to override the virtual function everytime 

//The performance difference isn't too noticable, but could be an issue
//for a small embedded device

class EntityV {
public:
	//A method returning type string
	//Since it has virtual, it can be overwritten
	//tells the compiler to generate a V-table for
	//this function, if it's overwritten, you
	//can point to the correct function
	//std::string GetName()
	virtual std::string GetName()
	{
		return "Entity";
	}
};

class PlayerV : public EntityV
{
private:
	std::string m_Name;
public:
	PlayerV(const std::string& name)
		: m_Name(name){}

	//in C++ 11, it introduced the override
	//keyword. It isn't required, but it is
	//good practice, helps catch spelling mistakes,
	//and makes the code more readable
	std::string GetName() override
	{
		return m_Name;

	}
};


void PrintName(EntityV* entity)
{
	std::cout << entity->GetName() << std::endl;
}

int mainVirtual() {

	EntityV* e = new EntityV();
	//std::cout << e->GetName() << std::endl;
	PrintName(e);

	PlayerV* p = new PlayerV("Cherno");
	//std::cout << p->GetName() << std::endl;
	//player is an entityV due to inheritance
	//it will call the method that belongs to that class
	//despite p being part of PlayerV with its own GetName() method
	//The PrintName's function parameter has a EntityV pointer
	PrintName(p);

	//Creating an entity type that points to a
	//player type.It printsEntity
	EntityV* entityExample = p;
	std::cout << entityExample->GetName() << std::endl;

	//This is where virtual functions come in. They implement
	//something called dynamic dispatch, which compiles
	//via V-table. A V-table is a table that contains all the mappings
	//of all the virtual functions inside our base class, so we can map
	//them to the correct overwritten function on runtime

	//If you want to overwrite a function, you need to mark the method
	//as virtual in the base class

	std::cin.get();
	return 0;
}


