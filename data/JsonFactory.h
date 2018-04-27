//
// Created by dario1227 on 26/04/18.
//

#ifndef PROGRA_2_DATOS_C_JSONFACTORY_H
#define PROGRA_2_DATOS_C_JSONFACTORY_H


#include "Cancion.h"
#include "User.h"
#include <json-c/json.h>
class JsonFactory {
public:
    static json_object* makeSong(Cancion * song);
    static json_object* makeUser(User* usuario);

};


#endif //PROGRA_2_DATOS_C_JSONFACTORY_H
