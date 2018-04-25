//
// Created by dario1227 on 24/04/18.
//

#ifndef PROGRA_2_DATOS_C_NODO_H
#define PROGRA_2_DATOS_C_NODO_H

template <typename T>
class Nodo {
public:
    Nodo<T>(){
        this->next= nullptr;
    };
    T* value;
    Nodo* next;


};


#endif //PROGRA_2_DATOS_C_NODO_H
