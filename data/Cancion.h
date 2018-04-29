//
// Created by dario1227 on 24/04/18.
//

#ifndef PROGRA_2_DATOS_C_CANCIONES_H
#define PROGRA_2_DATOS_C_CANCIONES_H

#include <iostream>
#include <QtCore/QString>
#include "../Estructuras/Lista.h"

using namespace std;
class Cancion {
public:
    Cancion();
    Cancion(string nombre,string album, string artista, string letra);
    int pos;
    string nombre;
    string album;
    string artista;
    QString *letra;
    int calificacion;
    static Lista<Cancion*>*Music;
    static void order(Lista<Cancion*>*music);

};


#endif //PROGRA_2_DATOS_C_CANCIONES_H
