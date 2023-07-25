#include "Student.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Student::Student(string perName, int perAge, University* currentUni):
Person(perName, perAge){
    currentUniversity = currentUni;
}
Student::~Student(){}

/*SETTERS & GETTERS*/
University* Student::getCurrentUniversity(){
    return currentUniversity;
}
vector<int> Student::getStudyingSubjects (){
    return studyingSubjects;
}

/*METHODS*/
void Student::printInfo(){
    cout<<"-----"<<name<<"-----"<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"University: "<<currentUniversity->getName()<<endl;
    cout<<"Studying subjects id:"<<endl;

    for (int i=0; i<studyingSubjects.size(); i++)
        cout<<studyingSubjects[i]<<endl;

    cout<<endl;
}
void Student::includeSubject (Subject* sub){
    studyingSubjects.push_back(sub->getId());
}