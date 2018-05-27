//
// Created by kenneth on 4/27/18.
//

#include "Data_parser.h"
#include "User.h"
#include "Data_Holder.h"
#include <iostream>

using namespace std;

void Data_parser::append_user(json_object *object) {
    string age = json_object_to_json_string(json_object_object_get(object, "age"));
    string ID = json_object_to_json_string(json_object_object_get(object, "ID"));
    string name = json_object_to_json_string(json_object_object_get(object, "name"));
    string password = json_object_to_json_string(json_object_object_get(object, "password"));;
    User *usuario = new User(name, age, ID, password);
    Data_Holder::users->insertar(usuario->name, usuario);
}

void Data_parser::read_users() {
    json_object *array[] = {};
    array_list *var = json_object_get_array(array[0]);

    int indice = 0;

    while (array[indice] != nullptr) {

        append_user(array[indice]);

    }
}