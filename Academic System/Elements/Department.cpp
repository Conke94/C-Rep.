#include "Department.hpp"
#include "University.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Department::Department(){}
Department::Department(string name, University* uni){
    dptName = name;
    uniBelonged = uni;
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

/*METHODS*/
void Department::printInfo(){
    /*Print all the information related to the department*/
    cout<<"-----"<<dptName<<"-----"<<endl;
    cout<<"Belonged to:"<<uniBelonged->getUniversityName()<<endl;
    cout<<"Subjects owned:"<<endl;
    List<Subject*>::Element* elAux = ownedSubjects.getFirstElement();
    while (elAux!=NULL){
        cout<<"- "<<elAux->getValue()->getName()<<endl;
        elAux = elAux->getNextElement();
    }

    cout<<endl;
}
void Department::includeSubject(Subject* sub){
    ownedSubjects.includeElement(sub);
}


