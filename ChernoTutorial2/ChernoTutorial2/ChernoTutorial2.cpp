#include <iostream>


class Entity 
{
public:
    float X, Y;

    //The constructor of the class is a method
    //that runs when initialized and has the same
    //name as the class. Can have parameters or not.
    //You can overload the constructor to account for
    //the case of no parameters at initialization
    //You can write multiple constructor methods
    //with different parameter situations
    Entity() 
    {
        X = 0.0f;
        Y = 0.0f;
    }
    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Init() 
    {
        X = 0.0f;
        Y = 0.0f;
    }
    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

class Log
{
private:
    //Log() {}
public:
    Log() = delete;
    static void Write() {
        std::cout << "Hi" << std::endl;
    }
};

int maina()
{
    //Random values will be given for X,Y
    //Since it was not set when intialized
    //Entity e;
    //e.Print();

    //Using an Init method will fix the problem
    //But there's a special method that does this already in c++
    //Entity e1;
    //e1.Init();
    //e1.Print();

    Entity e2(10.0f, 5.0f);
    e2.Print();
    Entity e3;
    e3.Print();


    //If you use static methods from a class, constructor won't run
    //If you want a class of only static methods and not allow instances
    //There's two different strategies:
    //Make the constructor private to hide it private: Log(){}
    //Set the constructor equal to delete  Log()=delete;
    //This will get rid of the default constructor
    Log::Write();
    //Log l;   <-- Not allowed to run


    //There are also other type of constructors such as the copy and move constructor
    //But that will get covered later on

    std::cin.get();
    return 0;
}
