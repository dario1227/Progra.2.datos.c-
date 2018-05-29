//
// Created by dario1227 on 24/04/18.
//

#include "Cancion.h"

static int num = 0;
Lista<Cancion *> *Cancion::Music = new Lista<Cancion *>();
ArbolB *Cancion::arbolb = new ArbolB();
AVL *Cancion::avl = new AVL();
//Ordena los indices de las canciones una vez que se ordena segun atributo.
void Cancion::order(Lista<Cancion *> *music) {
    Nodo<Cancion *> *temp = music->head;
    int c = 0;
    while (temp != nullptr) {
        temp->value->pos = c;
        c++;
        temp = temp->next;

    }
}
//elimina una cancion con los 3 atributos
void Cancion::erase(string name, string artist, string album) {
    Nodo<Cancion *> *temp = Cancion::Music->head;
    string nombre = temp->value->nombre;
    string artista = temp->value->artista;
    string album2 = temp->value->album;
    if (nombre == name && artista == artist && album2 == album) {
        Cancion::Music->head = temp->next;
        Cancion::Music->head->prev = nullptr;
        Cancion::Music->length--;
    } else {
        while (temp->next != nullptr) {
            string nombre = temp->next->value->nombre;
            string artista = temp->next->value->artista;
            string album2 = temp->next->value->album;
            if (nombre == name && artista == artist && album2 == album) {
                if (temp->next->next != nullptr) {
                    temp->next->next->prev = temp;
                }
                temp->next = temp->next->next;
                Cancion::Music->length--;
                break;
            }
            temp = temp->next;
        }
    }
}

Cancion::Cancion() {
    this->nombre = nullptr;
    this->album = nullptr;
    this->artista = nullptr;
    this->letra = nullptr;
    this->pos = num;
    this->calificacion = 0;
    this->genero = nullptr;
    Cancion::Music->add(this);
    Cancion::arbolb->Insertar_Nodo(num);
    Cancion::avl->Insertar(num);
    num++;
}

//
Cancion::Cancion(string nombre, string album, string artista, string letra, string genero) {
    this->nombre = nombre;
    this->album = album;
    this->pos = num;
    this->genero = genero;
    this->artista = artista;
    this->letra = new QString(letra.c_str());
    this->calificacion = 0;
    Cancion::arbolb->Insertar_Nodo(num);
    Cancion::avl->Insertar(num);
    num++;
    Cancion::Music->add(this);

}
