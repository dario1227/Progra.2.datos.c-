//
// Created by dario1227 on 01/05/18.
//

#ifndef PROGRA_2_DATOS_C_ARBOLB_H
#define PROGRA_2_DATOS_C_ARBOLB_H


#include "../data/Cancion.h"
#include <iostream>
class Cancion;
using namespace std;
class ArbolB {
public:
    void Insertar_Nodo(int clave);
    Lista<Cancion*> *Buscar_Nodo(string x);

};


#endif //PROGRA_2_DATOS_C_ARBOLB_H
