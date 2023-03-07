#pragma once
#include <iostream>

template <class TIPO>
class List{
public:
    class Element{
        private:
            Element* nextElement;
            TIPO value;
        public:
        /*CONSTRUCTORS & DESTRUCTORS*/
            Element(){
                nextElement=nullptr;
            }
            ~Element(){
                nextElement=nullptr;
            }
        /*SETTERS & GETTERS*/
            void setNextElement(Element* el){
                nextElement=el;
            }
            Element* getNextElement(){
                return nextElement;
            }
            void setValue (TIPO val){
                value=val;
            }
            TIPO getValue(){
                return value;
            }
    };
private:
    Element* firstElement;
    Element* currentElement;
    int size;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    List(){
        firstElement=nullptr;
        currentElement=nullptr;
        size=0;
    }
    ~List(){
        clear();
    }
    
    /*SETTERS & GETTERS*/
    Element* getFirstElement (){
        return firstElement;
    } 
    void setFirstElement(Element* el){
        firstElement=el;
    }
    Element* getCurrentElement(){
        return currentElement;
    }
    void setCurrentElement(Element* el){
        currentElement=el;
    }  

    /*METHODS*/
    void includeNewElement(TIPO data){
        Element* nEl = nullptr;
        nEl=new Element();
        nEl->setValue(data);

        if (firstElement==nullptr)
            firstElement=nEl;
        else
            currentElement->setNextElement(nEl);
        currentElement=nEl;
        size++;
    }
    void clear (){
        Element* auxEl = nullptr;
        Element* it=nullptr;
        it=firstElement;

        while (it!=nullptr){
            auxEl=it;
            it=auxEl->getNextElement();
            delete(auxEl);
        }

        firstElement=nullptr;
        currentElement=nullptr;
    }
};