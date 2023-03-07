#include "Student.hpp"

/*CONTRUCTORS & DESTRUCTORS*/
Student::Student(): Person(1){
    uniBelonged=nullptr;
}
Student::Student(string n, int a):Person(n, a, 1){
    uniBelonged=nullptr;
}
Student::~Student(){
}

/*SETTERS & GETTERS*/
void Student::setUniversityBelonged (University* uni){
    uniBelonged=uni;
}
University* Student::getUniversityBelonged (){
    return uniBelonged;
}

/*METHODS*/
















