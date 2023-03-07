#pragma once
#include <string>
using namespace std;
#include "../List.hpp"
#include "Subject.hpp"

class Person{
protected:
    int id;
    string name;
    int age;
    List<Subject*> lAssociatedSubjects;

public:
/*CONSTUCTORS & DESTRUCTORS*/
    Person();
    Person(string n, int a, int idF);
    Person (int idF);
    ~Person();
    
/*SETTERS & GETTERS*/
    int getAge();
    void setAge (int a);
    void setPersonName(string pName);
    string getPersonName();
    List<Subject*> getAssociatedSubjectsList ();
    // void computeAge(); Computaria com base na data de nascimento

/*METHODS*/
    void printAllSubjects ();
    void associateToSubject (Subject* sub);
};
