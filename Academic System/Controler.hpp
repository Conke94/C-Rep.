#pragma once
#include <iostream>
#include "Elements/University.hpp"
#include "Elements/Department.hpp"
#include "Elements/Student.hpp"
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
    List<Subject*> subjectsMainList;
    List<Student*> studentsMainList;

public:
    void welcome();
    void closeWindow();

    void addUniversity();
    void addDepartment();
    void addSubject();
    void addStudent();
    
    void includeSubjects (Student* newStu);

    void listUniversities();
    void listDepartment();
    void listSubject();
    void listStudent();

    void saveAll();
    void recoverAll();

    University* searchUniversity(string uniName);
    Department* searchDepartment(string dptName);
    Subject* searchSubject (string subName);

    string eliminateSpaces(string str);
    string recoverSpaces(string str);
};