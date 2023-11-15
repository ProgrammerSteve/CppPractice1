#include<iostream>
//Mutables are used in 2 areas, 
//1: with const methods in classes
//2: with lambda functions
//
//usages with lambdas is a rare situation
//and usually isn't done
//
//With classes, the mutable keyword
//kind of negates the const keywords for a variable


class EntityMutable
{
private:
	std::string m_Name;
	//For debugging purposes we have
	//and int called m_DebugCount which doesn't
	//affect the rest of the code
	//This is a good candidate for a mutable
	mutable int m_DebugCount;
public:
	const std::string& GetName()const
	{
		//const makes it where
		//we can modify class members

		//Without the mutable keyword, we wouldn't be
		//able to do this. Now const methods can modify it
		m_DebugCount++;
		return m_Name;
	}
};


int MutableMain() {
	EntityMutable e;
	e.GetName();

	//lambdas
	int x = 8;
	//Suppose you wanted to use x in the lambda function
	//we need to define a "capture method"
	//By reference [&x]()
	//By value [x]()
	//or you can just write it like [&]() [=]()
	//to send everything that is used by reference or by value
	auto f = [=]()
		{
			//x++; if passed by value, you get an error
			// 
			//One way to get around is to make another var
			//and do the incrementing with that.
			//int y=x;
			//y++;
			//
			std::cout << x << std::endl;
		};
	f();

	//To get around this, you can add the mutable keyword
	//after [=]() in the lambda
	//what this means is that variables passed by value
	//can be changed from within the lambda function
	//Outside of the function x will still equal 8
	// int x = 8;
	//inside the lambda, x will be 9
	auto g = [=]()mutable
		{
			x++;
			std::cout << x << std::endl;
		};
	g();
	return 0;
}