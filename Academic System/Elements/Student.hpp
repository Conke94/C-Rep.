#pragma once
#include "Person.hpp"
#include "University.hpp"
#include "Subject.hpp"

class Student: public Person{
private:
    University* uniBelonged;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Student();
    Student(string n, int a);
    ~Student();

/*SETTERS & GETTERS*/
    void setUniversityBelonged (University* uni);
    University* getUniversityBelonged ();

/*METHODS*/
};