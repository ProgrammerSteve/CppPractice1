#include <iostream>


//implicit conversion
//explicit keyword

//implicit means without you saying what to do
//so automatic in this context

//compiler can perform implicit conversion on your code
//if one data type can be converted from one type to the other
//the compiler will convert it in the background

class EntityImplicit
{
private:
	std::string m_Name;
	int m_Age;
public:
	EntityImplicit(const std::string& name)
		:m_Name(name), m_Age(-1){}
	EntityImplicit(int age)
		:m_Name("Unknown"),m_Age(age){}
};

void ImplicitConversion()
{
	//Regular instantiating
	EntityImplicit a("Cherno");
	EntityImplicit b(22);

	//implicit conversion/construction
	//implicitly turning the value into an EntityImplicit class
	EntityImplicit c= std::string("Cherno");
	EntityImplicit d= 22;
	
}