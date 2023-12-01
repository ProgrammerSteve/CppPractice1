#include<iostream>
#include<string>
//using the preprocessor in c++ in order to "macrofy"
//instead of typing some code over and over again,
//you can use the preprocessor and a macro to write it for you

//Preprocessor pass occurs first
//all lines that start with a hash, # is a preprocessor
//it is a text editing stage and kind of control which
//code gets sent to the compiler

//you can do find/replace code with parameters
//This is different from a template since
//templates get evaluated later at compile time
//macros is just in the preprocessor before the compiler

//it's hard for people who read your code for the first
//time to understand what your code is doing if you
//overuse macros or templates


//writing a macro using the define keyword
//we define the word WAIT with the value of
//std::cin.get()
//we leave out the semicolon since we will add it within our code
//if WAIT is defined in a different file, the programmer would
//have to look for the definition of it which can be annoying
//so using macros senselessly for little things like std::cin.get()
//isn't a good use of macros
#define WAIT std::cin.get()

//macros aren't limited to just expressions
//we can define OPEN_CURLY to be the open curly bracket symbol
//and use it in our code
#define OPEN_CURLY {
#define CLOSE_CURLY }
//another thing you can do is set parameters for macros
//here we define LOG which takes in x and std::cout the value
#define LOG(x) std::cout<<x<<std::endl



//for more complicated projects, the way you log values
//can be different from normal, so using a macro to 
//ease the process is ideal
//
//We can also set the logging macro to only run in debug mode
//but not in production (release mode)

//right click your project, go to settings, change the configuration to Debug
//Go to C/C++->Preprocessor->Preprocessor Definitions
//and define a value _DEBUG; might actually be already defined
//depending on the compiler

//We could also do this in the release environment too

//defining a macro using #ifdef to check the environment first
//In our #else we set the macro function to be nothing, so any instances of it
//in our code gets replaced with nothing
//leaving a ";" by itself is a blank statement and does nothing
//so whether you include or exclude the semicolon in the macro doesn't matter

//here is the overall structure of #ifdef
//#ifdef
//#define ....
//#else
//#define ...
//#endif

#ifdef _DEBUG
#define LOG_DEBUG(x) std::cout<<x<<std::endl
#else
#define LOG_DEBUG(x)
#endif

//Another way is to use #if and defining a value for your define
//this allows you to control the macro from the code itself
//or you can define PR_DEBUG in the properties of the project
#define PR_DEBUG 1
#if PR_DEBUG==1
#define PR_LOG_DEBUG(x) std::cout<<x<<std::endl
#else
#define PR_LOG_DEBUG(x)
#endif


//You can allow make multiple lines of code
//inactive using the #if macro
#if 0
any code here will not run
#endif

//when you define something, it doesn't have to be all in one line
//if you use the backslash character \ 
#define FOO void foo()\
{\
	std::cout<<"foo"<<std::endl;\
}

//Macros are mostly useful for debugging purposes and dealing
//with code only allowed in certain environments

FOO

void Macros()
OPEN_CURLY
	LOG("hello");
	LOG_DEBUG("DEBUG MODE...");
	//FOO macro defines the foo function in the preprocessor step
	foo();
	//suppose you want to add
	//std::cin.get();
	//with a macro instead of writing it
	WAIT;
CLOSE_CURLY