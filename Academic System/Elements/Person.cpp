#include "Person.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Person::Person(){
}
Person::Person(string n, int a, int idF){
    name=n;
    age=a;
    id=idF;
}
Person::Person(int idF){
    id=idF;
}
Person::~Person(){
}

/*SETTERS & GETTERS*/
int Person::getAge(){
    return age;
}
void Person::setAge(int a){
    age=a;
}
void Person::setPersonName(string pName){
    name=pName;
}
string Person::getPersonName(){
    return name;
}
List<Subject*> Person::getAssociatedSubjectsList (){
    return lAssociatedSubjects;
}

/*METHODS*/
void Person::printAllSubjects (){
    List<Subject*>::Element* subAux=nullptr;
    subAux=lAssociatedSubjects.getFirstElement();

    while (subAux!=nullptr){
        cout<<"- "<<subAux->getValue()->getSubName()<<endl;

        subAux=subAux->getNextElement();
    }
}
void Person::associateToSubject (Subject* sub){
    lAssociatedSubjects.includeNewElement(sub);
}









