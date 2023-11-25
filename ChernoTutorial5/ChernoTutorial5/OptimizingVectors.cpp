#include<iostream>
#include<vector>


//you create a vector and push_back() elements
//vector will allocate memory to handle the new element you want to add
//it causes slow code
//
//we want to avoid copying objects in vectors
//so we need to know when copying happens

struct VertexOptimized
{
	float x, y, z;
	VertexOptimized(float x, float y, float z)
		:x(x), y(y), z(z)
	{}

	//Made a copy constructor to see
	//when copying happens
	VertexOptimized(const VertexOptimized& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!\n";
	}
};


void OptimizingVectors()
{
	std::vector<VertexOptimized> vertices;
	//optimization strategy, reserve space for n vector to avoid resizing
	//using the .reserve() method
	vertices.reserve(3);

	//to initalize the Vertex in the vector instead of the
	//main function, we use the .emplace_back() method instead of push_back()

	//vertices.push_back(VertexOptimized(1,2,3));
	//	copied once at push_back, created object in main function
	//	then pushed it into vector by copying from the main function into the vector
	//vertices.push_back(VertexOptimized(4,5,6));
	//vertices.push_back(VertexOptimized( 7,8,9 ));
	//	at this point, we have see 6 copies performed
	//	after using .reserve() it goes to 3 copies

	//Using .emplace_back() instead of .push_back() along with .reserve() causes
	//the copy constructor to be called 0 times!
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);
}