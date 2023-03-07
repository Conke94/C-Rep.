#pragma once
#include <string>
using namespace std;

class Department;

class Subject{
private:
    string subName;
    Department* dptBelonged;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Subject();
    Subject(string n);
    ~Subject();

/*SETTERS & GETTERS*/
    void setDepartmentBelonged (Department* dpt);
    Department* getDepartmentBelonged ();
    void setSubName (string name);
    string getSubName();

/*METHODS*/
};