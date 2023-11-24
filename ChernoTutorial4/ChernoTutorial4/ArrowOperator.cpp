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
	Arrow* GetObject() { return m_Obj; }

	//overloading the arrow operator
	Arrow* operator->()
	{
		return m_Obj;
	}

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
	

}