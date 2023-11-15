#include<iostream>
#include <array>

class EntityArray
{
public:
	int exampleArray[5];
	EntityArray()
	{
		for (int i = 0; i < 5; i++)
			exampleArray[i] = 2;
	}
};

int ArrayMain() {

	int example[5]; //declares an array of 5 integers
	example[0] = 5; //Sets the element value at index 0
	example[4] = 4; //Sets the last element value at index 4

	std::cout << example[0] << std::endl;
	std::cout << example[4] << std::endl;

	for (int i = 0; i < 5; i++)
		example[i] = 2;

	//Causing a memory access violation
	//accessing memory that hasn't been allocated
	//for the array. In debug mode, it'll throw an error
	//In production mode, it will overwrite the memory in your code
	//and can mess up the program. Setting up safety checks 
	//can help to prevent this issue
	// 
	//example[-1] = 5;
	//example[5] = 3;
	std::cout << std::endl << std::endl;
	std::cout <<"Output: " << std::endl;
	std::cout << example[0] << std::endl;
	std::cout << example[1] << std::endl;
	std::cout << example[2] << std::endl;
	std::cout << example[3] << std::endl;
	std::cout << example[4] << std::endl;
	std::cout << std::endl << std::endl;

	//This returns the memory location, since it's really just a pointer
	//Looking at the memory, int are 4bytes, so you'll see 20bytes of memory used up
	//by the array.
	std::cout << "Printing Memory: " << std::endl;
	std::cout << example<< std::endl<<std::endl; 


	//Since the int array is just an int pointer, we can
	//pointers can be used as such:
	int* ptr = example;
	//accessing example[2] by moving up 2 and dereferencing it
	*(ptr + 2) = 6;

	//We needed to go up 8 bytes to reach example[2]
	//when doing pointer arithmetic, the number added
	//will be based on the type, since it's an int ptr,
	//It'll add 4 per number added so address+2*(4bytes)


	std::cout << std::endl << std::endl;
	std::cout << "Output With Pointer Manipulation: " << std::endl;
	std::cout << example[0] << std::endl;
	std::cout << example[1] << std::endl;
	std::cout << example[2] << std::endl;
	std::cout << example[3] << std::endl;
	std::cout << example[4] << std::endl;
	std::cout << std::endl << std::endl;


	//Just like you can make classes with the new keyword
	//you can create arrays with the new keyword

	
	// This gets created on the stack: int example[5]
	//
	//This will be created on the heap and will be alive
	//until we destroy it with the delete keyword
	//since it is an array and we allocated it using the
	//array operator [], we need to delete it using the
	//square brackets as such: delete[] another;
	int* another = new int[5];
	for (int i = 0; i < 5; i++)
		another[i] = 2;
	delete[] another;

	//Why would you allocate memory for an array
	//using the new keyword instead of stack memory?
	//The biggest reason is for lifetimes. It will be around until
	//you delete it.


	//Defining a c++ 11 array
	//you put the type and size in arrow brackets
	//it includes the size method and bounds checking
	//A lot safer than raw arrays, but raw arrays have
	//a slight speed advantage
	std::array<int, 5> array11;
	for (int i = 0; i < array11.size(); i++)
		array11[i] = 2;

	return 0;
}

//in c++11 it included a standard array and includes size
//and bounds checking. The raw array we used doesn't have a 
//way of checking the size

//To get the size of an array, you get to total memory
//and divide it by the size of the type
//only works for stack allocated arrays, not pointers
static int a[5];
static int count = sizeof(a) / sizeof(int);//5

//Since the size has to be known at compile time, you need
//to set up the size variable as static const int to define
//the size of the array. We can then use it in our for loop
//for initializing.
class ExampleArray {
public:
	static const int exampleSize = 5;
	int example[exampleSize];
	ExampleArray()
	{
		for (int i = 0; i < exampleSize; i++)
			example[i] = 2;
	}
};