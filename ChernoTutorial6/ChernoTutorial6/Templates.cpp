#include <iostream>
#include<string>
//Similar to generics in other languages, but is more powerful
//since a template can be thought of as a macro that isn't limited
//by the type system

//allows you to define a template to make the compiler write code for you
//based on the rules/blueprint you set for it

//if you want to create a function that is the same but takes in
//different types. You need a lot of overloads to cover everything
void PrintOverloaded(int value)
{
	std::cout << value << std::endl;
}
void PrintOverloaded(float value)
{
	std::cout << value << std::endl;
}
void PrintOverloaded(std::string value)
{
	std::cout << value << std::endl;
}

//If you want to write the code once and fill in the blanks
//you can use a template. You define a template by writing template
//and having arrow brackets with typename and a variable T
//This isn't actually real code, it gets evaluated at compile time
//to cover all the situations you encounter
//
//The template parameter we use, typename followed by the variable we want to
//use at the type, in this case T
//you can also write it using the class keyword and it will be
//exactly the same
//template<class T>
//
//If you never use the Print Template, you can make syntax mistakes and
//it doesn't get compiled since it wasn't used.
//it doesn't exist until you call it, so it isn't really code until called
//
//Some compilers might complain, but it's specific to the compiler
//
//templates aren't limited to just functions, they can be used on entire classes
template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
}


//suppose you want to create an array but it will be created on the stack
//we will create a class with template. Arrays usually need a size but it
//isn't known, you can pass a int template parameter to substitute for that
//we can add multiple parameters, such as typename T in front
//so that we can specify the type of the Array at compile time
template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const
	{
		return N;
	}
};


//This can be thought of as Metaprogramming and can get really
//complicated really easily
//some companies ban templates altogether
//it can be good for a logging system
//if you get too complex and develop your own meta language with it
//then you're probably going too far and will be hard
//to debug by a team of developers
//
//unlike functions, you must either write the templates and use them inside a SINGLE
//source (cpp) file OR, you must write them ENTIRELY inside a header file.
//The linker will have trouble linking the templates

void Templates()
{
	//Now supposed you want to now use a string
	//with Print. You would need an overload
	//with a template all three function invokes work
	Print(5);
	Print(5.5f);
	Print("hello");

	//Here we are using int as the template argument
	//this makes our function void Print(int value)
	//we could specify the type, but we don't have to
	//if the parameter can be inferred.
	Print<int>(3);

	//creates a stack allocated array with size 5
	Array<int,5> array;
	//the method that uses N will receive the template argument
	std::cout << array.GetSize() << std::endl;
}