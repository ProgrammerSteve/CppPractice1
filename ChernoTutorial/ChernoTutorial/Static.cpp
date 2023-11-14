//Static outside of a class/struct and inside a class/struct have different meanings
//For static outside of a class or struct we will look at this example.

//The linker will not look outside this translation unit/file for the static variable
static int s_Variable = 5;


// Suppose this is the c++ file with the main function
// There will be no Linking error with global vairable s_Variable
// since the s_Variable in Static.cpp is static
// 
//#include <iostream>
// 
//int s_Variable = 10;
// 
//int main()
//{
//	std::cout << s_Variable << std::endl;
//	return 0;
//}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//A way you can avoid a linking error is to
//use the extern keyword to refer to the other file
//for its variable

int s_Variable2 = 5;

// Suppose this is the c++ file with the main function
// There will be no Linking error with global vairable s_Variable
// since the s_Variable2 has the extern keyword and is referencing the s_Variable2
// from the Static.cpp file. This is called External Linking
// 
//#include <iostream>
// 
//extern int s_Variable2 = 10;
// 
//int main()
//{
//	std::cout << s_Variable << std::endl;
//	return 0;
//}


//The static keyword works for functions as well
//You should use static as much as you can if you don't need
//it in any other files