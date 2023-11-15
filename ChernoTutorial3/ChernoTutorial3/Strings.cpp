#include <iostream>
#include <string>

//This creates a copy of the class and giving
//it to the function which makes you allocate more memory
//in the heap and makes it slower.
//void PrintString(std::string string)
//{
//
//}

//This way avoids copying the string
//and should be used if the string is read only
//const reference
static void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}


// To understand how strings work, 
// you need to understand characters char
// char is 1 byte of memory
// useful for casting pointers into char pointers
// to do pointer arithmetic in terms of 1 byte at
// a time. It is also useful for allocating memory buffers
// since 1kb =1024bytes.

// It is also useful for strings and text
// ASCII character set have 1 byte
// Foreign languages sometimes can't be represented by ASCII
// A string is an array of characters
int StringMain()
{
	// C style string
	//C++ library has string build in
	const char* name = "Cherno";
	std::cout << name << std::endl;
	//you don't need to declare it as const char
	//but people do that since strings are
	//immutable since it's a fixed block of
	//allocated memory. It isn't heap allocated
	//if you don't use the new keyword, don't
	//use the delete keyword.

	//If you look at the memory, the char arr ends with a 0
	//this is called the null termination character
	//We don't know the size of the char arr if it's just a pointer
	//So the null termination character is necessary.
	
	//If you do this manually
	//note: single quotes are used for characters
	//using double quotes turns it into a char pointer
	//char name2[6] = { 'C','h','e','r','n','o' };
	//std::cout << name2 << std::endl;
	//This is the output without the null termination character
	//Cherno╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠h

	//'\0' or simply 0 can act as the null
	//termination character in a char pointer
	char name3[7] = { 'C','h','e','r','n','o',0 };
	std::cout << name3 << std::endl;

	//A c++ string using the string library
	//The string is a const char[7] array type
	//the 7th char being the null termination character
	//You can use string with <iostream> but it won't
	//let you print the string with cout<<
	//so you need the #include<string>
	std::string name4 = "Cherno";
	std::string greeting = "hello ";
	std::cout << name4 << std::endl;

	std::cout << std::endl << std::endl;
	//appending strings won't work this way
	//std::string exampleString = "Hello " + "Cherno";

	//To get the same result, split it to different lines
	std::string name5 = "Cherno";
	name5 += " hello";
	//Now you're adding a pointer to the name string
	//+= is overloaded in the string class to allow for this
	std::cout << name5 << std::endl;

	//Another way is to cast string to the const char array and add as such:
	std::cout << std::string("Cherno") + " hello!" << std::endl;

	//To find string in a text, you can use the .find() method
	//std::string::npos is the return for an illegal position
	//if "no" is not in the variable, npos would get returned
	//We can get a boolean by using the != logic operator to compare
	bool contains= name5.find("no") != std::string::npos;
	std::cout << contains << std::endl;
	return 0;
}