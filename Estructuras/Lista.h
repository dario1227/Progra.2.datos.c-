//
// Created by dario1227 on 24/04/18.
//

#ifndef PROGRA_2_DATOS_C_LISTA_H
#define PROGRA_2_DATOS_C_LISTA_H

#include "Nodo.h"
template <typename T>
class Lista {
public:
    Lista(){
        this->head= nullptr;
        this->length=0;
        this->tail= nullptr;
    };
    Nodo<T>* head;
    int length;
    Nodo<T>* tail;

    void add(T valor){
        Nodo<T>* temp=this->head;
        Nodo<T>* nodo= new Nodo<T>();
        nodo->value=valor;
        if(this->head== nullptr){
            this->head=nodo;
            this->tail=nodo;
            this->length++;
        }
        else{
            while(temp->next!= nullptr){
                temp=temp->next;
            }
            this->length++;
            temp->next=nodo;
            this->tail=nodo;
            nodo->prev=temp;
        }
    }
    void erase(T valor){
        Nodo<T>* temp=this->head;
        if(temp->value==valor){
            this->head=temp->next;
            this->head->prev= nullptr;
            this->length--;
        }
        else {
            while (temp->next != nullptr) {
                if(temp->next->value==valor){
                    temp->next=temp->next->next;
                    temp->next->next->prev=temp;
                    this->length--;
                    break;
                }
                temp=temp->next;
            }
        }

    }
};


#endif //PROGRA_2_DATOS_C_LISTA_H
