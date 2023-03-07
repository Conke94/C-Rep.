#include "Department.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Department::Department(){

}
Department::Department(string name, University* uni){
    depName=name;
    uniBelonged=uni;
}
Department::~Department(){

}

/*SETTERS & GETTERS*/
University* Department::getUniBelonged(){
    return uniBelonged;
}
string Department::getDepName(){
    return depName;
}
List<Subject*> Department::getListSubjects (){
    return listSubjects;
}
void Department::setName(string name){
    depName=name;
}
void Department::setUniBelonged(University* uniBlg){
    uniBelonged=uniBlg;
}

/*METHODS*/
























