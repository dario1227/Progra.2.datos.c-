//
// Created by kenneth on 5/18/18.
//

#include "Factory.h"
#include "User.h"
#include "JsonFactory.h"

void Factory::User(string name, string age, string ID, string password) {
    new User(name,age,ID,password);
    JsonFactory::save();
}
void Factory::Cancion(string nombre, string album, string artista, string letra) {
    new Cancion( nombre,  album,  artista,  letra);
    JsonFactory::save();
}