#include<iostream>

class Arrow
{
public:
	void Print() const
	{
		std::cout << "Hello!" << std::endl;
	}
};


class ScopedPtr
{
private:
	Arrow* m_Obj;
public:
	ScopedPtr(Arrow* entity)
		:m_Obj(entity) {}
	~ScopedPtr()
	{
		delete m_Obj;
	}
	//A way to get the obj pointed towards to use its method
	//but can look messy
	Arrow* GetObject() { return m_Obj; }

	//makes the scope pointer behave like
	//a pointer to the original object by
	//overloading the arrow operator
	Arrow* operator->()
	{
		return m_Obj;
	}
	//consider 
	// const ScopedPtr entity=new Arrow();
	// You need to overload for this situation
	//const version of overloading the arrow operator
	const Arrow* operator->() const
	{
		return m_Obj;
	}
};


struct Vector3
{
	float x, y, z;
};


void ArrowOperator()
{
	Arrow a;
	a.Print();

	//Can't use ptr.Print() to access the method directly with the pointer
	//It is only a numeric value and need to be dereferenced in order
	//to call methods from the class the pointer is pointing to
	//
	//Due to order of operations, you need to use () with *ptr to dereference
	//first
	Arrow* ptr = &a;
	(*ptr).Print();
	//arrow function is a shorthand way of dereferencing a class and calling
	//a method.
	ptr->Print();
	//The ScopedPtr class deletes the class when it goes out of scope
	ScopedPtr entity = new Arrow();
	entity->Print();


	//lets say you want to find the offset each member
	//in memory
	//in the Vector3 struct
	//
	//can also be:
	//int offsetX=(int)& ((Vector3*)0)->x;
	int offsetX=(int)& ((Vector3*)nullptr)->x;
	int offsetY = (int)&((Vector3*)nullptr)->y;
	int offsetZ = (int)&((Vector3*)nullptr)->z;
	//casts a nullptr into Vector3* struct, then
	//uses reference operator to get memory
	std::cout <<"X: " << offsetX 	//casts into an int
<< std::endl;
	std::cout << "Y: " << offsetY << std::endl;
	std::cout << "Z: " << offsetZ << std::endl;

	//useful when you want to serialize your data
	//into a string of bytes. And you want to figure
	//out the offsets of certain things

	//In summary:
	//	We are casting a base arbitrary address to a Vector3 pointer
	//  type and then retrieving the address of a specific field
	//  from the struct.Since the base arbitrary address is 0,
	//  the returned address actually corresponds to the offset!
	

}