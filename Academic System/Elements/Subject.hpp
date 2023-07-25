#pragma once
#include <string>
using namespace std;

class Department;

class Subject{
    private:
        int id;
        string subName;
        Department* dptBelonged;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        Subject(string name, Department* , int subId);
        ~Subject();

    /*SETTERS & GETTERS*/
        string getName ();
        void setName (string name);
        Department* getDptBelonged ();
        int getId ();

    /*METHODS*/
        void printInfo();
};