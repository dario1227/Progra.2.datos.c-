//
// Created by dario1227 on 28/04/18.
//

#ifndef PROGRA_2_DATOS_C_BACKTRACKING_H
#define PROGRA_2_DATOS_C_BACKTRACKING_H


#include "../data/Cancion.h"
#include "Lista.h"
#include "QString"

class BackTracking {
public:
    static Cancion *start(Lista<Cancion *> *Music, string frase);
};


#endif //PROGRA_2_DATOS_C_BACKTRACKING_H
