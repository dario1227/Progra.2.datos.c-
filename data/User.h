//
// Created by dario1227 on 26/04/18.
//

#ifndef PROGRA_2_DATOS_C_USER_H
#define PROGRA_2_DATOS_C_USER_H

#include <iostream>
#include "../Estructuras/Lista.h"
#include "json-c/json_object.h"
#include "../Estructuras/HashMap.h"
#include "frien.h"

using namespace std;

class HashMap;

class User {
public:
    User(string name, string age, string ID, string password);

    User();

    void addFriend(User *compa);

    static int counter;
    static HashMap *UserHash;
    string ID;
    string password;

    bool contains(User *amigo);

    int num;
    string name;
    string age;
    string favorites[10];
    string compas;
    string recomendados;

    void addRecomendado(string name);

    Lista<string> *getRecomendados();

    static Lista<User *> *Users;

    Lista<User *> *getFriends();

};


#endif //PROGRA_2_DATOS_C_USER_H
