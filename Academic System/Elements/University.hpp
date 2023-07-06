#pragma once
#include <string>
#include <iostream>
#include "../Lists/List.hpp"
#include "Department.hpp"
using namespace std;

class University{
    private:
        string universityName;
        int foundation;
        string city;
        List<Department*> ownedDepartments;

        int id;
        
    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        University();
        University(string uniName, int year, string ct);
        ~University(){}

    /*SETTERS & GETTERS*/
        void setUniversityName (string uniName);
        void setFoundation (int year);
        void setCity (string ct);
        string getUniversityName();
        int getFoundation ();
        string getCity();
        List<Department*> getOwnedDepartements ();
        int getId ();

    /*METHODS*/
        void printInfo ();
        void includeDepartments (Department* dpt);
};