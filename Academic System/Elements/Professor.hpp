#pragma once
#include "Person.hpp"
#include "Department.hpp"
#include "Subject.hpp"

class Professor: public Person{
private:
    Department* dptBelonged;

public:
/*CONSTRUCTOS & DESTRUCTORS*/
    Professor();
    Professor(string n, int a);
    ~Professor();

/*SETTERS & GETTERS*/
    void setDptBelonged (Department* dpt);
    Department* getDptBelonged ();

/*METHODS*/
};