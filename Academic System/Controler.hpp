#pragma once
#include "Elements/Professor.hpp"
#include "Elements/Student.hpp"
#include "Elements/Department.hpp"
#include "List.hpp"
#include <iostream>
#include <fstream>

class Controler{
private:
    List<University*> lUniversityMain;
    List<Department*> lDepartmentMain;
    List<Subject*> lSubjectMain;
    List<Professor*> lProfessorMain;
    List<Student*> lStudentMain;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Controler();
    ~Controler();

/*SETTERS & GETTERS*/

/*METHODS*/
    void welcome();
    void addElements();
    void listElements ();
    void addUniversity ();
    void addDepartment ();
    void addSubject ();
    void addProfessor ();
    void addStudent ();
    void listUniversities();
    void listDepartments();
    void listSubjects();
    void listProfessors();
    void listStudents();
    University* findUniversity(string name);
    Department* findDepartment(string name);
    Subject* findSubject (string name);
    void associateProfessorToSubject (Professor* prof);
    void associateSubjectsToStudent(Student* stu);

    void saveElements ();
    void saveUniversities();
    void saveDepartments();
    void saveSubjects();
    void saveProfessors();
    void saveStudents();
    void saveAll ();
/*DESENVOLVER*/
    void clearElements ();
    void clearUniversities ();
    void clearDepartments();
    void clearSubjects ();
    void clearPersons ();
};