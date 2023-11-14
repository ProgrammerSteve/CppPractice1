//Enum is short for enumeration, and is a set of values
//is a way to give a name to a set of values
//you can limit what can be used for what
//can be good for states
//is really just an integer

#include<iostream>

//The issue here is a,b,c
// are not grouped at all
int a = 0;
int b = 1;
int c = 2;

enum Example
{
	A,B,C
};

//You can set a value to enums
//by default it would just be 0,1,2,...
//just use the equal sign
//if you don't specify all of them
//the next value will be the incremented
//value of the last specified value
//Thus N=16
enum Example2
{
	L=10, M=15, N, O=19
};


//By default enums are 32bit integers
//but you can specify the type using : after the name
//float doesn't work with it
enum Example3: unsigned char
{
	E,F,G
};



int mainEnum()
{
	//You can assign a value outside of a,b,c
	//which is a problem if you don't want that behavior
	int value = b;
	if (value == b)
	{
		//Do something here
	}

	//This forces value2 to be either A,B,or C
	Example value2 = B;
	//enums are just integers at the end of the day
	//A,B,C hold values 0,1,2, respectively
	//So if value2 is B, value2 is 1 and the if
	//statement will get triggered
	if (value2 == 1)
	{
		//Do something here
	}


	std::cin.get();
	return 0;
}