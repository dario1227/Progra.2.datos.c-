//
// Created by dario1227 on 26/04/18.
//

#include "JsonFactory.h"
json_object* JsonFactory::makeSong(Cancion *song) {
    json_object* objeto=json_object_new_object();
    json_object* toAdd = json_object_new_string(song->nombre.c_str());
    json_object_object_add(objeto,"name",toAdd);
    toAdd = json_object_new_string(song->artista.c_str());
    json_object_object_add(objeto,"artist",toAdd);
    toAdd = json_object_new_string(song->album.c_str());
    json_object_object_add(objeto,"album",toAdd);
    toAdd = json_object_new_string(song->letra->toStdString().c_str());
    json_object_object_add(objeto,"lyrics",toAdd);
    toAdd = json_object_new_string(to_string(song->calificacion).c_str());
    json_object_object_add(objeto,"stars",toAdd);;
    return objeto;
}
json_object* JsonFactory::makeUser(User *usuario) {
    json_object* objeto=json_object_new_object();
    json_object* toAdd = json_object_new_string(usuario->ID.c_str());
    json_object_object_add(objeto,"ID",toAdd);
    toAdd = json_object_new_string(usuario->password.c_str());
    json_object_object_add(objeto,"password",toAdd);
    toAdd = json_object_new_string(usuario->name.c_str());
    json_object_object_add(objeto,"name",toAdd);
     toAdd = json_object_new_string(usuario->age.c_str());
    json_object_object_add(objeto,"age",toAdd);
    toAdd = json_object_new_string(usuario->favorites->c_str());
    json_object_object_add(objeto,"favorites",toAdd);
    json_object_object_add(objeto,"Friends",usuario->compas);
    return objeto;
}