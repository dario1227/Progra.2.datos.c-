//
// Created by dario1227 on 26/04/18.
//

#ifndef PROGRA_2_DATOS_C_USER_H
#define PROGRA_2_DATOS_C_USER_H

#include <iostream>
#include "../Estructuras/Lista.h"
#include "json/json_object.h"
using  namespace std;
class User {
public:
    void addFriend(json_object* compa);
    User(string name, string age, string ID, string password){
        this->compas=json_object_new_array();
        this->password=password;
        this->name=name;
        this->ID=ID;
        this->age=age;
    }
    User(){
        this->age= "";
        this->ID= "";
        this->name= "";
        this->password= "";
        this->compas=json_object_new_array();
    }
    string ID;
    string password;
    string name;
    string age;
    string favorites[10];
    json_object*compas;

};


#endif //PROGRA_2_DATOS_C_USER_H
