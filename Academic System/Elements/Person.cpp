#include "Person.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Person::Person(string perName, int perAge){
    name = perName;
    age = perAge;
}
Person::Person(){}
Person::~Person(){}

/*SETTERS & GETTERS*/
string Person::getName(){
    return name;
}
int Person::getAge (){
    return age;
}

