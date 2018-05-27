//
// Created by dario1227 on 27/04/18.
//

#ifndef PROGRA_2_DATOS_C_HASHMAP_H
#define PROGRA_2_DATOS_C_HASHMAP_H

#include "HashEntry.h"

const int TABLE_SIZE = 128;

class HashEntry;

class User;

class HashMap {
private:
    HashEntry **table;
public:
    HashMap();

    int HashFunc(int key);

    void Insert(int key, User *value);

    User *Search(int key);
};


#endif //PROGRA_2_DATOS_C_HASHMAP_H
