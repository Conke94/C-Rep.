#include "Controler.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Controler::Controler(){
    welcome();
}
Controler::~Controler(){

}

/*SETTERS & GETTERS*/

/*METHODS*/
void Controler::welcome(){
    cout<<"Welcome! Choose your option:"<<endl;
    cout<<"1- Add"<<endl;
    cout<<"2- List"<<endl;
    cout<<"3- Save"<<endl;
    cout<<"4- Recover"<<endl;

    int op;
    cin>>op;
    system("cls");

    switch (op){
        case 1:{
            addElements ();
        }break;
        case 2:{
            listElements ();
        }break;
        case 3:{
            saveElements();
        }
        default:{
            cout<<"This option doesn't exists"<<endl;
        }break;
    }
}
void Controler::addElements(){
    cout<<"Choose what do you want:"<<endl;
    cout<<"1- Add university"<<endl;
    cout<<"2- Add department"<<endl;
    cout<<"3- Add subject"<<endl;
    cout<<"4- Add professor"<<endl;
    cout<<"5- Add student"<<endl;

    int op;
    cin>>op;
    system("cls");

    switch (op){
        case 1:{
            addUniversity ();
        }break;
        case 2:{
            addDepartment();
        }break;
        case 3:{
            addSubject();
        }break;
        case 4:{
            addProfessor();
        }break;
        case 5:{
            addStudent();
        }break;
        default:{
            cout<<"This option doesn't exists"<<endl;
        }break;
    }
}
void Controler::listElements(){
    cout<<"Choose what do you want:"<<endl;
    cout<<"1- List universities"<<endl;
    cout<<"2- List departments"<<endl;
    cout<<"3- List subjects"<<endl;
    cout<<"4- List professors"<<endl;
    cout<<"5- List students"<<endl;

    int op;
    cin>>op;
    system("cls");

    switch (op){
        case 1:{
            listUniversities ();
        }break;
        case 2:{
            listDepartments();
        }break;
        case 3:{
            listSubjects();
        }break;
        case 4:{
            listProfessors();
        }break;
        case 5:{
            listStudents();
        }break;
        default:{
            cout<<"This option doesn't exeists"<<endl;
        }break;
    }
}
void Controler::addUniversity(){
    University* uniNew = new University();
    string aux;
    int numAux;

    cout<<"Insert the university name:";
    cin.ignore();
    getline(cin, aux);
    uniNew->setUniName(aux);

    cout<<"Insert the year of foundation:";
    cin>>numAux;
    uniNew->setUniFoundation(numAux);

    cout<<"Insert the university city:";
    cin.ignore();
    getline(cin, aux);
    uniNew->setUniCity(aux);

    lUniversityMain.includeNewElement(uniNew);
    system("cls");
    welcome();
}
void Controler::addDepartment(){
    Department* newDpt=nullptr;
    newDpt=new Department();

    string aux;

    cout<<"Insert the department name:";
    cin.ignore();
    getline(cin, aux);
    newDpt->setName(aux);

    cout<<"Insert the university belonged:";
    getline(cin, aux);
    newDpt->setUniBelonged(findUniversity(aux));
    
    findUniversity(aux)->addDepartment(newDpt);

    lDepartmentMain.includeNewElement(newDpt);
    cout<<"Departament sucessfully registered"<<endl;
    system("pause");
    system("cls");
    welcome();
}
void Controler::addSubject(){
    string aux;
    Subject* newSub=nullptr;
    newSub= new Subject();

    cout<<"Insert the subject name:";
    cin.ignore();
    getline(cin, aux);
    newSub->setSubName(aux);

    Department* dptBlg=nullptr;
    cout<<"Insert the department belonged:";
    getline(cin, aux);
    dptBlg=findDepartment(aux);
    newSub->setDepartmentBelonged(dptBlg);
    dptBlg->getListSubjects().includeNewElement(newSub);

    lSubjectMain.includeNewElement(newSub);
    cout<<"Subject sucessfully registered"<<endl;
    system("pause");
    system("cls");
    welcome();
}
void Controler::addProfessor(){
    string aux;
    Professor* newProf=nullptr;
    newProf=new Professor();

    cout<<"Insert professor's name:";
    cin.ignore();
    getline(cin, aux);
    newProf->setPersonName(aux);

    cout<<"Insert the department belonged:";
    getline(cin, aux);
    newProf->setDptBelonged(findDepartment(aux));

    cout<<"This professor teaches any subject?"<<endl;
    cout<<"1- Yes"<<endl;
    cout<<"2- No"<<endl;

    int op;
    cin>>op;

    system("cls");
    
    switch(op){
        case 1: {
            associateProfessorToSubject(newProf);
        } break;
    }

    lProfessorMain.includeNewElement(newProf);
    cout<<"Professor sucessfully registered"<<endl;
    system("pause");
    system("cls");
    welcome();
}
void Controler::addStudent(){
    string aux;

    Student* newStu=nullptr;
    newStu=new Student();
    
    cout<<"Insert student's name:";
    cin.ignore();
    getline(cin, aux);
    newStu->setPersonName(aux);

    cout<<"Enter the student's University:";
    getline(cin, aux);
    newStu->setUniversityBelonged(findUniversity(aux));

    int op;
    cout<<"Does the student attend a class?"<<endl;
    cout<<"1- Yes"<<endl;
    cout<<"2- No"<<endl;

    cin>>op;
    system("cls");

    switch(op){
        case 1:{
            associateSubjectsToStudent(newStu);
        }
    }

    lStudentMain.includeNewElement(newStu);
    cout<<"Student sucessfully registered"<<endl;
    system("pause");
    system("cls");
    welcome();

}
void Controler::listUniversities(){
    List<University*>::Element* aux=nullptr;
    aux=lUniversityMain.getFirstElement();

    while (aux!=NULL){
        cout<<"- "<<aux->getValue()->getUniName()<<" from "<<aux->getValue()->getUniCity()<<" and founded in "<<aux->getValue()->getUniFoundation()<<endl;
        aux=aux->getNextElement();
    }
    system("pause");
    system("cls");
    welcome();
}
void Controler::listDepartments(){
    List<Department*>::Element* aux= nullptr;
    aux= lDepartmentMain.getFirstElement();

    while (aux!=nullptr){
        cout<<aux->getValue()->getDepName()<<" belonged to "<<aux->getValue()->getUniBelonged()->getUniName()<<endl;
        aux=aux->getNextElement();
    }

    system("pause");
    system("cls");
    welcome();
}
void Controler::listSubjects(){
    List<Subject*>::Element* aux= nullptr;
    aux= lSubjectMain.getFirstElement();

    while (aux!=nullptr){
        cout<<aux->getValue()->getSubName()<<" belonged to "<<aux->getValue()->getDepartmentBelonged()->getDepName()<<endl;
        aux=aux->getNextElement();
    }

    system("pause");
    system("cls");
    welcome();
}
void Controler::listProfessors(){
    List<Professor*>::Element* elProf=nullptr;
    elProf=lProfessorMain.getFirstElement();

    while (elProf!=nullptr){
        cout<<elProf->getValue()->getPersonName()<<" is from "<<elProf->getValue()->getDptBelonged()->getDepName()<<" and theaches:"<<endl;
        elProf->getValue()->printAllSubjects();
        
        elProf=elProf->getNextElement();
        cout<<endl;
    }

    system("pause");
    system("cls");
    welcome();
}
void Controler::listStudents(){
    List<Student*>::Element* elStu=nullptr;
    elStu=lStudentMain.getFirstElement();

    while (elStu!=NULL){
        cout<<elStu->getValue()->getPersonName()<<" is from "<<elStu->getValue()->getUniversityBelonged()->getUniName()<<" and studies:"<<endl;
        elStu->getValue()->printAllSubjects();
        
        elStu=elStu->getNextElement();
        cout<<endl;
    }

    system("pause");
    system("cls");
    welcome();
}
University* Controler::findUniversity(string name){
    List<University*>::Element* pUniEl=nullptr;
    pUniEl=lUniversityMain.getFirstElement();

    while (pUniEl!=nullptr){
        if (pUniEl->getValue()->getUniName()==name)
            return pUniEl->getValue();
        else
            pUniEl=pUniEl->getNextElement();
    }

    cout<<"This university doesn't exist"<<endl;
    system("pause");
    exit(0);
}
Department* Controler::findDepartment(string name){
    List<Department*>::Element* pDptEl=nullptr;
    pDptEl=lDepartmentMain.getFirstElement();

    while (pDptEl!=nullptr){
        if (pDptEl->getValue()->getDepName()==name)
            return pDptEl->getValue();
        else
            pDptEl=pDptEl->getNextElement();
    }

    cout<<"This department doesn't exist"<<endl;
    system("pause");
    exit(0);
}
Subject* Controler::findSubject (string name){
    List<Subject*>::Element* pSubEl=nullptr;
    pSubEl=lSubjectMain.getFirstElement();

    while (pSubEl!=nullptr){
        if (pSubEl->getValue()->getSubName()==name)
            return pSubEl->getValue();
        else
            pSubEl=pSubEl->getNextElement();
    }

    cout<<"This subject doesn't exist"<<endl;
    system("pause");
    exit(0);
}
void Controler::associateProfessorToSubject(Professor* prof){
    string aux;
    system("cls");

    cout<<"Insert the subject name:";
    cin.ignore();
    getline(cin, aux);

    prof->associateToSubject(findSubject(aux));

    cout<<"Do you want to associate more subjects?"<<endl;
    cout<<"1- Yes"<<endl;
    cout<<"2- No"<<endl;

    int op;
    cin>>op;

    if (op==1){
        associateProfessorToSubject(prof);
    }

}
void Controler::associateSubjectsToStudent(Student* stu){
    string aux;
    system("cls");
    
    cout<<"Insert subject's name:";
    cin.ignore();
    getline(cin, aux);

    stu->associateToSubject(findSubject(aux));

    int op;
    cout<<"Do you have more subjects to add?"<<endl;
    cout<<"1- Yes"<<endl;
    cout<<"2- No"<<endl;
    cin>>op;
    switch(op){
        case 1:{
            associateSubjectsToStudent(stu);
        }
    }


}

void Controler::saveElements(){
    system("cls");

    cout<<"0- Save all"<<endl;
    cout<<"1- Save Universities"<<endl;
    cout<<"2- Save Departments"<<endl;
    cout<<"3- Save Subjects"<<endl;
    cout<<"4- Save Professors"<<endl;
    cout<<"5- Save Students"<<endl;

    int op;
    cin>>op;

    switch(op){
        case 0:{
            saveAll();
        }break;
        case 1:{
            saveUniversities();
        }break;
        case 2:{
            saveDepartments();
        }break;
        case 3:{
            saveSubjects();
        }break;
        case 4:{
            saveProfessors();
        }break;
        case 5:{
            saveStudents();
        }break;
        default:{
            cout<<"This option doesn't exists"<<endl;
        }break;
    }
}
void Controler::saveUniversities(){
    ofstream saver("Universities.dat", ios::out);

    if (!saver){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    List<University*>::Element* elUni=nullptr;
    elUni=lUniversityMain.getFirstElement();

    while (elUni!=NULL){
        saver<<elUni->getValue()->getUniName()<<' '
             <<elUni->getValue()->getUniFoundation()<<' '
             <<elUni->getValue()->getUniCity()<<' ';
             
        List<Department*>::Element* dptAux=nullptr;
        dptAux=elUni->getValue()->getListDepartments().getFirstElement();
        
        elUni=elUni->getNextElement();
    }

    saver.close();
    
    system("cls");
    cout<<"Universities sucessfully saved"<<endl;
    system("pause");
    system("cls");
    welcome();
}

void Controler::saveDepartments(){}
void Controler::saveSubjects(){}
void Controler::saveProfessors(){}
void Controler::saveStudents(){}
void Controler::saveAll (){}





























