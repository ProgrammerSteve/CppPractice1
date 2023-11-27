#include <iostream>
#include<utility>
#include<functional>
//you have a function and you want to return 2 strings
//in c++,by default, you can't return 2 types
//so a function that returns an integer and a string,
//there are a few ways to handle this
// 
//1. create a struct and return that
//2. take in the parameters as reference and update from within
//3. You can pass a pointer instead of a value by reference,
//the benefit is that you can pass a nullptr if you don't want to have a value
//4. you can return an array/vector if return types are the same, becareful of heap allocation
//5. return a tuple, which is a class that return n variables and doesn't care about the types


struct Example {
	int a;
	std::string b;
	Example(int a, std::string b):a(a),b(b)
	{}
	void Print()const
	{
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
};

Example Foo(int i, std::string txt)
{
	return Example(i,txt);
}

void FooRef(int& c, std::string& d)
{
	c = 2;
	d = "pong";
}

//tuples are from the functional
//#include<utility>
//#include<functional>
std::tuple<int, std::string> FooTuple()
{
	//utility has the make_pair function to create a tuple
	return std::make_pair<int, std::string>(2, "hi");
}

void MultipleReturnValues()
{
	int c = 0;
	std::string d = "ping";
	std::cout << "before...\n";
	std::cout << "c: " << c << " d: " << d << std::endl;
	FooRef(c, d);
	std::cout << "\nafter...\n";
	std::cout << "c: " << c << " d: " << d << std::endl;
	std::cout << "\n\n";

	int a = 0;
	std::string b = "hello world";
	Example e = Foo(a, b);
	std::cout << "printing struct...\n";
	e.Print();
	std::cout << "\nUsing a Tuple:\n";
	std::tuple<int, std::string> exampleTuple = FooTuple();

	//You need to use std::get to pull values from a tuple
	//the template parameter is the index, the parameter is the tuple
	std::cout <<"tuple ind 0: "<< std::get<0>(exampleTuple) << std::endl;
	std::cout <<"tuple ind 1: "<< std::get<1>(exampleTuple) << std::endl;


}