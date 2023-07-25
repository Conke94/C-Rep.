#include "Controler.hpp"

Controler *Controler::manager = NULL;

/*---------------------SINGLETON IMPLEMENTATION----------------------------------*/
Controler::Controler(){
        welcome();
    }
Controler::~Controler(){
    universitiesMainList.clear();
    departmentsMainList.clear();
}
Controler* Controler::getInstance (){
        if (manager==NULL)
            manager = new Controler();
        return manager;
    }
void Controler::deleteInstance(){
        if (manager)
            delete(manager);
    }

/*-----------------------CLASS IMPLEMENTATION---------------------------------*/
void Controler::welcome(){
        cout<<"Welcome to out academic system! Please, select an option:"<<endl;
        cout<<"1-Add University"<<endl;
        cout<<"2-Add Department"<<endl;
        cout<<"3-Add Subject"<<endl;
        cout<<"4-Add Students"<<endl;
        cout<<"5-List Universities"<<endl;
        cout<<"6-List Departments"<<endl;
        cout<<"7-List Subjects"<<endl;
        cout<<"8-List Students"<<endl;
        cout<<"9-Save"<<endl;
        cout<<"10-Recover"<<endl;
        cout<<"11-Close window"<<endl;
        int op;
        cin>>op;
        system("cls");

        switch(op){
            case 1:{
                addUniversity();
            }break;
            case 2:{
                addDepartment();
            }break;
            case 3:{
                addSubject();
            }break;
            case 4:{
                addStudent();
            }break;
            case 5:{
                listUniversities();
            }break;
            case 6:{
                listDepartment();
            }break;
            case 7:{
                listSubject();
            }break;
            case 8:{
                listStudent();
            }break;
            case 9:{
                saveAll();
            }break;
            case 10:{
                recoverAll();
            }break;
            case 11:{
                closeWindow();
            }break;
            default:{
                cout<<"Option not available"<<endl;
                system("pause");
                system("cls");
                welcome();
            }break;
        }
    }
void Controler::closeWindow(){
    /*Close the app*/
        Controler::deleteInstance();
        exit(1);
    }

void Controler::addUniversity(){
        cout<<"Insert university's name:";
        string uniName;
        cin.ignore();
        getline(cin, uniName);

        cout<<"Insert university's foundation year:";
        int year;
        cin>>year;

        cout<<"Insert university's city:";
        string ct;
        cin.ignore();
        getline(cin, ct);

        University* newUni = new University(uniName, year, ct);
        universitiesMainList.includeElement(newUni);
        cout<<"University sucessfully added"<<endl;

        system("pause");
        system("cls");

        welcome();
    }   
void Controler::addDepartment(){
    cout<<"Insert department's name:";
    string dptName;
    cin.ignore();
    getline(cin, dptName);
    
    cout<<"Insert university belonged:";
    string uniName;
    getline(cin, uniName);

    University* uniBelonged = searchUniversity(uniName);
    Department* newDpt = new Department(dptName, uniBelonged);
    departmentsMainList.includeElement(newDpt);
    uniBelonged->includeDepartments(newDpt);

    cout<<"Department successfully inserted"<<endl;
    system("pause");
    system("cls");

    welcome();
}
void Controler::addSubject(){
    cout<<"Insert subject's name:";
    string name;
    cin.ignore();
    getline(cin, name);

    cout<<"Insert department belonged:";
    string dptName;
    getline(cin, dptName);

    Department* dptBel = searchDepartment(dptName);
    Subject* newSub = new Subject(name, dptBel, subjectsMainList.getSize());
    subjectsMainList.includeElement(newSub);
    dptBel->includeSubject(newSub);

    cout<<"Subject successfully inserted"<<endl;
    system("pause");
    system("cls");

    welcome();
}
void Controler::addStudent(){
    cout<<"Insert student's name:";
    string stuName;
    cin.ignore();
    getline(cin, stuName);

    cout<<"Insert student's age:";
    int perAge;
    cin>>perAge;

    cout<<"Insert students's university:";
    string uniName;
    cin.ignore();
    getline(cin, uniName);
    University* uniAux = searchUniversity(uniName);

    Student* newStu = new Student(stuName, perAge, uniAux);
    studentsMainList.includeElement(newStu);
    cout<<"Student sucessfully added"<<endl;

    system("pause");
    system("cls");

    cout <<"Is the student attending any subject?"<<endl;
    cout <<"1- Yes"<<endl;
    cout <<"2- No"<<endl;
    int op;
    cin>>op;
    system("cls");
    
    if (op == 1)
        includeSubjects (newStu);

    system("cls");
    welcome();
}

void Controler::includeSubjects(Student* newStu){
    cout<<"Insert the subject's name:";
    string subName;
    cin.ignore();
    getline(cin, subName);

    Subject* wantedSub = searchSubject(subName);
    newStu -> includeSubject(wantedSub);

    cout<<"Do you want to add more subjects?"<<endl;
    cout<<"1- Yes"<<endl;
    cout<<"2- No"<<endl;
    int op;
    cin>>op;

    if (op == 1){
        system("cls");
        includeSubjects(newStu);
    }   
}

void Controler::listUniversities(){
        List<University*>::Element* it1 = NULL;
        it1 = universitiesMainList.getFirstElement();

        while (it1 != NULL){
            it1->getValue()->printInfo();
            it1 = it1->getNextElement();
        }
        
        system("pause");
        system("cls");
        welcome();
    }
void Controler::listDepartment(){
    List<Department*>::Element* auxEl = departmentsMainList.getFirstElement();
    
    while (auxEl!=NULL){
        auxEl->getValue()->printInfo();
        auxEl = auxEl->getNextElement();
    }
    
    system("pause");
    system("cls");
    welcome();
}
void Controler::listSubject(){
    List<Subject*>::Element* auxEl = subjectsMainList.getFirstElement();
    
    while (auxEl!=NULL){
        auxEl->getValue()->printInfo();
        auxEl = auxEl->getNextElement();
    }
    
    system("pause");
    system("cls");
    welcome();
}
void Controler::listStudent(){
    List<Student*>::Element* auxEl = studentsMainList.getFirstElement();
    
    while (auxEl!=NULL){
        auxEl->getValue()->printInfo();
        auxEl = auxEl->getNextElement();
    }
    
    system("pause");
    system("cls");
    welcome();
}

void Controler::saveAll(){
    ofstream saver ("Data/salvamento.dat", ios::out);
    if(!saver){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush (stdin);
        getchar();
        return;
    }
    int i, size;

    List<Department*>::Element* dptElAux = NULL;
    List<University*>::Element* uniElAux = NULL;
    List<Subject*>::Element* subElAux = NULL;
    List<Student*>::Element* stuElAux = NULL;

    size = universitiesMainList.getSize();
    saver<<size<<endl;
    uniElAux = universitiesMainList.getFirstElement();
    for (i=0; i<size; i++){
        saver<<eliminateSpaces(uniElAux->getValue()->getName())<<endl;
        saver<<uniElAux->getValue()->getFoundation()<<endl;
        saver<<eliminateSpaces(uniElAux->getValue()->getCity())<<endl;
        uniElAux = uniElAux->getNextElement();
    }

    size = departmentsMainList.getSize();
    saver<<size<<endl;
    dptElAux = departmentsMainList.getFirstElement();
    for (i=0; i<size; i++){
        saver<<eliminateSpaces(dptElAux->getValue()->getDptName())<<endl;
        saver<<eliminateSpaces(dptElAux->getValue()->getUniBelonged()->getName())<<endl;    
        dptElAux = dptElAux->getNextElement();
    }

    size = subjectsMainList.getSize();
    saver<<size<<endl;
    subElAux = subjectsMainList.getFirstElement();
    for (i=0; i<size; i++){
        saver<<eliminateSpaces(subElAux->getValue()->getName())<<endl;
        saver<<eliminateSpaces(subElAux->getValue()->getDptBelonged()->getDptName())<<endl;
        subElAux = subElAux->getNextElement();
    }

    size = studentsMainList.getSize();
    saver<<size<<endl;
    stuElAux = studentsMainList.getFirstElement();
    for (i=0; i<size; i++){
        saver<<eliminateSpaces(stuElAux->getValue()->getName())<<endl;
        saver<<stuElAux->getValue()->getAge()<<endl;
        saver<<eliminateSpaces(stuElAux->getValue()->getCurrentUniversity()->getName());
        stuElAux = stuElAux->getNextElement();
    }

    saver.close();

    cout<<"Save completed successfully!!"<<endl;
    system("pause");
    system("cls");
    welcome();
}
void Controler::recoverAll(){
    ifstream recover ("Data/salvamento.dat", ios::in);
    if(!recover){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush (stdin);
        getchar();
        return;
    }
    int i, size, year;
    string str1, str2;

    recover>>size;
    for (i=0; i<size; i++){
        recover>>str1;
        str1 = recoverSpaces(str1);
        recover>>year;
        recover>>str2;
        str2 = recoverSpaces(str2);
        University* newUni = new University (str1, year, str2);
        universitiesMainList.includeElement(newUni);
    }

    recover>>size;
    University* uniBelonged;
    for (i=0; i<size; i++){
        recover>>str1;
        str1 = recoverSpaces (str1);
        recover>>str2;
        str2 = recoverSpaces (str2);
        uniBelonged = searchUniversity(str2);
        Department* newDpt = new Department (str1, uniBelonged);
        newDpt->getUniBelonged()->includeDepartments(newDpt);
        departmentsMainList.includeElement(newDpt);
    }

    recover>>size;
    Department* dptBelonged;
    for (i=0; i<size; i++){
        recover>>str1;
        str1 = recoverSpaces (str1);
        recover>>str2;
        str2 = recoverSpaces (str2);
        dptBelonged = searchDepartment(str2);
        Subject* newSub = new Subject (str1, dptBelonged, subjectsMainList.getSize());
        newSub->getDptBelonged()->includeSubject(newSub);
        subjectsMainList.includeElement(newSub);
    }

    recover.close();
    cout<<"Recovery completed successfully!!"<<endl;
    system("pause");
    system("cls");
    welcome();
}

University* Controler::searchUniversity(string uniName){
    List<University*>::Element* aux= universitiesMainList.getFirstElement();
    while (aux!=NULL){
        if (aux->getValue()->getUniversityName()==uniName)
            return (aux->getValue());
        aux = aux->getNextElement();
    }
    
    cout<<"University not founded"<<endl;
    system("pause");
    system("cls");

    return NULL;
}
Department* Controler::searchDepartment(string dptName){
    List<Department*>::Element* auxEl = departmentsMainList.getFirstElement();

    while (auxEl!=NULL){
        if (auxEl->getValue()->getDptName() == dptName)
            return auxEl->getValue();
        auxEl = auxEl->getNextElement();
    }

    cout<<"Department not founded"<<endl;
    system("pause");
    system("cls");

    return NULL;
}
Subject* Controler::searchSubject (string subName){
    List<Subject*>::Element* auxEl = subjectsMainList.getFirstElement();

    while (auxEl!=NULL){
        if (auxEl->getValue()->getName() == subName)
            return auxEl->getValue();
        auxEl = auxEl->getNextElement();
    }

    cout<<"Subject not founded"<<endl;
    system("pause");
    system("cls");

    return NULL;
}

string Controler::eliminateSpaces(string str){
    /*Eliminate spaces from strings with 2 or more words (essential to save in .dat)*/
    for (int i=0; i<str.size(); i++){
        if (str[i]==' ')
            str[i]='*';
    }

    return str;
}
string Controler::recoverSpaces(string str){
    /*Recover eliminated spaces from strings with 2 or more words (essential to save in .dat)*/
    for (int i=0; i<str.size(); i++){
        if (str[i]=='*')
            str[i]=' ';
    }

    return str;
}

