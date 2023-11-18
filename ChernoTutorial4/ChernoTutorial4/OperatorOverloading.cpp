#include<iostream>
#include<string>
//Giving a new meaning to, or adding new parameters to an operator
//This is a useful feature that gives us full control, but that can
//be a bad thing as well as good
//Instead of giving a function a name, such as add(), you can use +
//operator overload should be minimal and makes sense




struct Vector2 {
	float x, y;
	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	//To overload an operator, you write the operator keyword
	//then write the operator you want to overload
	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}

	//You can write it a different way by using the
	//this keyword and dereference it to get
	//the current Vector2 object
	Vector2 Multiply(const Vector2& other) const
	{
		//return operator*(other);
		return (*this) * other;
	}
	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	//You can also overload the == and != operator which is useful
	bool operator==(const Vector2& other) const
	{
		return x==other.x && y==other.y;
	}
	bool operator!=(const Vector2& other) const
	{
		return x != other.x || y != other.y;
		//alternative ways of writing it:
		//return (*this == other);
		//return !operator==(other);	
	}


};

//Overloading the << operator in std::cout
std::ostream& operator<<(std::ostream& stream,const Vector2& other) {
	stream << other.x << ", " << other.y;
	return stream;
}

void OperatorOverloading()
{
	
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);
	Vector2 powerup(1.1f, 1.1f);

	//Using methods to add and multiply Vector2 struct objects
	//May look hard to read if done too much
	Vector2 result1 = position.Add(speed.Multiply(powerup));

	//We can make something like this with overloading
	Vector2 result2 = position+speed*powerup;


	//we overloaded the == operator for this to be possible
	if (result1 == result2)
	{
		std::cout << "The struct objects are equal...\n";
	}

	//cout has a leftshift operator and normally
	//you can only use outputstrings
	//The << operator returns a reference to a std::ostream type
	//Our overload function will look something like this
	//std::ostream& operator<<(std::ostream& stream,const Vector2& other)
	std::cout << result2 << std::endl;
}