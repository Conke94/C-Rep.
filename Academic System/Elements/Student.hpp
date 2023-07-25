#pragma once 
#include "../Lists/List.hpp"
#include <vector>
#include "Subject.hpp"
#include <string>
#include <iostream>
#include "Person.hpp"
using namespace std;

#define STUDENT 0
#define PROFESSOR 1

class Student: public Person{
    private:
        University* currentUniversity;
        vector<int> studyingSubjects;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        Student(string perName, int perAge, University* currentUni);
        ~Student();

    /*SETTERS & GETTERS*/
        University* getCurrentUniversity();
        vector<int> getStudyingSubjects ();

    /*METHODS*/
        void printInfo ();
        void includeSubject (Subject* sub);
};