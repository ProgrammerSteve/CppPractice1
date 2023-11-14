// ChernoTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Log.h"


class Log {
public:
    enum Level {
        LevelError=0,LevelWarning=1,LevelInfo=2
    };

    //const int LogLevelError = 0;
    //const int LogLevelWarning = 1;
    //const int LogLevelInfo = 2;
private:
    Level m_LogLevel = LevelInfo;
    //int m_LogLevel=LogLevelInfo;
public:
    //void SetLevel(int level)
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }
    void Error(const char* message)
    {
        //if (m_LogLevel >= LogLevelError)
        if (m_LogLevel >= LevelError)
        std::cout << "[ERROR]: " << message << std::endl;
    }
    void Warn(const char* message)
    {
        //if (m_LogLevel >= LogLevelWarning)
        if (m_LogLevel >= LevelWarning)
        std::cout<<"[WARNING]: " << message << std::endl;
    }
    void Info(const char* message)
    {
        //if (m_LogLevel >= LogLevelInfo)
        if (m_LogLevel >= LevelInfo)
        std::cout << "[INFO]: " << message << std::endl;
    }
};

int main()
{
    Log log;
    //log.SetLevel(log.LogLevelWarning);
    log.SetLevel(Log::LevelWarning);
    log.Warn("Hello");
    log.Error("Hello");
    log.Info("Hello");
    std::cin.get();
    return 0;
}


class Player
{
public:
    int x, y;
    int speed;
    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};
void Move(Player& player, int xa, int ya)
{
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}
struct Vec2
{
    float x, y;
    void Add(const Vec2& other)
    {
        x += other.x;
        y += other.y;
    }
};
int mainClassTutorial()
{

    Player player;
    player.x = 5;
    player.y = 0;
    player.speed = 1;
    std::cout <<"player.x: "<< player.x << std::endl;
    std::cout << "player.y: " << player.y << std::endl;
    Move(player, 1, -1);
    std::cout << "player.x: " << player.x << std::endl;
    std::cout << "player.y: " << player.y << std::endl;
    player.Move(-1, 1);
    std::cout << "player.x: " << player.x << std::endl;
    std::cout << "player.y: " << player.y << std::endl;
    std::cin.get();
    return 0;
}
void Increment(int* value)
{
    //We need to dereference the value before incrementing
    //If you don't dereference, the memory address gets incr
    //due to order of operations, we need to use parentheses
    (*value)++;
}
void IncrementRef(int& value)
{
    //Since the variable is being passed by reference
    //we can access the variable directly and change its value
    value++;
}
int mainPtrsAndRefs()
{
    Log1("test");
    
    char* buffer = new char[8];
    //a pointer to a pointer
    char** ptr = &buffer;

    //Accesses heap memory so memory needs to be allocated
    memset(buffer, 0, 8);

    //Once finished, we need to delete the memory from the heap
    delete[] buffer;

    int var = 8;
    std::cout << var << std::endl;
    //Create a pointer for var's memory using the & ref operator
    int* varPointer = &var;

    //Dereference a pointer with * asterisk before the pointer variable and set it's value
    *varPointer = 10;

    //The variable's value is now changed to 10 via pointer
    std::cout << var << std::endl;


    std::cout << std::endl << std::endl;

    //REFERENCES
    int a = 5;
    std::cout << "a: " << a << std::endl;

    //int& is used to signify a ref to an int
    //Note that the ampersand is part of the type and not an operator
    //You set it to an exisiting variable and creates an alias to the variable
    //The reference variable doesn't exist and if you compile the code, it doesn't show up
    int& ref = a;

    //This is the same as writing a=2;
    ref = 2;
    std::cout <<"a: "<< a << std::endl;

    Log1("using pointer to increment...");
    //Incrementing with a ptr
    Increment(&a);
    std::cout << "a: " << a << std::endl;


    Log1("using reference to increment...");
    //Incrementing with a ref
    IncrementRef(a);
    std::cout << "a: " << a << std::endl;

    //Once you declare a reference, you cannot change what it references
    //if you declare a reference, it needs to be defined immediately
    // Example of an error int& var;
    std::cin.get();
    return 0;
}
