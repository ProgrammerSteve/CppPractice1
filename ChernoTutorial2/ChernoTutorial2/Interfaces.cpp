#include<iostream>

//Interfaces are a type of virtual functions called pure Virtual Function

//The same as an abstract method or interface in other languages
//such as Java or C#

//Pure Virtual Functions allow us to define a virtual function in a base class
//that does not have an implementation, and forces subclasses to implement that
//function


class Printable {
public:
	//pure virtual function
	virtual std::string GetClassName() = 0;
};



class EntityI: public Printable {
public:
	//In some cases it doesn't make sense for us to
	//provide this default implementation
	//
	//We might want to force the subclass to provide its
	//own definition for a certain function
	//
	//In object oriented programming, its commond to create
	//a class of only of unimplemented methods and force
	//subclasses to define them. This is something often
	//referred to as an interface. Acts like a template
	//
	//Since the Interface class doesn't have method implementation,
	//you can't instantiate the class 
	//
	//By having a virtual function with no body in the function and equalling it to zero,
	//we lose the ability to create an instance of the class due to the interface
	virtual std::string GetName() = 0;




	std::string GetClassName() override
	{
		return "Entity";
	}
};

class PlayerI : public EntityI
{
private:
	std::string m_Name;
public:
	PlayerI(const std::string& name)
		: m_Name(name) {}
	std::string GetName() override
	{
		return m_Name;
	}
	std::string GetClassName() override
	{
		return "Player";
	}
};

//Another class that inherits from the
//Printable interface and is forced
//to define GetClassName
class A :public Printable
{
public:
	std::string GetClassName() override
	{
		return "A";
	}
};



void PrintName(EntityI* entity)
{
	std::cout << entity->GetName() << std::endl;
}

//Uses an interface as the return type
//to enforce classes derived from that interface
//to have the GetClassName method to be defined
void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{
	//Can't create an EntityI instance due to interface
	//EntityI* e = new EntityI();

	//Without GetName defined in PlayerI, we can't create
	//an instance of the PlayerI class.
	PlayerI* p = new PlayerI("name");


	Print(p);
	Print(new A());
	return 0;
}