#include "Professor.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Professor::Professor():Person(2){
        dptBelonged=nullptr;
    }
Professor::Professor(string n, int a):Person(n, a, 2){
        dptBelonged=nullptr;
    }
Professor::~Professor(){

    }

/*SETTERS & GETTERS*/
void Professor::setDptBelonged (Department* dpt){
    dptBelonged=dpt;
}
Department* Professor::getDptBelonged (){
    return dptBelonged;
}

/*METHODS*/











    