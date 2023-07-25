#include "University.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
University::University(){
}
University::University(string uniName, int year, string ct){
    universityName = uniName;
    foundation = year;
    city = ct;
}

/*SETTERS & GETTERS*/
void University::setUniversityName (string uniName){
    universityName = uniName;
}
void University::setFoundation (int year){
    foundation = year;
}
void University::setCity (string ct){
    city = ct;
}

string University::getUniversityName(){
    return universityName;
}
int University::getFoundation (){
    return foundation;
}
string University::getCity(){
    return city;
}
List<Department*> University::getOwnedDepartments (){
    return ownedDepartments;
}
string University::getName (){
    return universityName;
}

/*METHODS*/
void University::printInfo(){
    /*Print all the information related to the university*/
    cout<<"-----"<<universityName<<"-----"<<endl;
    cout<<"-Foundation: "<<foundation<<endl;
    cout<<"-City: "<<city<<endl;
    cout<<"Departments owned"<<endl;
    List<Department*>::Element* elAux = ownedDepartments.getFirstElement();
    while (elAux!=NULL){
        cout<<"- "<<elAux->getValue()->getDptName()<<endl;
        elAux = elAux->getNextElement();
    }
    cout<<endl;
}

void University::includeDepartments (Department* dpt){
    ownedDepartments.includeElement(dpt);
}




