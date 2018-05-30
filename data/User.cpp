//
// Created by dario1227 on 26/04/18.
//

#include <algorithm>
#include "User.h"
#include "Data_Holder.h"
#include "JsonFactory.h"

int  User::counter = 0;
HashMap *User::UserHash = new HashMap();
Lista<User *> *User::Users = new Lista<User *>();

void User::addFriend(User *compa) {
    this->compas.append(compa->name + "&");
}

void User::addRecomendado(string name) {
    this->recomendados.append(name + "&");
}

Lista<string> *User::getRecomendados() {
    Lista<string> *result = new Lista<string>();
    int y = 0;
    string frien;
    while (y != this->recomendados.length()) {
        if (this->recomendados[y] != '&') {
            char sa = this->recomendados[y];
            frien += sa;
        } else {
            result->add(frien);
            frien.clear();

        }
        y++;
    }
    return result;

}

//verifica un amigo en la lista
bool User::contains(User *amigo) {
    Lista<User *> *lista = this->getFriends();
    Nodo<User *> *temp = lista->head;
    bool result = false;
    while (temp != nullptr) {
        if (amigo->name == temp->value->name) {
            result = true;
            return result;
        }
        temp = temp->next;
    }
    return result;

}

string chop2(string data) {
    string name = data;
    name.resize(name.length() - 1);
    std::reverse(name.begin(), name.end());
    name.resize(name.length() - 1);
    std::reverse(name.begin(), name.end());
    return name;

}

//obtiene la lista de amigos como objeto
Lista<User *> *User::getFriends() {
    Lista<User *> *result = new Lista<User *>();
    int y = 0;
    string frien;
    while (y != this->compas.length()) {
        if (this->compas[y] != '&') {
            char sa = this->compas[y];
            frien += sa;
        } else {
            result->add(User::UserHash->Search1(frien));
            frien.clear();

        }
        y++;
    }
    return result;

}

User::User(string name, string age, string ID, string password) {
    this->compas = "";
    this->password = password;
    this->name = name;
    this->ID = ID;
    this->age = age;
    this->num = User::counter;
    UserHash->Insert(counter, this);
    User::Users->add(this);
    User::counter++;
    Data_Holder::users->insertar(name, this);


}

User::User() {
    this->age = "";
    this->ID = "";
    this->name = "";
    this->password = "";
    this->compas = "";
    this->num = User::counter;
    UserHash->Insert(counter, this);
    User::Users->add(this);
    User::counter++;
}