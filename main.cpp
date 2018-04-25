//
// Created by dario1227 on 21/04/18.
//
#include <iostream>
#include "Estructuras/Lista.h"
#include "Data/Cancion.h"
#include "Estructuras/BubbleSort.h"
#include "Estructuras/Quicksort.h"
#include "Estructuras/RadixSort.h"

using namespace std;
int main() {

    Lista<Cancion>* prueba=new Lista<Cancion>();
    prueba->add(new Cancion("jeremy   ","perro  ","Tool     ",""));
    prueba->add(new Cancion("patient   ","gato  ","Don Omar    ",""));
    prueba->add(new Cancion("Aarabola   ","Aandril  ","Belinda    ",""));
    prueba->add( new Cancion("vicarious   ","Ardilla   ","Chayanne     ",""));
    prueba->add(new Cancion("schism    ","zanahoria","Maluma    ",""));
    BubbleSort::start(prueba);
    Nodo<Cancion>* temp=prueba->head;
    while (temp!= nullptr){
        cout<<temp->value->album;
        temp=temp->next;
    }
    Quicksort::start(prueba);
    temp=prueba->head;
    while (temp!= nullptr){
        cout<<temp->value->nombre;
        temp=temp->next;
    }
    return 0;
}