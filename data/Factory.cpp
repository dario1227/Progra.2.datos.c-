//
// Created by kenneth on 5/18/18.
//

#include "Factory.h"
#include "User.h"
#include "JsonFactory.h"

void Factory::User2(string name, string age, string ID, string password) {
    User* usuario= new User(name,age,ID,password);
    JsonFactory::save();
}
void Factory::Cancion2(string nombre, string album, string artista, string letra,string genero) {
    Cancion* cancio = new Cancion( nombre,  album,  artista,  letra,genero);
    JsonFactory::save();
}