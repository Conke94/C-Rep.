#pragma once
#include <iostream>
using namespace std;

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
                    nextElement=NULL;
                }
                ~Element(){
                    nextElement=NULL;
                }

                /*SETTERS & GETTERS*/
                void setNextElement (Element* p){
                    nextElement=p;
                }
                void setValue(TIPO p){
                    value = p;
                }
                Element* getNextElement(){
                    return nextElement;
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
        List (){
            firstElement = NULL;
            currentElement = NULL;
            size=0;
        }
        ~List(){
            clear();
        }
        void clear (){
            Element* it = NULL;
            Element* it2 = NULL;
            it = firstElement;
            
            while (it!=NULL){
                it2 = it->getNextElement();
                delete(it->getValue());
                delete(it);
                it = it2;
            }

            firstElement = NULL;
            currentElement = NULL;
        }

        /*SETTERS & GETTERS*/
        void setFirstElement(Element* p){
            firstElement=p;
        }
        void setCurrentElement (Element* p){
            currentElement=p;
        }
        Element* getFirstElement (){
            return firstElement;
        }
        Element* getCurrentElement(){
            return currentElement;
        }
        int getSize(){
            return size;
        }

        /*METHODS*/
        void includeElement (TIPO newOne){
            Element* newEl = NULL;
            newEl = new Element();
            newEl->setValue(newOne);

            if (currentElement!=NULL)
                currentElement->setNextElement(newEl);
            else{
                firstElement = newEl;
            }

            currentElement = newEl;
            size++;
        }
        void deleteElement (TIPO wanted){
            Element* auxEl = getFirstElement();
            Element* auxEl2 = NULL;

            while (auxEl!=NULL){
                if (auxEl->getValue()==wanted && auxEl==getFirstElement()){
                    setFirstElement(auxEl->getNextElement());
                    auxEl->setNextElement(NULL);
                    delete(auxEl->getValue());
                    delete(auxEl);
                    size--;
                    return;
                }
                else if (auxEl->getValue()==wanted){
                    auxEl2->setNextElement(auxEl->getNextElement());
                    delete(auxEl->getValue());
                    delete(auxEl);
                    size--;
                    return;
                }
                auxEl2 = auxEl;
                auxEl = auxEl -> getNextElement();
            }
            cout<<"This element isn't included in the list. Please, try again"<<endl;
        }
};