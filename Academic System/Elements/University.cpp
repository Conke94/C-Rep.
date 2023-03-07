#include "University.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
University::University (){
}
University::University (string n, int year, string city){
    uniName=n;
    foundation=year;
    uniCity=city;
}
University::~University(){
}

/*SETTERS & GETTERS*/
string University::getUniName (){
    return uniName;
}
List<Department*> University::getListDepartments (){
    return listDepartments;
}

/*METHODS*/
void University::setUniName (string name){
    uniName=name;
}
void University::setUniFoundation (int foun){
    foundation=foun;
}
void University::setUniCity(string city){
    uniCity=city;
}
void University::addDepartment(Department* dpt){
    listDepartments.includeNewElement(dpt);
}
string University::getUniCity(){
    return uniCity;
}
int University::getUniFoundation(){
    return foundation;
}











