//
// Created by dario1227 on 21/04/18.
//
#include <iostream>
#include "Estructuras/Lista.h"
#include "data/Cancion.h"
#include "Estructuras/BubbleSort.h"
#include "Estructuras/Quicksort.h"
#include "Estructuras/RadixSort.h"

using namespace std;
void print(Lista<Cancion*>*lista){
    Nodo<Cancion*>*temp=lista->head;
    while(temp!= nullptr){
        cout<<"############Cancion##########"<<"\n";
        cout<<temp->value->nombre<<"\n";
        cout<<temp->value->artista<<"\n";
        cout<<temp->value->album<<"\n";
        temp=temp->next;
    }
}
int main() {

    Lista<Cancion*>* prueba=new Lista<Cancion*>();
    prueba->add(new Cancion("Vicarious   ","10000Days  ","Tool     ",""));
    prueba->add(new Cancion("Master   ","Master ","Metallica    ",""));
    prueba->add(new Cancion("Hangar18   ","Rest in peace  ","Megadeth    ",""));
    prueba->add( new Cancion("Futile   ","Fear   ","Porcupine    ",""));
    prueba->add(new Cancion("Schism    ","Lateralus","Tool   ",""));
     RadixSort::start(prueba);
    print(prueba);
    return 0;
}