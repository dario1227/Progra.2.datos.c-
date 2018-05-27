//
// Created by dario1227 on 01/05/18.
//

#ifndef PROGRA_2_DATOS_C_BINARYSEARCH_H
#define PROGRA_2_DATOS_C_BINARYSEARCH_H


#include "../data/Cancion.h"

class BinarySearch {
public:
    static Lista<Cancion *> *start(string album);

    static Cancion *search(string name, string artist);

};


#endif //PROGRA_2_DATOS_C_BINARYSEARCH_H
