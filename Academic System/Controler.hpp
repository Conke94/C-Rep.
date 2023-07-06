#pragma once
#include <iostream>
#include "Elements/University.hpp"
#include "Elements/Department.hpp"
#include "Lists/List.hpp"
#include <fstream>
using namespace std;

class Controler{
/*---------------------SINGLETON IMPLEMENTATION----------------------------------*/
private:
    Controler();
    static Controler* manager;

public:
    ~Controler();
    static Controler* getInstance ();
    static void deleteInstance();

/*-----------------------CLASS IMPLEMENTATION---------------------------------*/
private:
    List<University*> universitiesMainList;
    List<Department*> departmentsMainList;

public:
    void welcome();
    void closeWindow();

    void addUniversity();
    void addDepartment();

    void listUniversities();
    void listDepartment();

    void saveUniversity();

    void recoverUniversity();

    University* searchUniversity(string uniName);
    Department* searchDepartment(string dptName);

    string eliminateSpaces(string str);
    string recoverSpaces(string str);
};