#include<iostream>
#include<string>
#include<vector>
//Standard template library
//you can template it into anything
//you provide the underlying datatype the datastructure will handle
//c++ offers a class called vector in the std
//it's an array, that can be resized and doesn't have a set size
//companies usually make their on container library instead of the standard template library

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x<<", " << vertex.y << ", " << vertex.z;
	return stream;
}

//pass by const reference when possible
//to avoid copying an entire array into the function
void Function(const std::vector<Vertex>& vector)
{

}

void DynamicArray()
{
	//static array
	//can't go past index 4
	//you could allocate a larger amount but
	//is wasteful with memory
	Vertex* verticesStatic=new Vertex[5];

	//defines a vector with type of Vertex
	std::vector<Vertex> vertices;

	//There's a huge difference between using Vertex
	//and a bunch of Vertex pointers Vertex* in a vector
	//it is technically more optimal to store with Vertex objects
	//instead of pointers due to memory being inline.
	//dynamic arrays have contiguous memory, and storing inline
	//helps make iterating over them faster.
	//if you resize the vector with inline objects, it could be a costly operation
	//in comparison to a vector of pointers but you can use
	//moving instead of copying to handle this particular issue
	//but there is still some copying with isn't ideal

	//define a Vertex with 3 inputs
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });

	//to iterate over a vector, use vertices.size()
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i]<<std::endl;

	//range based forloops in c++
	//in this instance we are copying each vertex
	//into the forloop which isn't good
	for(Vertex v:vertices)
		std::cout << v << std::endl;

	//use the ampersand to prevent copying
	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	//to remove vertices individually in a vector
	//use the .erase() method
	//we can't just use an index
	//we could use .begin() to get the first element
	//then add to it to find the correct postion
	vertices.erase(vertices.begin()+1);

	//to clear the list of vertices in a vector
	//use .clear() method
	vertices.clear();

}