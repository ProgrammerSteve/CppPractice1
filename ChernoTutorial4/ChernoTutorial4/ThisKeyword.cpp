#include<iostream>
//The this keyword is only accessible to us in a member function
//a function inside a class. It is a pointer to the current
//object instance the member belongs to

//In order to call that method, you need to instantiate an object first
//this is a pointer to that object from within its method

class ThisEntity;
void PrintThisEntity(ThisEntity*);
void PrintThisEntityTwo(const ThisEntity&);

class ThisEntity
{
public:
	int x, y;
	ThisEntity(int x, int y)
		//:x(x),y(y)
	{
		//Usually you can just use a constructor initializer list
		//but if you wanted to initialize from within the body, you will
		//be faced with a problem. They have the same name.
		//you need to reference the x y members and not the parameters,
		//you will need to use this as a pointer
		//ThisEntity* e = this;
		//(*e).x = x; You need to dereference the pointer to change the value
		//(*e).y = y; You need to dereference the pointer to change the value
		//using the arrow operator is easier
		this->x = x;
		this->y = y;

		//Using an outside function
		//with the class instance
		PrintThisEntity(this);

		//You can delete the instance from within
		//but can lead to errors and is not
		//typically done. Only in rare instances
		//delete this;
	}

	int GetX()const
	{
		//when a method uses const
		//the this pointer doesn't equal
		//ThisEntity* e = this;
		//instead it is equal to
		//const ThisEntity* e = this;
		//since you can't change the values of members

		//an outside function that
		//uses a const ref can still take this
		//as a parameter, you just need to
		//dereference it first
		PrintThisEntityTwo(*this);
		return x;
	}
};


//This function takes in a pointer to the class
//as an input. If you wanted to use an outside function
//inside of the class, you will need the this keyword
void PrintThisEntity(ThisEntity* e)
{
}

//This uses a const reference instead of a pointer
void PrintThisEntityTwo(const ThisEntity& e)
{
}

void ThisKeyword()
{
	std::cout << "running...\n";
}