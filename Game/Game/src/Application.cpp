#include<iostream>

//This tutorial deals with working with multiple projects

//with properties, we add engine to our additional include dir
//so we can include it in this manner
#include "Engine.h" 

//relative path but isn't ideal
//#include "../../Engine/src/Engine.h"

//writing header manually
//namespace engine {
//	void PrintMessage();
//}

//for Engine properties->configuration properties, set to static library
//leave Game properties->configuration properties as application.exe
// 
// 
//in Game c/c++ additional include directory, add
//$(SolutionDir)\Engine\dir
//in Game, add a reference to the Engine folder to deal with linking

int main()
{
	engine::PrintMessage();
	std::cin.get();
}