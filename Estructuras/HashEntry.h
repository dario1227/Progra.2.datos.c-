//
// Created by dario1227 on 27/04/18.
//

#ifndef PROGRA_2_DATOS_C_HASHENTRY_H
#define PROGRA_2_DATOS_C_HASHENTRY_H

#include <iostream>
#include "../data/User.h"

using namespace std;
class User;
class HashEntry {
public:
    HashEntry(int key, User* user);
    int key;
    User* value;
};


#endif //PROGRA_2_DATOS_C_HASHENTRY_H
