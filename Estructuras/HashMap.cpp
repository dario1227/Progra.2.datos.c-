//
// Created by dario1227 on 27/04/18.
//

#include "HashMap.h"
HashMap::HashMap() {
    table = new HashEntry *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int HashMap::HashFunc(int key) {
    return key % TABLE_SIZE;
}

void HashMap::Insert(int key, User *value) {

    int hash = HashFunc(key);
    while (table[hash] != NULL && table[hash]->key != key) {
        hash = HashFunc(hash + 1);
    }
    if (table[hash] != NULL)
        delete table[hash];
    table[hash] = new HashEntry(key, value);
}
User* HashMap::Search1(string nombre) {
    User* result= nullptr;
    int y=0;
    while(y!=User::counter){
        if(HashMap::Search(y)->name==nombre){
            result=HashMap::Search(y);
            return result;
        }
        y++;
    }
    return result;
}
User *HashMap::Search(int key) {
    int hash = HashFunc(key);
    while (table[hash] != NULL && table[hash]->key != key) {
        hash = HashFunc(hash + 1);
    }
    if (table[hash] == NULL)
        return nullptr;
    else
        return table[hash]->value;
}
