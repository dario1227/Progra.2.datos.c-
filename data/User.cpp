//
// Created by dario1227 on 26/04/18.
//

#include "User.h"
void User::addFriend(json_object *compa) {
    json_object_array_add(this->compas,compa);
}