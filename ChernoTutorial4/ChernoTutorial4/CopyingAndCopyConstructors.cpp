#include<iostream>
//a lot of the time we want to copy an object
// so we can modify them in certain way,
// 
// but if we can avoid unnecessary copying
// such as only wanted to read the value
// we definitely should do that
// 
// understanding copying and getting it to work
// and avoid it is very important
// 
// 
// 
// 
// 
// 

class String
{
private:
	//points to the array location
	//in memory
	char* m_Buffer;
	//keeps track of the size
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		//+1 for null termination character
		m_Buffer = new char[m_Size+1];
		memcpy(m_Buffer, string, m_Size);
		//adding null termination with 0 at the last index
		m_Buffer[m_Size] = 0;
	}
	//Copy constructor takes a const ref to the same class
	//c++ supplies this automatically with a memcpy
	//We can set the copy constructor to = delete
	//to prevent copying, similar to unique pointers
	//String(const String& other)=delete;
	//String(const String& other)
	//	:m_Buffer(other.m_Buffer), m_Size(other.m_Size)
	//{
		//another way of putting it
		//memcpy(this, &other, sizeof(String));
	//}
	//m_Size can be shallow copied
	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "Copied string...\n";
		//sets buffer from other into m_Buffer
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size+1);
	}
	~String()
	{
		//making sure there is no memory leak
		delete[] m_Buffer;
	}
	//using the friend keyword allows that function
	//outside of the class to access private members of the class
	friend std::ostream& operator<<(std::ostream& stream, const String&);

	//overloads [] operator
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}
};

//overload Cout for the String class
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

struct Vector2
{
	float x, y;
	Vector2(float x, float y)
		:x(x),y(y)
	{}
};

//creates a copy of string which
//triggers the copy constructor
void PrintString(String string)
{
	std::cout << "PrintString invoked...\n";
	std::cout << string << std::endl;
}

//if we don't mark it with const
//you are saying that the string can be edited
//we can't pass temporary R values
//we pass with reference so it doesn't copy
void PrintStringByRef(const String& string)
{
	std::cout << "PrintStringByRef invoked...\n";
	std::cout << string << std::endl;
}

void CopyingAndCopyConstructors()
{
	int a = 2;
	//creating a copy of a
	//a and b are two separate variables
	//with diffrent memory addresses so
	//if b is changed, a remains unchanged
	int b = a;

	//works similar with classes
	Vector2 v1 = { 2,3 };
	Vector2 v2 = v1;

	v2.x = 5;
	//v1.x will remain equalling 2

	//using heap allocation with the new keyword
	//these are pointers, so we are copying the pointer
	//that point to the same memory
	Vector2* p1 = new Vector2(2, 3);
	Vector2* p2 = p1;
	std::cout << "p1: \n";
	std::cout << "x: " << p1->x << ", y: " << p1->y << std::endl;
	std::cout << "p2: \n";
	std::cout << "x: " << p2->x << ", y: " << p2->y << std::endl;
	std::cout << "\nmaking changes to p2...\n";
	//will affect pointer p1 as well as pointer p2
	p2->x = 3;
	std::cout << "p1: \n";
	std::cout<<"x: "<< p1->x <<", y: " << p1->y << std::endl;
	std::cout << "p2: \n";
	std::cout << "x: " << p2->x << ", y: " << p2->y << std::endl;

	std::cout << "\n\n";
	//Set up custom String class
	String string = "Cherno";
	//shallow copy, get's the pointer and int
	String second = string;
	//crashes when copying string to second
	//the memory address for both of the buffers is
	//the same for both of the strings
	//crashes when the destructor tries to delete
	//the same block of memory twice
	std::cout << string << std::endl;
	std::cout << second << std::endl;

	//using overloaded [] operator, we can do this
	second[2] = 'a';
	//edited the second string, but it affects both
	//since they point to the same buffer of memory
	std::cout << string << std::endl;
	std::cout << second << std::endl;


	PrintString(string);
	PrintString(second);
	PrintStringByRef(string);
	PrintStringByRef(second);
	//we want the second string to have its own block
	//of memory using a deepcopy and not a shallow copy
	//copies object entirely using a copy constructor
	//a copy constructor is a constructor that gets
	//called when you copy the object
	//
	//always pass your objects by const reference
	//to prevent copying and taking a performance hit
}