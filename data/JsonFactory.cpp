//
// Created by dario1227 on 26/04/18.
//

#include <fstream>
#include <zconf.h>
#include <pwd.h>
#include "JsonFactory.h"
//quita las comillas que retornan las funciones de jsonc
string chop(string data) {
    string name = data;
    name.resize(name.length() - 1);
    std::reverse(name.begin(), name.end());
    name.resize(name.length() - 1);
    std::reverse(name.begin(), name.end());
    return name;

}

void readaux(string data) {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name = homedir;
    ofstream myfile;
    string da = name + "/Jsons" + "/" + data + ".json";
    json_object *datos = json_object_from_file(da.c_str());
    int y = 0;
    int z = json_object_array_length(datos);
    if (data == "Canciones") {
        while (y != z) {
            json_object *temp = json_object_array_get_idx(datos, y);
            new Cancion(chop(json_object_to_json_string(json_object_object_get(temp, "name"))),
                        chop(json_object_to_json_string(json_object_object_get(temp, "album"))),
                        chop(json_object_to_json_string(json_object_object_get(temp, "artist"))),
                        chop(json_object_to_json_string(json_object_object_get(temp, "lyrics"))),
                        chop(json_object_to_json_string(json_object_object_get(temp, "genero"))));
            y++;

        }
    } else {
        while (y != z) {
            json_object *temp = json_object_array_get_idx(datos, y);
            new User(chop(json_object_to_json_string(json_object_object_get(temp, "name"))),
                     chop(json_object_to_json_string(json_object_object_get(temp, "age"))),
                     chop(json_object_to_json_string(json_object_object_get(temp, "ID"))),
                     chop(json_object_to_json_string(json_object_object_get(temp, "password"))));
            y++;

        }

    }

}
// lee los archivos Json y carga al server los datos
void JsonFactory::read() {
    int x = 0;
    string data;
    data = "Canciones";
    while (x < 2) {
        readaux(data);
        x++;
        data = "Usuarios";
    }

}

void saveaux(string data) {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    string name = homedir;
    ofstream myfile;
    string da = name + "/Jsons" + "/" + data + ".json";
    myfile.open(da.c_str());
    json_object *array = json_object_new_array();
    if (data == "Canciones") {
        Nodo<Cancion *> *temp = Cancion::Music->head;
        while (temp != nullptr) {
            json_object_array_add(array, JsonFactory::makeSong(temp->value));
            temp = temp->next;
        }
        json_object_to_file_ext((char *) da.c_str(), array, 0777);

    } else {
        Nodo<User *> *temp = User::Users->head;
        temp = User::Users->head;
        while (temp != nullptr) {
            json_object_array_add(array, JsonFactory::makeUser(temp->value));

            temp = temp->next;
        }
        json_object_to_file_ext((char *) da.c_str(), array, 0777);

    }


    myfile.close();

}
//guarda las canciones en memoria al archivos de Json
void JsonFactory::save() {
    int x = 0;
    string data;
    data = "Canciones";
    while (x < 2) {
        saveaux(data);
        x++;
        data = "Usuarios";
    }
}
//crea un archivo Json para una cancion
json_object *JsonFactory::makeSong(Cancion *song) {
    json_object *objeto = json_object_new_object();
    json_object *toAdd = json_object_new_string(song->nombre.c_str());
    json_object_object_add(objeto, "name", toAdd);
    toAdd = json_object_new_string(song->artista.c_str());
    json_object_object_add(objeto, "artist", toAdd);
    toAdd = json_object_new_string(song->album.c_str());
    json_object_object_add(objeto, "genero", toAdd);
    toAdd = json_object_new_string(song->genero.c_str());
    json_object_object_add(objeto, "album", toAdd);
    toAdd = json_object_new_string(song->letra->toStdString().c_str());
    json_object_object_add(objeto, "lyrics", toAdd);
    toAdd = json_object_new_string(to_string(song->calificacion).c_str());
    json_object_object_add(objeto, "stars", toAdd);;
    return objeto;
}
//crea el Json para un user
json_object *JsonFactory::makeUser(User *usuario) {
    json_object *objeto = json_object_new_object();
    json_object *toAdd = json_object_new_string(usuario->ID.c_str());
    json_object_object_add(objeto, "ID", toAdd);
    toAdd = json_object_new_string(usuario->password.c_str());
    json_object_object_add(objeto, "password", toAdd);
    toAdd = json_object_new_string(usuario->name.c_str());
    json_object_object_add(objeto, "name", toAdd);
    toAdd = json_object_new_string(usuario->age.c_str());
    json_object_object_add(objeto, "age", toAdd);
    toAdd = json_object_new_string(usuario->favorites->c_str());
    json_object_object_add(objeto, "favorites", toAdd);
    json_object_object_add(objeto, "Friends", usuario->compas);
    return objeto;
}