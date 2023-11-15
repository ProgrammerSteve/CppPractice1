#include<iostream>
#include<string>

//Imports a C library
#include<stdlib.h>

int StringLiteralMain()
{
	//even though Cherno has 6 characters, the string literal has
	//7 due to the null termination character
	const char* stringLiteral = "Cherno";

	//Prints out 3 due to the manually inserted termination char
	const char name[8] = "Che\0rno";
	std::cout << strlen(name) << std::endl;


	//string literals are stored in a read only section of memory
	//The code below may or maynot be allowed depending on the compiler
	//char* name="Cherno"
	//name[2]='a';

	//If you do want to modify the string, you need to use
	//an array and not a pointer
	//char[] name="Cherno"
	//name[2]='a';


	//Depending on the OS and compiler, these characters can take up different
	//number of bytes

	//Wide characters
	//2bytes per character
	const wchar_t* name2 = L"Cherno";


	//char16_t
	//2bytes per character
	const char16_t* name3 = u"Cherno";


	//char32_t
	//8bytes per character
	const char32_t* name4 = U"Cherno";


	//normal const char
	//can use u8 or not
	const char* name5 = u8"Cherno";

	return 0;
}