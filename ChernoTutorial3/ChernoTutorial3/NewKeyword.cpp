#include<iostream>
#include<string>
using String = std::string;
//the main purpose is to allocate memory on the heap
//you write new and then the datatype and it determines 
//the size of allocation
//Finds contiguous blocks of memory to match the size
//that is required. Once it finds it, a void pointer
//is returned pointing to that memory

class ExampleObject
{
private:
	String m_Name;
public:
	ExampleObject(): m_Name("Unknown"){}
	ExampleObject(String name) : m_Name(name){}
	const String& GetName()const
	{
		return m_Name;
	}
};

void NewKeyword()
{
	//Stack memory allocation
	int a = 2;
	int* b = new int; //4byte integer allocated on the heap
	int* arr = new int[50]; //allocates 50*4= 200bytes for the int array

	ExampleObject* e = new ExampleObject("Name");

	//makes an array of 50 elements for the class
	ExampleObject* eArray = new ExampleObject[50];

	//We not only allocated memory on the heap
	//we also call the constructor
	//so the new operator does 2 things
	ExampleObject* e2 = new ExampleObject();

	//since new is an operator, you can overload it
	//to change its behavior
	//by default return a void pointer
	//calling new will call the underlying C function malloc()
	//for memory allocation, that takes in a size and returns a void pointer

	//The new keyword is kind of similar to using malloc with the size of
	//data type and a pointer casting to that data type
	//but the difference is that it doesn't call the constructor
	//you should be using the new keyword in c++ in most cases
	ExampleObject* e3 = (ExampleObject*)malloc(sizeof(ExampleObject));


	//When you do use the new keyword, you must use delete
	//delete is also an operator. Takes a block of memory
	//if your value is an array, you need to have square brackets
	//after delete like this:  delete [] var;
	delete b;
	delete[] arr;
	delete e;
	delete[] eArray;
	delete e2;
	//free is the C function to free up memory
	free(e3);

	//placement new
	//you can add a memory address as an argument
	//to the new operator to place the memory at
	//that location
	// 
	//You're not allocatng memory, you are giving
	//the place where the memory should go
	//and can be use for some optimizations
	int* var1 = new int;
	int* var2 = new(var1) int;
	delete var2;
}