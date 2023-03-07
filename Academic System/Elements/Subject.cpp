#include "Subject.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Subject::Subject(){

}
Subject::Subject(string n){
    subName=n;
}
Subject::~Subject(){
}

/*SETTERS & GETTERS*/
void Subject::setDepartmentBelonged (Department* dpt){
    dptBelonged=dpt;
}
Department* Subject::getDepartmentBelonged (){
    return dptBelonged;
}
void Subject::setSubName (string name){
    subName=name;
}
string Subject::getSubName(){
    return subName;
}

/*METHODS*/

















