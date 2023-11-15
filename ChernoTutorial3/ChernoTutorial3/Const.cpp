#include<iostream>

//Kind of a fake keyword since
//it doesn't do much to the code when compiled
//It's like a promise that a variable won't be changed


class EntityC
{
//It's best to mark your methods with const
//if it doesn't modify any of the member variables
//within your class
private:
	int m_X, m_Y;

	//Note: If you want to declare multiple pointers at once
	// you need to put an asterisk for every variable
	//int *m_A, *m_B;
	int* m_Z;

	//setting this as mutable allows it the variable
	//to be changed in const methods
	mutable int var;
public:
	//Put a const on the right side of the method name
	//only works in a class
	//This method cannot modify class member variables
	//Good for read-only methods such as getters
	int GetX() const
	{
		//m_X = 2; <-error
		return m_X;
	}
	//returns a pointer that cannot be modified
	//its content cannot be modified
	//This method cannot modify the class member variables
	const int* const GetZ()const
	{
		return m_Z;
	}
	//Can't be const since it is a setter
	int SetX(int x)
	{
		m_X = x;
	}

	int GetXWithMutable() const
	{
		//here we are able to get away
		//with changing a variable in the class
		//since var is a mutable

		//In situations where you need to
		//change a variable's value in a getter and it
		//doesn't affect the result of the code
		//setting it to mutable would be the solution
		var = 2;
		return m_X;
	}
};

//It's better to pass with a const reference
//Since you don't want to copy the entity class
//because it'll slow down the code if it's read only
//This states that the EntityC class is const
//just like a pointer const int*, you can modify
//what it's pointing towards, but you cannot change
//the value when you dereference the pointer


void PrintEntity(const EntityC& e)
{
	//if you remove the const from the method:
	//int GetX() const
	//you aren't allowed to call it here
	//since it doesn't guarantee that you
	//won't alter the class member variables
	//Sometimes programmers will overload their
	//getters to have and not have the const
	//keyword for convenience but can look messy
	std::cout << e.GetX() << std::endl;
}

int ConstMain()
{
	const int MAX_AGE = 90;

	// int a cannot be modified due to the const keyword
	const int a = 5;

	//There are several uses for const
	//pointers
	//declared on the heap
	int* b = new int;
	//dereference and set a value
	*b = 2;
	std::cout << *b << std::endl;
	//setting the pointer to MAX_AGE with a reference
	//needs to be casted into an int pointer to work
	b = (int*) & MAX_AGE;
	std::cout << *b << std::endl;
	//Not something you should do since you can cause an error


	//##################################################
	//adding const to a pointer
	//- you cannot modify the contents of that pointer
	const int* c = new int;
	//*c = 4; //<-error due to const
	c = &MAX_AGE;// no error, you just can't change the contents of that variable

	//Putting const after the pointer
	int* const d = new int;
	*d = 2;//You can change the contents
	//d=&MAX_AGE// <-- can't change the pointer itself
	

	//So cont int* and int* const are kind of the opposite
	//const int* var= can't change value, can change pointer
	//int* const var=can change value, can't change pointer

	//finally we have const int* const
	const int* const e = new int;
	//cannot change the value or the pointer to
	//point to something else

	EntityC entity;

	return 0;
}