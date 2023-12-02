#include<iostream>
#include<string>
#include<vector>

//To let C++ to automatically infer what the type is
//let's say you make a string and have a function that returns a string
//the compiler knows the function returns a string
//so using auto with the variable equalling the output of the function will
//automatically set the variable type to string

//Using auto will allow for the variable to instantly
//adapt to the return type you specify at the function
//let say you put char* instead of std::string,
//then the auto variable will adapt

//technically there's an implicit constructor that works
//with std::string and char*, so it would work if you swapped
//out the return type, but this is an exception
//doing the .size() method from string on a char* won't work
std::string GetName()
{
	return "Cherno";
}

//The bad part of auto, is that if you make a change, your auto variable
//could break the code elsewhere in the code due to a change in the function
//so not using auto is a lot less error prone

void Auto() 
{
	//c++ will figure out that 5 is an int so variable a will also be an a
	auto a = 5;

	//using auto for b will deduce that b is an int like a
	auto b = a;

	//infers that s is a const char *
	auto s = "Cherno";


	std::string name = GetName();
	auto autoName = GetName();

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");
	//iterating through a vector in c++ using an iterator
	//the type std::vector<std::string>::iterator is long
	//using auto would be a lot easier
	// 
	//    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	//    {
	//	    std::cout << *it << std::endl;
	//    }

	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	//if a type is too long, you can alias the type
	//with "typedef" or "using"

	//using auto for simple types just makes the code less readable
}