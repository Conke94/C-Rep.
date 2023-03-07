#pragma once
#include "University.hpp"
#include <string>
using namespace std;

class Subject;

class Department{
private:
    string depName;
    University* uniBelonged;
    List<Subject*> listSubjects;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Department();
    Department(string name, University* uni);
    ~Department();

/*SETTERS & GETTERS*/
    University* getUniBelonged();
    string getDepName ();
    List<Subject*> getListSubjects ();
    void setName(string name);
    void setUniBelonged(University* uniBlg);

/*METHODS*/
};