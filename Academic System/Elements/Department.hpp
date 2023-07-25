#pragma once
#include <string>
#include "Subject.hpp"
#include "../Lists/List.hpp"
#include <iostream>
using namespace std;

class University;

class Department{
    private:
        string dptName;
        University* uniBelonged;
        List<Subject*> ownedSubjects;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        Department();
        Department(string name, University* uni);
        ~Department(){}

    /*SETTERS & GETTERS*/
        void setDptName (string name);
        void setUniBelonged (University* uni);
        string getDptName ();
        University* getUniBelonged();

    /*METHODS*/
        void printInfo();
        void includeSubject (Subject* sub);
};