#include<iostream>
#include"GLFW/glfw3.h"
//compiling your code helps to run the code
//without any additional setup is nice
//but can take some time
// 
//linking binaries for GLFW
// www.glfw.org
// clicking Download button on home page
// gives you the source code for GLFW
// 
// but if you click download on the navbar
// you will see Windows pre-compiled binaries
// for 32bit or 64bit binaries
// you choose based on your target device
//
//binaries may now be available for the
//library you want to use and you might
//have to build it yourself. This is
//usually the case when you use Mac and Linux
// 
//There are two parts to a library
//includes and lib/libraries directory
// 
//includes has a bunch of header files
//that we need to use to find function in prebuilt
//binaries
//
//There are two types of libraries
// dyanimc libraries and static libraries
// not all libraries give you both options
// glfw has both static and dyanmic
//
// you can choose to link statically or dynamically
// we will discuss the difference between
// static linking and dynamic linking
// 
// static linking
// means that the libaries get put inside your executable
// in your .exe
//
//dynamic linking
// gets linked during runtime
//
//You can choose to load a library on the fly
//There's a windows api function called loadLibrary
//or
//at application launch it loads your .dll library
//  
//static linking can be faster because the compiler
//can do linktime optimizations since it
//knows the functions at linktime
//
//In summary we have Includes files and library files
//in our compiler in visual studio, we have to point
//it to the header files in the include files
//to know what functions are available to us
//
//Then we point the linker to the library files
// to get the function definition linked correctly
//
//To begin, we make a directory called Dependencies
//then we'll add a folder named GLFW
//and we'll add the include and lib-vc2022 or latest to it
//
//Right click the project in teh solution explorer and 
//click properties, go to c/c++->general->additional include directories
// Using the macro $(SolutionDir) to get root of project path and make a path
// to the include folder
//   $(SolutionDir)\Dependencies\GLFW\include
//
//on the top left, for the configuration: drop down, pick all configurations
//on platform in the top right, make sure you select the correct platform: Win32, Win64, ...
//
//Now you can do #include "GLFW/glfw3.h"
//if you compile the code, you will get no errors now
//
//Because it is a compiler specified include path
//you can use angular brackets #include <GLFW/glfw3.h>
//quotes vs angular brackets
//quotes will check relative paths first, then check in the compiler include paths
//so both will work. 
// One way to organize it is if the source code is included in the solution, and doesn't
// need a external library, use quotes, else use angular brackets
// If a library is included in the solution, you can use quotes
//
//If you try using a function from the GLFW library, it will have a linking error
//even though the IDE doesn't show an error due to the header files
//you haven't linked the actual library, only included the headers
// 
// 
//Go back to project properties, go to Linker, then to General, then Additional Library Directory
// $(SolutionDir)\Dependencies\GLFW\lib-vc2022
// 
//Then in Linker->Input->Additonal Dependencies, we need to specify the library we are going to use
//in this case, it is glfw3.lib

void UsingLibraries() {
	int a = glfwInit();
	std::cout << a << std::endl;
}