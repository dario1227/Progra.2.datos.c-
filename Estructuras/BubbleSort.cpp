//
// Created by dario1227 on 24/04/18.
//

#include "BubbleSort.h"
void BubbleSort::start(Lista<Cancion*>* lista) {
    Nodo<Cancion*>* head=lista->head;
    Nodo<Cancion*>* i= head;
    Nodo<Cancion*>* j=head;
    while(i!= nullptr){
        while(j->next!= nullptr){
            if(j->value->album>j->next->value->album){
                Cancion* temp = j->value;
                j->value= j->next->value;
                j->next->value= temp;
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
    Cancion::order(lista);
}
