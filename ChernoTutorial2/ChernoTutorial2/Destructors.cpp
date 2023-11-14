//Destructors runs when an object is destroyed
//This where you uninitialized anythin you may have to
//or clean any memory you've used

//Applies to both stack and heap allocated objects
//So if you allocate an object using new, when you call delete
//The destructor will be called.


#include <iostream>
static class Entity3
{
public:
    float X, Y;
    Entity3()
    {
        std::cout << "Created Entity!" << std::endl;
        X = 0.0f;
        Y = 0.0f;
    }

    //The destructor is defined with the tilde ~
    //and the name of the class
    ~Entity3()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

void Function()
{
    //Since this object was saved on the stack
    //When it goes out of the scope, it
    //automatically gets destroyed which
    //calls the destructor method
    Entity3 e;
    e.Print();

    //Although rare, you can manually call the destructor as such
    //e.~Entity3();
}

int main3()
{
    Function();
    std::cin.get();
    return 0;
}