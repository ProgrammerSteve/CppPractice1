#include<iostream>
#include<GLFW/glfw3.h>
//
//Dynamic Linking is linking that happens at runtime
//and isn't included in the executable
//Static linking is aware of all the functions and can optimize the
//performance. So static is faster
// 
// 
// For dynamically loading libraries into your code, 
// You can have it to where you code knows you will
// load a library dynamically and will throw an error
// if it isn't present on runtime
// 
// alternatively,in your executable code you can write code
// that looks for and loads certain dynamic libraries
// and obtain function pointers to use the functions
// 
// There are some differences when you want to 
// declare functions when you link statically vs dynamically
//
// In our lib-vc2022 folder there are 4 files:
//glfw3.lib, glfw3.dll, glfw3dll.lib, glfw_mt.lib
// glfw3dll.lib is just a series of pointers into the glfw3.dll file
// so you don't have to retrieve the locations of everything at runtime
//
// it is important you compile glfw3.dll and glfw3dll.lib at the same time
// for dynamic linking, Because you'll end up with function mismatching and other errors
// 
//for static, we included glfw3.lib with properties\Linker\input\Additional Dependencies
//we will replace it to glfw3dll.lib
//
//we get an error message, The code execution cannot proceed because glfw3.dll was not found.
//we have to put our .dll file into the same folder as the executable
//which is in the Debug folder
//
//You can set paths to folders with the .dll, but the root folder of your
//executable is the default
void DynamicLibraries() {
	int a = glfwInit();
	std::cout << a << std::endl;
}