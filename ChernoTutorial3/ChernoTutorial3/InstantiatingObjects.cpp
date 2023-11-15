#include<iostream>
#include<string>

using String = std::string;

//how to create your objects in c++
//we we've written a class, we need to
//instatiate it
//
//There are two choices, and the difference is
//where the memory comes from. Which memory we are
//going to be creating our object in.
//
//When we create an object in c++, it needs to occupy some memory
//Even if we make a class that's completely empty (no members)
//it has to occupy at least 1 byte of memory
//
//Stack/heap memory are the main sections of memory
//stacks objects have an automatic lifespan and is controlled
//by the scope they are in. When the scope ends, the stack pops the variable off
//
//When you create an object in the heap, it's going to sit there
//until you decide to free up the memory yourself


class EntityObject
{
private:
	String m_Name;
public:
	//constructor initializer list used
	EntityObject()
		:m_Name("Unknown")
	{
		//Constructor with no parameter
	}
	EntityObject(const String& name)
		:m_Name(name)
	{
		//Constructor with parameter
	}
	const String& GetName() const
	{
		return m_Name;
	}
};
int InstantiatingObjectsMain()
{
	// If you can create an object like this,
	// Do create an object like this, since it's the fastest
	// and managed way of creating an object
	// 
	//Calling default constructor
	EntityObject entity;
	std::cout<<entity.GetName()<<std::endl;

	//Calling with parameter constructor
	EntityObject entity2("Cherno");
	std::cout << entity2.GetName() << std::endl;

	//An alternative way of Calling with parameter constructor
	EntityObject entity3= EntityObject("Cherno");
	std::cout << entity3.GetName() << std::endl;

	//Reasons you can't instantiate an object like this
	//1. You want the object to live outside of the life of the function/scope
	//When the function is called a stackframe gets created for the function
	//that contains all the local variables declared, which included primitive types
	//but also our classes and objects. When the function ends, that stackframe
	//gets destroyed. Meaning all the memory that we had on the stack are gone.

	//an example for stack memory fails
	EntityObject* e; //a pointer for the class Object
	{
		EntityObject entity4("Cherno");
		e = &entity4;//It will point to entity4
		std::cout << entity4.GetName() << std::endl;
	}//end of scope, stackframe gets deleted
	//The pointer is still pointing to the address
	//but now the entity4 object is gone
	//
	//so If we wanted entity4 to live outside the scope
	//we can't allocate the memory in the stack and use the heap
	//
	//Another reason we might want to use the heap or be able to
	//is because the size of the object is too large or too many objects
	//we may not have enough room to allocate memory on the stack
	//the stack memory is small is like 1-2mb depending on the platform
	//or compiler
	//
	//Here is how to allocate to the heap memory
	EntityObject* e2; //a pointer for the class Object
	{
		//The biggest difference is the new keyword
		//we create a pointer to the new EntityObject
		//In java you can only allocate on the heap
		//in c# structs are stack and classes are heap 
		EntityObject* entity5=new EntityObject("Cherno");
		e2 = entity5;
		std::cout << (*entity5).GetName() << std::endl;
		//arrow operator dereferences the pointer for us
		//same code as above
		std::cout << entity5->GetName() << std::endl;

		//We use the delete keyword to free up the heap memory
		//delete entity5;
	}
	//If you want to delete the object from outside the scope
	//we delete using the pointer e defined outside the scope
	//to begin with.
	delete e2;

	//Why allocating on the stack is preferable
	//Performance: it takes longer to allocate on the heap
	//Managing memory: with heap, you need to manually take down the memory
	//or it will cause memory leaks
	//
	//You can use a smart pointer to help with this
	// allocate on the heap, still have the size advantage,
	// automatically delete when pointer goes out of scope,
	// or if sharedPointers have no references
	// This will be explained more thoroughly later on
	// 
	//Ask yourself this:
	//Is my object really big?
	//Do I want to control the lifetime of my object?
	//If you answered no to both, use stack memory

	return 0;
}