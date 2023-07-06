#include "Department.hpp"
#include "University.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Department::Department(){}
Department::Department(string name, University* uni){
    dptName = name;
    uniBelonged = uni;
    id = 2;
}

    /*SETTERS & GETTERS*/
void Department::setDptName (string name){
    dptName = name;
}
void Department::setUniBelonged (University* uni){
    uniBelonged=uni;
}
string Department::getDptName (){
    return (dptName);
}
University* Department::getUniBelonged(){
    return uniBelonged;
}
int Department::getId (){
    return id;
}

    /*METHODS*/
void Department::printInfo(){
    /*Print all the information related to the department*/
    cout<<"-----"<<dptName<<"-----"<<endl;
    cout<<"Belonged to:"<<uniBelonged->getUniversityName()<<endl;
    cout<<endl;
}