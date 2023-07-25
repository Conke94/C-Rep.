#pragma once
#include <string>
using namespace std;
#include "University.hpp"

#define STUDENT 0
#define PROFESSOR 1

class Person{
    protected:
        string name;
        int age;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        Person(string perName, int perAge);
        Person();
        ~Person();

    /*SETTERS & GETTERS*/
        string getName();
        int getAge ();
};