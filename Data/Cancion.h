//
// Created by dario1227 on 24/04/18.
//

#ifndef PROGRA_2_DATOS_C_CANCIONES_H
#define PROGRA_2_DATOS_C_CANCIONES_H

#include <iostream>
using namespace std;
class Cancion {
public:
    Cancion();
    Cancion(string nombre,string album, string artista, string letra);
    string nombre;
    string album;
    string artista;
    string letra;
    int calificacion;

};


#endif //PROGRA_2_DATOS_C_CANCIONES_H
