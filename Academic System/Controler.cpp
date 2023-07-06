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
        cout<<"3-List Universities"<<endl;
        cout<<"4-List Departments"<<endl;
        cout<<"5-Save Universities"<<endl;
        cout<<"6-Recover Universities"<<endl;
        cout<<"7-Close window"<<endl;
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
                listUniversities();
            }break;
            case 4:{
                listDepartment();
            }
            case 5:{
                saveUniversity();
            }break;
            case 6:{
                recoverUniversity();
            }break;
            case 7:{
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
    
    cout<<"Insert university belonged:"; //VERIFICAR SE ESTÁ CERTO
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

void Controler::saveUniversity(){
    /*Save the university info in a .dat file*/
        ofstream saver("Data/universitySave.dat", ios::out);

        if (!saver)
        {
            cerr << "File couldn't be open" << endl;
            fflush(stdin);
            getchar();
            return;
        }

        saver<<universitiesMainList.getSize()<<endl;
        saver<<departmentsMainList.getSize()<<endl;
        List<University*>::Element* uniElAux = universitiesMainList.getFirstElement();
        List<Department*>::Element* dptElAux = NULL;
        while (uniElAux!=NULL){
            saver<<uniElAux->getValue()->getId()<<endl;
            uniElAux->getValue()->setUniversityName(eliminateSpaces(uniElAux->getValue()->getUniversityName()));
            saver<<uniElAux->getValue()->getUniversityName()<<endl;
            saver<<uniElAux->getValue()->getFoundation()<<endl;
            uniElAux->getValue()->setCity(eliminateSpaces(uniElAux->getValue()->getCity()));
            saver<<uniElAux->getValue()->getCity()<<endl;
            dptElAux = uniElAux->getValue()->getOwnedDepartements().getFirstElement();
            dptElAux->getValue ()->printInfo();
            system("pause");//ERRO ANTES DAQUI
            while (dptElAux != NULL){
                saver<<dptElAux->getValue()->getId()<<endl;
                dptElAux->getValue()->setDptName(eliminateSpaces(dptElAux->getValue()->getDptName()));
                saver<<dptElAux->getValue()->getDptName()<<endl;
                dptElAux = dptElAux->getNextElement();
            }

            uniElAux=uniElAux->getNextElement();
        }

        saver.close();
        cout<<"Save completed"<<endl;
        system("pause");
        system("cls");
        welcome();
    }

void Controler::recoverUniversity(){
    /*Recover some infos saved in a .dat file*/
    ifstream recover ("Data/universitySave.dat", ios::in);

    if (!recover){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush(stdin);
        getchar();
        return;
    }

    int size1, size2, id;
    recover>>size1;
    recover>>size2;
    string nameAux;
    int year;
    string cityAux;
    University* newUni = NULL;

    for (int i=0; i<size1 + size2; i++){
        recover>>id;
        if (id==1){
            recover>>nameAux;
            nameAux = recoverSpaces(nameAux);
            recover>>year;
            recover>>cityAux;
            cityAux = recoverSpaces(cityAux);
        
            newUni = new University(nameAux, year, cityAux);
            universitiesMainList.includeElement(newUni);    
        }
        else if (id==2){
            recover>>nameAux;
            nameAux = recoverSpaces(nameAux);
            newUni->includeDepartments(searchDepartment(nameAux));
        }
    }

    cout<<"Universities recovered sucessfully!"<<endl;
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

