//
// Created by dario1227 on 24/04/18.
//

#include "Cancion.h"
Cancion::Cancion() {
    this->nombre= nullptr;
    this->album= nullptr;
    this->artista= nullptr;
    this->letra= nullptr;
    this->calificacion=0;
}
Cancion::Cancion(string nombre, string album, string artista, string letra) {
    this->nombre= nombre;
    this->album= album;
    this->artista= artista;
    this->letra= letra;
    this->calificacion=0;

}
