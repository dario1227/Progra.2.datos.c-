//
// Created by dario1227 on 24/04/18.
//

#include "Cancion.h"
static int num=0;
Lista<Cancion*>*Cancion::Music=new Lista<Cancion*>();
void Cancion::order(Lista<Cancion *> *music) {
    Nodo<Cancion*>*temp=music->head;
    int c=0;
    while(temp!= nullptr){
        temp->value->pos=c;
        c++;
        temp=temp->next;

    }
}
Cancion::Cancion() {
    this->nombre= nullptr;
    this->album= nullptr;
    this->artista= nullptr;
    this->letra= nullptr;
    this->pos=num;
    this->calificacion=0;
    num++;
    Cancion::Music->add(this);
}
Cancion::Cancion(string nombre, string album, string artista, string letra) {
    this->nombre= nombre;
    this->album= album;
    this->pos=num;
    this->artista= artista;
    this->letra= new QString(letra.c_str());
    this->calificacion=0;
    num++;
    Cancion::Music->add(this);

}