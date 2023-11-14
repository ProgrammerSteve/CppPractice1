#include<iostream>

// virtual functions allow us or override methods in subclasses
// suppose there are two classes: A,B
// class A is the base class
// class B is the derived class

// If we create a method in the A class and mark it as virtual
// We have the option of overriding the method in the B class
// so it'll do something else


class EntityV {
public:
	//A method returning type string
	std::string GetName()
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

	std::string GetName()
	{
		return m_Name;
	}
};

int main() {

	EntityV* e = new EntityV();
	std::cout << e->GetName() << std::endl;

	PlayerV* p = new PlayerV("Cherno");
	std::cout << p->GetName() << std::endl;

	EntityV* entity = p;
	std::cout << p->GetName() << std::endl;


	std::cin.get();
	return 0;
}


