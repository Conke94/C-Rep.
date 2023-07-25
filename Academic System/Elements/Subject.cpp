#include "Department.hpp"
#include "Subject.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Subject::Subject(string name, Department* dptBel, int idSub){
    subName = name;
    dptBelonged = dptBel;
    id = idSub;
}
Subject::~Subject(){}

/*SETTERS & GETTERS*/
string Subject::getName (){
    return subName;
}
void Subject::setName (string name){
    subName = name;
}
Department* Subject::getDptBelonged (){
    return dptBelonged;
}
int Subject::getId(){
    return id;
}

/*METHODS*/
void Subject::printInfo(){
    cout<<"-----"<<subName<<"-----"<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Belonged to:"<<dptBelonged->getDptName()<<endl;
    cout<<endl;
}