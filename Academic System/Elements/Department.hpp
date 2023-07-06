#pragma once
#include <string>
#include <iostream>
using namespace std;

class University;

class Department{
    private:
        string dptName;
        University* uniBelonged;
        int id;

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
        int getId ();

    /*METHODS*/
        void printInfo();

};