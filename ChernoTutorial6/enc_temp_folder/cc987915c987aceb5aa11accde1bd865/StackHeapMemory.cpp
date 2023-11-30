#include<iostream>

//The stack
//predefined, Has about 2mb
// 
//The heap
//predefine, but can grow
//and change as the program goes on

//Suppose we want to store an int (4byte)
//how do we find 4 bytes of contiguous memory
//The stack will gives up that memory
//versus the heap is different

//You can access the memory view on visual studio
//by selecting debug->windows->memory->Memory 1

struct Vector3
{
	float x, y, z;

	//set default values in constructor
	Vector3(): x(10),y(11),z(12){}
};


void StackHeapMemory()
{
	//allocated on the stack with value 5
	int value = 5;

	//new keyword returns a pointer to where
	//the memory is stored via the heap
	//we dereference the pointer and set it to 5
	int* hvalue = new int;
	*hvalue = 5;

	//array allocated on the stack
	int array[5];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	//array allocated on the heap
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;

	//main difference is that you use the new
	//keyword to begin allocating memory on the heap


	//struct example
	Vector3 vector;
	Vector3* hvector = new Vector3();



}