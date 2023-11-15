#include<iostream>

static int s_Level = 11;
static int s_Speed = 2;

void PrintLevel()
{
	std::cout << "s_Level: " << s_Level << std::endl;
}
void PrintSpeed()
{
	std::cout << "s_Speed: " << s_Speed << std::endl;
}



int TernaryMain()
{
	std::cout << "Beginning code..." << std::endl;
	std::cout << "################################################" << std::endl;
	PrintLevel();
	PrintSpeed();
	std::cout << "################################################" << std::endl;

	//A typical if and else situation
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;
	std::cout << "if (s_Level > 5) s_Speed = 10; else s_Speed = 5;" << std::endl;
	PrintLevel();
	PrintSpeed();
	std::cout << "################################################" << std::endl;
	//A ternary operation checks the statement
	//if true, the value after ? will be the value
	//if false, the value after : will be the value
	//
	//It cleans up the code to be concise but
	//its usage is subjective
	s_Speed = s_Level > 5 ? 10 : 5;

	std::cout << "s_Speed = s_Level > 5 ? 10 : 5;" << std::endl;
	PrintLevel();
	PrintSpeed();
	std::cout << "################################################" << std::endl;
	//another example
	std::string rank = s_Level > 10 ? "Master" : "Beginner";

	//equivalent to the statement above except
	//an empty string object is created and overwritten
	//Is technically slower by a small amount
	std::string otherRank;
	if (s_Level > 10)
		otherRank = "Master";
	else
		otherRank = "Beginner";

	//You can nest ternary operators
	//This is where it can look a little confusing
	s_Speed = (s_Level > 5) ? (s_Level > 10 ? 15 : 10) : 5;
	std::cout << "s_Speed = (s_Level > 5) ? (s_Level > 10 ? 15 : 10) : 5;" << std::endl;
	PrintLevel();
	PrintSpeed();
	std::cout << "################################################" << std::endl;

	//Add && will make the conditional statement longer, but still work
	s_Speed = (s_Level > 5 && s_Level<100) ? (s_Level > 10 ? 15 : 10) : 5;
	std::cout << "s_Speed = (s_Level > 5 && s_Level<100) ? (s_Level > 10 ? 15 : 10) : 5;" << std::endl;
	PrintLevel();
	PrintSpeed();
	std::cout << "################################################" << std::endl;


	return 0;
}