#include<iostream>
//using static in a local scope to declare a variable
//different from using static in global and classes
//
//allows us to declare a variable that has the lifetime of
//the entire program, however, the scope is limited into
//inside a function
//
//useful for singletons design pattern
//adding static extends the lifetime of the variable
//as long as the program runs
//
//Not using local static
//code is more messier
class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get()
	{
		return *s_Instance;
	}
};
//have to declare it
Singleton* Singleton::s_Instance = nullptr;

//Using local static
//makes it much simpler
class SingletonLocalStatic
{
public:
	static SingletonLocalStatic& Get()
	{
		static SingletonLocalStatic instance;
		return instance;
	}
};

void FunctionExample()
{
	static int i = 0;
	//on subsequent calls to the function
	//it's not actually to create a brand
	//new variable
	i++;
	std::cout << i << std::endl;
	//if you didn't have the static keyword
	//you would expect 1 being printed every time
	// 
	//but with the static keyword,
	//cout displays 1, then 2, then 3 and so on
	//
	//would have the same effect as puting int i
	//outside the scope of the function
	//but then i can be accessed anywhere
	// 
	//only difference with a local static
	//is that it's only available in the function scope
	//
}
void LocalStatic()
{
	FunctionExample();
	FunctionExample();
	FunctionExample();
}