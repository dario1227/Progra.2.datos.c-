//
// Created by dario1227 on 24/04/18.
//

#include "BubbleSort.h"
void BubbleSort::start(Lista<Cancion>* lista) {
    Nodo<Cancion>* head=lista->head;
    Nodo<Cancion>* i= head;
    Nodo<Cancion>* j=head;
    while(i!= nullptr){
        while(j->next!= nullptr){
            if(j->value->album>j->next->value->album){
                string temp = j->value->album;
                j->value->album= j->next->value->album;
                j->next->value->album = temp;
            }
            j=j->next;
        }
        j=head;
        i=i->next;
    }
}
