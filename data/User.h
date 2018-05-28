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

using  namespace std;
class HashMap;
class User {
public:
    User(string name, string age, string ID, string password);
    User();
    void addFriend(json_object* compa);
    static HashMap* UserHash;
    string ID;
    string password;
    bool contains(User* amigo);
    int num;
    string name;
    string age;
    string favorites[10];
    json_object*compas;
    static Lista<User*>*Users;
    Lista<frien*>* getFriends();

};


#endif //PROGRA_2_DATOS_C_USER_H
