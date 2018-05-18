//
// Created by kenneth on 5/18/18.
//

#ifndef PROGRA_2_DATOS_C_FACTORY_H
#define PROGRA_2_DATOS_C_FACTORY_H

#include "iostream"
using namespace std;
class Factory {
public:
 static void   Cancion(string nombre,string album, string artista, string letra);
 static void User(string name, string age, string ID, string password);
};


#endif //PROGRA_2_DATOS_C_FACTORY_H
