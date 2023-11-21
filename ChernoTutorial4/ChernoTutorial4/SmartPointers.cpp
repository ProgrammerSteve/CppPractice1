#include<iostream>
#include<memory>

//What they are???
// 
//new allocate memory on the heap
//delete gets rid of that allocated memory
//
//smart pointing is a way to automate that
//c++ programmers have a programming style
//where they never use new or delete
//which is done using smart pointers
//
//The reason they're called unique pointers
//is because they have to be unique and you
//can't copy a unique pointer, because
//if you copy a unique pointer, the memory it's
//pointing to will mean you will have 2 pointers
// pointing to the same block of memory
//when one of them dies, it frees up the memory
//then the second unique pointer is pointing to
//freed up memory. So you cannot copy unique pointers
//
//To get access to the smart pointers, you need to include
//memory using #include<memory>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!\n";
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!\n";
	}
	void Print() {
		std::cout << "Print invoked...\n";
	}
};

void SmartPointerFunction()
{
	{
		//call unique_ptr
		//takes in a template input of the class object
		std::unique_ptr<Entity> entity(new Entity());

		//can't be initialized like this:
		//std::unique_ptr<Entity> entity=new Entity();
		//this is because it's labeled explicit and
		//constructor can't be called implicitly

		//methods can be accessed with the arrow operator
		entity->Print();

		//The preferred way to initialize a unique pointer
		//this is due to exception safety which will be covered later
		//if the constructor happens to throw an exception, you won't have
		//a dangling pointer with no reference, thus a memory leak
		std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();

		//That's the simplest smart pointer there is, and doesn't have much
		//overhead. The problem with this is that if you want to copy the
		//pointer, or share it, pass it into a function, or have another class store it,
		//you'll run into an error
		// 
		//The copy operator has been overloaded to be delete
		//so you can't assign on unique pointer to another
		//std::unique_ptr<Entity> e0 = entity;
		//
		//If you want to share, you need to use a shared pointer
		//uses something called reference counting under the hood
		//you keep track of how many reference you have to the pointer
		//when the reference count is zero, it gets deleted
		//
		//Uses a template input of the class
		//only difference is that we use 
		// shared_ptr instead of unique_ptr and
		// make_shared instead of make_unique
		std::shared_ptr<Entity>sharedEntity = std::make_shared<Entity>();

		//this way works, but you don't want to do that with shared pointers
		//not only for exception safety, but because it needs to allocated another
		//block of memory called the control block, where it stores that reference count
		//if you create a new Entity and pass it into a sharedEntity constructor,
		//it has to do two allocations. make_shared constructs them together and is
		//more optimized
		std::shared_ptr<Entity>sharedEntity2(new Entity());

		//With shared pointers, you can copy the pointer as such
		std::shared_ptr<Entity>e0 = sharedEntity;
	}

	//example with multiple scopes
	{
		std::shared_ptr<Entity>e0;
		{
			std::shared_ptr<Entity>sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;
		} 
		//sharedEntity dies when first scope ends, e0 still lives and isn't deleted
		//because the reference count isn't zero with e0
	}//Now the sharedEntity dies because e0 dies at the second scope


	//Weak pointers    std::weak_ptr<>
	//copies the entity like a shared pointer
	//but doesn't increase the reference count
	//great if you don't want to take ownership of the entity
	//can be used to reference something, check to see if it expired
	//but won't keep it alive
	{
		std::weak_ptr<Entity>e0;
		{
			std::shared_ptr<Entity>sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;
		}//sharedEntity is deleted since scope ends and ref count goes from 1 to 0
	}
}

//You should use them all the time, shared pointers have a bit of overhead
//since you need to keep track of the reference count
//
//use unique pointer when possible due to low overhead
//shared pointer if you can't use unique pointers