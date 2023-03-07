#pragma once
#include <string>
#include "../List.hpp"
using namespace std;

class Department;

class University{
private:
    string uniName;
    int foundation;
    string uniCity;
    List<Department*> listDepartments;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    University ();
    University (string n, int year, string city);
    ~University();

/*SETTERS & GETTERS*/
    string getUniName ();
    List<Department*> getListDepartments ();
    void setUniName (string name);
    void setUniFoundation (int foun);
    void setUniCity(string city);
    void addDepartment(Department* dpt);
    string getUniCity();
    int getUniFoundation();
/*METHODS*/
};