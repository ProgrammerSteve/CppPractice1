#include <iostream>

// The constructor initialization list in C++ is a way to initialize 
// class members before the constructor body executes. 
// It's a comma-separated list of member variables followed 
// by their initial values in the constructor's header.

// Initialization in the constructor initialization list is often 
// more efficient than assigning values within the constructor body. 
// It directly initializes the members using their constructors 
// or assignment operators, avoiding unnecessary default initializations.

// Const or Reference Members: 
// For members that are constants or references 
// (which must be initialized upon creation), 
// the initialization list is the only way to assign values.

// Base Class Initialization: 
// When a derived class constructor is called, the constructor 
// of the base class is also executed. The initialization list 
// is used to pass arguments to the base class constructor.
class Example {
private:
	int var1;
	float var2;
public:
	//In this example, we are intializing var1 and var2
	//using the parameters from the constructor method
	Example(int a, float b) : var1(a), var2(b) {
		// Constructor body
	}
};


class Animal {
public:
	//A method returning type string
	std::string GetName()
	{
		return "Entity";
	}
};

class Character : public Animal
{
private:
	std::string m_Name;
public:
	//The private variable m_Name is being initialized
	//Using the Constructor initialization List
	//The parameter, const string reference, name, is being used
	//to initialize with the :m_Name(name) part
	Character(const std::string& name): m_Name(name) {}
	std::string GetName()
	{
		return m_Name;
	}
};

int main5()
{
	//Because the Character class 
	Character c("Bob");
	std::cout << c.GetName() << std::endl;
	return 0;
}
