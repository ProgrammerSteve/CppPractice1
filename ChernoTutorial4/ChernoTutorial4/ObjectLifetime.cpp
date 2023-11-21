#include<iostream>

//Talk about Memory and how objects live on the stack
//What lifetime means for stack variables
//you need to understand how thing live on the stack
//
//stack is a datastructure where you stack things on top
//and you can remove the top from it
//We push a stack frame on it with a scope
//when the scope ends, the stack frame gets popped off
//and is now gone.
//
//We have function scopes, if/else scopes, loop scopes, class scopes, and empty scopes

class LifetimeEntity {
public:
	LifetimeEntity()
	{
		std::cout << "Created class instance\n";
	}
	~LifetimeEntity()
	{
		std::cout << "Destroyed class instance\n";
	}
private:

};


int* CreateArrayBadExample()
{
	//allocates memory for 50 ints, 50*4=200bytes
	//Problem is that it's allocated on the stack
	int array[50];
	//returns a pointer to that stack memory
	//gets cleared when we go out of scope
	//it will fail
	return array;
}
int* CreateArrayGoodExample()
{
	//allocates memory for 50 ints, 50*4=200bytes
	//it's allocated on the heap
	int* array=new int[50];
	return array;
}
void FillExistingStackArray(int* array)
{
	//fill our array
}



//sets up a scoped pointer that gets initalized
//with a pointer to the LifetimeEntity class
//and deletes it afterwords
class ScopedPtr
{
private:
	LifetimeEntity* m_Ptr;
public:
	ScopedPtr(LifetimeEntity* ptr)
		:m_Ptr(ptr)
	{

	}
	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

void ObjectLifetime()
{

	//Stack based variable in a scope
	{
		//constructor called
		LifetimeEntity e;
		//destructor called
	}

	//Heap based variable in a scope
	{
		//constructor called
		LifetimeEntity* e2=new LifetimeEntity();
		//destructor never called
		//memory does get cleaned up when our
		//application terminates, but not
		//while the code runs
	}

	//You can use a stack allocated array from the larger scope
	//and fill it within a function scope, instead of heap memory
	int array[50];
	FillExistingStackArray(array);


	//Things that can be done with scopes
	//Scoped pointer, a class that's a wrapper over a pointer
	//which upon construction, heap allocations the pointer
	//upon destruction, deletes the pointer


	//Making a ScopedPtr class to heap allocate but
	//deletes when it goes out of scope. You can use a unique pointer
	//but we will write it manually

	//This demonstrates what a very basic smart pointer, unique pointer does
	{
		std::cout << "\n\nEntering scoped pointer scope...\n";
		//without impilict conversion
		LifetimeEntity* e2 = new LifetimeEntity();
		ScopedPtr s2 = ScopedPtr(e2);

		//uses implicit conversion
		//gets allocated on the stack
		ScopedPtr s = new LifetimeEntity();

		//at the end of the scope, the ScopedPtr gets deleted
	}
	std::cout << "Exited scoped pointer scope...\n";

	//a good use of unique pointers are timers
	//time how long you were inside a scope for benchmarking
	//you start and stop the timer when constructed until destruction

	//mutex locking
	//you want to lock a function so that multiple threads can't
	//access it at the same time and cause an error. use a scoped lock
}