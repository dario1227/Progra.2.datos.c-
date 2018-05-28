//
// Created by kenneth on 4/30/18.
//

#include <sstream>
#include "XML_handler.h"
#include "../data/rapidxml.hpp"
#include "../Estructuras/Lista.h"
#include "../data/Cancion.h"
#include "../data/XML_generator.h"
#include "../data/rapidxml_print.hpp"
#include "../data/Data_Holder.h"
#include "Archive_manager.h"
#include "../data/base64.h"
#include "Holder.h"
#include "../data/Factory.h"
#include "../Estructuras/BinarySearch.h"
#include "../Estructuras/BackTracking.h"
#include "../Estructuras/RadixSort.h"
#include "../Estructuras/BubbleSort.h"
#include "../Estructuras/Quicksort.h"

/**
 * Metodo para parsear metodo de canciones
 * @param archive
 */
void XML_handler::parse_song_requests(char *archive) {
    xml_document<> doc;
    doc.parse<0>(archive);
    xml_node<> *root_node = doc.first_node("Root");
    char *metodo = root_node->first_attribute("Method")->value();
    QString metodo2 = QString(metodo);
    char *busqueda = root_node->first_attribute("Busqueda")->value();
    string page = root_node->first_attribute("Page")->value();
    QString orden = root_node->first_attribute("Orden")->value();

    int x = stoi(page);
    if (metodo2.contains("Autor")) {
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion *> *lista = Cancion::avl->Buscar(busqueda);
        if (orden.contains("true")) {
            RadixSort::start(lista);
        }
        xml_document<> *documento = XML_generator::create_Music_list(lista, x);
        std::stringstream ss;
        ss << (*documento);
        std::string result_xml = ss.str();
        documento->clear();

        char *variable = (char *) result_xml.c_str();
        Holder::odisea->send2(result_xml.c_str());

    }
    if (metodo2.contains("Album")) {
        //
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion *> *lista = BinarySearch::start(busqueda);
        if (orden.contains("true")) {
            BubbleSort::start(lista);
        }
        xml_document<> *documento = XML_generator::create_Music_list(lista, x);
        std::stringstream ss;
        ss << (*documento);
        std::string result_xml = ss.str();
        char *variable = (char *) result_xml.c_str();
        documento->clear();
        Holder::odisea->send2(result_xml.c_str());
    }
    if (metodo2.contains("Nombre")) {
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion *> *lista = Cancion::arbolb->Buscar_Nodo(busqueda);
        if (orden.contains("true")) {
            Quicksort::start(lista);
        }
        xml_document<> *documento = XML_generator::create_Music_list(lista, x);
        std::stringstream ss;
        ss << (*documento);
        std::string result_xml = ss.str();
        documento->clear();

        // char* variable =(char*) result_xml.c_str();
        Holder::odisea->send2(result_xml.c_str());

    }
    if (metodo2.contains("Letra")) {
        //debe cambiar a metodos de busqueda ahi
        Cancion *cancion = BackTracking::start(Cancion::Music, busqueda);
        xml_document<> *documento = new xml_document<>();

        xml_node<> *decl = documento->allocate_node(node_declaration);
        decl->append_attribute(documento->allocate_attribute("version", "1.0"));
        decl->append_attribute(documento->allocate_attribute("encoding", "utf-8"));
        documento->append_node(decl);
        xml_node<> *root = documento->allocate_node(node_element, "Root");
        root->append_attribute(documento->allocate_attribute("Operation", "Music List"));
        if (cancion == nullptr) {
            std::cout << "LLEGUE AQUI NO SE" << std::endl;
            root->append_attribute(documento->allocate_attribute("Result", "false"));
            documento->append_node(root);
            std::stringstream ss;
            ss << (*documento);
            std::string result_xml = ss.str();
            Holder::odisea->send2(result_xml);
            return;
        }
        xml_node<> *child = documento->allocate_node(node_element, "Cancion");
        char *letra = documento->allocate_string(cancion->letra->toLatin1().data());
        char *calificacion = documento->allocate_string(std::to_string(cancion->calificacion).c_str());
        char *nombre = documento->allocate_string(cancion->nombre.c_str());
        char *album = documento->allocate_string(cancion->album.c_str());
        char *artista = documento->allocate_string(cancion->artista.c_str());
        child->append_attribute(documento->allocate_attribute("Letra", letra));
        child->append_attribute(documento->allocate_attribute("Nombre", nombre));
        child->append_attribute(documento->allocate_attribute("Album", album));
        child->append_attribute(documento->allocate_attribute("Calificacion", calificacion));
        child->append_attribute(documento->allocate_attribute("Artista", artista));
        root->append_attribute(documento->allocate_attribute("Result", "true"));
        root->append_node(child);
        documento->append_node(root);
        std::stringstream ss;
        ss << (*documento);
        std::string result_xml = ss.str();
        documento->clear();

        char *variable = (char *) result_xml.c_str();
        Holder::odisea->send2(result_xml);

    }
    if (metodo2.contains("Nada")) {
        std::cout << "LLEGUE AQUI P O" << std::endl;

        Lista<Cancion *> *lista = Cancion::Music;
        xml_document<> *documento = XML_generator::create_Music_list(lista, x);
        std::stringstream ss;
        ss << (*documento);
        std::string result_xml = ss.str();
        char *variable = (char *) result_xml.c_str();
        Holder::odisea->send2(result_xml.c_str());
    }if(metodo2.contains("Random")){
        Lista<Cancion *> *cosa =new Lista<Cancion*>();
        cosa->add(Cancion::Music->get(rand()%Cancion::Music->length));
        cosa->add(Cancion::Music->get(rand()%Cancion::Music->length));
        cosa->add(Cancion::Music->get(rand()%Cancion::Music->length));
//        cosa->add(Cancion::Music->get(rand()%Cancion::Music->length));
//        cosa->add(Cancion::Music->get(rand()%Cancion::Music->length));
        xml_document<> *documento = XML_generator::create_Music_list(cosa, x);
        std::stringstream ss;
        ss << (*documento);
        std::string result_xml = ss.str();
        char *variable = (char *) result_xml.c_str();
        documento->clear();

        Holder::odisea->send2(result_xml.c_str());

    }

}

void XML_handler::edit_songdata(char *archivo) {
    xml_document<> doc;
    doc.parse<parse_full>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    char *songname = root_node->first_attribute("Name")->value();
    char *person = root_node->first_attribute("Artist")->value();
    xml_node<> *editado = root_node->first_node("Edit");
    Cancion *cancion = BinarySearch::search(songname, person);
    if (cancion == nullptr) {
        root_node->append_attribute(doc.allocate_attribute("Result", "false"));
        std::stringstream ss;
        ss << (doc);
        std::string result_xml = ss.str();
        Holder::odisea->send2(result_xml.c_str());
    } else {
        cancion->artista = editado->first_attribute("Artista")->value();
        cancion->nombre = editado->first_attribute("Name")->value();
        cancion->album = editado->first_attribute("Album")->value();
        cancion->letra = new QString(editado->first_attribute("Letra")->value());
        root_node->append_attribute(doc.allocate_attribute("Result", "false"));
        std::stringstream ss;
        ss << (doc);
        std::string result_xml = ss.str();
        Holder::odisea->send2(result_xml.c_str());
    }
}

void XML_handler::parse_xml_request_log(char *archive) {
    xml_document<> doc;
    doc.parse<parse_full>(archive);
    xml_node<> *root_node = doc.first_node("Root");
    xml_node<> *user = root_node->first_node("User");
    string name = user->first_attribute("Name")->value();
    char *password = user->first_attribute("Password")->value();
    User *usuario = User::UserHash->Search1(name);
    std::cout << name << std::endl;
    if (usuario == nullptr) {
        root_node->append_attribute(doc.allocate_attribute("Result", "false"));
        std::stringstream ss;
        ss << doc;
        std::string result_xml = ss.str();
        std::cout << result_xml << std::endl;
        Holder::odisea->send2(result_xml);
        return;
    }
    if (usuario->password == password) {
        std::cout << "WHY IM HERE PASSWORD" << std::endl;

        root_node->append_attribute(doc.allocate_attribute("Result", "true"));
        std::stringstream ss;
        ss << doc;
        std::string result_xml = ss.str();
        Holder::odisea->send2(result_xml);

        return;
    } else {
        std::cout << "WHY IM HERE NO PASSWORD" << std::endl;
        root_node->append_attribute(doc.allocate_attribute("Result", "false"));
        std::stringstream ss;
        ss << doc;
        std::string result_xml = ss.str();
        Holder::odisea->send2(result_xml);

        return;
    }
}

void XML_handler::parse_new_user(char *archive) {
    xml_document<> doc;
    doc.parse<0>(archive);
    xml_node<> *root_node = doc.first_node("Root");
    xml_node<> *user = root_node->first_node("User");
    char *name = user->first_attribute("Name")->value();
    char *age = user->first_attribute("Age")->value();
    char *id = user->first_attribute("ID")->value();
    char *password = user->first_attribute("Password")->value();
    if (Data_Holder::users->search(name) != nullptr) {
        root_node->append_attribute(doc.allocate_attribute("Result", "false"));
        std::stringstream ss;
        ss << doc;
        std::string result_xml = ss.str();
        std::cout << result_xml << std::endl;
        Holder::odisea->send2(result_xml);
        return;
    }
    root_node->append_attribute(doc.allocate_attribute("Result", "true"));
    std::stringstream ss;
    ss << doc;
    Factory::User2(name, age, id, password);

    std::string result_xml = ss.str();
    std::cout << result_xml << std::endl;
    Holder::odisea->send2(result_xml);
    new User(name, age, id, password);


}

void XML_handler::primary_handler(char *archivo) {
    std::stringstream to_return;
    to_return << archivo;
    xml_document<> doc;
    doc.parse<0>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    string operacion = root_node->first_attribute("Operation")->value();
    std::cout << operacion << std::endl;
    std::cout << operacion << std::endl;
    if (operacion == "Upload") {
        parse_new_file((char *) to_return.str().c_str());
        return;
    }
    if (operacion == "Register") {
        parse_new_user((char *) to_return.str().c_str());
        return;
    }
    if (operacion == "Log") {
        std::cout << "LOOOOOG" << std::endl;

        parse_xml_request_log((char *) to_return.str().c_str());
        return;
    }
    if (operacion == "Songs") {
        return parse_song_requests((char *) to_return.str().c_str());

    }
    if (operacion == "Stream") {
        parse_chunk((char *) to_return.str().c_str());
        return;
    }
    if (operacion == "Chunk") {
        parse_chunk2((char *) to_return.str().c_str());
        return;
    }
    if (operacion == "Addfriend") {
parse_new_Friend((char*) to_return.str().c_str());
        return;
    }

    return;
}

void XML_handler::parse_chunk2(char *archivo) {
    xml_document<> doc;
    doc.parse<0>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    char *num = root_node->first_attribute("Chunk")->value();
    string str = string(num);

    int chunk = stoi(num);
    char *name = root_node->first_attribute("Filename")->value();
    char *archive = doc.allocate_string(Archive_manager::return_archive2(name, chunk));
    //  xml_node<>* child = doc.allocate_node(node_element, "Archive");
    root_node->append_attribute(doc.allocate_attribute("Data", archive));
    string cosas2 = to_string((*Archive_manager::filesize));
    char *cosas = doc.allocate_string(cosas2.c_str());
    root_node->append_attribute(doc.allocate_attribute("Filesize", cosas));
    //  root_node->append_node(child);
    std::stringstream ss;
    ss << doc;
    std::string result_xml = ss.str();
    // std::cout<<result_xml<<std::endl;
    Holder::odisea->send2(result_xml);

}

void XML_handler::parse_chunk(char *archivo) {
    xml_document<> doc;
    doc.parse<0>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    char *num = root_node->first_attribute("Chunk")->value();
    string str = string(num);
    int chunk = stoi(num);
    char *name = root_node->first_attribute("Filename")->value();
    char *archive = doc.allocate_string(Archive_manager::return_archive(name, chunk));
    //  xml_node<>* child = doc.allocate_node(node_element, "Archive");
    root_node->append_attribute(doc.allocate_attribute("Data", archive));
    //  root_node->append_node(child);
    std::stringstream ss;
    ss << doc;
    std::string result_xml = ss.str();
    std::cout << result_xml << std::endl;
    Holder::odisea->send2(result_xml);

}

void XML_handler::parse_new_file(char *archivo) {
    try {
        // std::cout << "llego" << archivo << std::endl;
        xml_document<> doc;
        doc.parse<0>(archivo);
        xml_node<> *root_node = doc.first_node("Root");
        xml_node<> *nodo = root_node->first_node("Archive");
        char *archive = nodo->first_attribute("File")->value();
        char *filename = nodo->first_attribute("Filename")->value();
        char *letra = root_node->first_attribute("Letra")->value();
        char *artista = root_node->first_attribute("Artista")->value();
        char *Album = root_node->first_attribute("Album")->value();

        string str = base64::base64_decode(archive);
        FILE *oFile;
        //std::cout << str << std::endl;
        oFile = fopen(filename, "wb");
        fwrite(str.c_str(), str.size(), 1, oFile);
        root_node->remove_first_node();
        root_node->append_attribute(doc.allocate_attribute("Result", "true"));
        std::stringstream ss;
        ss << doc;
        std::string result_xml = ss.str();
        std::cout << result_xml << std::endl;
        Factory::Cancion2(filename, Album, artista, letra, "");
        Holder::odisea->send2(result_xml);

    } catch (exception) {
        std::cout << "llego" << archivo << std::endl;
        xml_document<> doc;
        doc.parse<0>(archivo);
        xml_node<> *root_node = doc.first_node("Root");
        xml_node<> *nodo = root_node->first_node("Archive");
        char *archive = nodo->first_attribute("File")->value();
        char *filename = nodo->first_attribute("Filename")->value();
        string str = base64::base64_decode(archive);
        FILE *oFile;
        std::cout << str << std::endl;
        oFile = fopen(filename, "wb");
        fwrite(str.c_str(), str.size(), 1, oFile);
        doc.remove_node(nodo);
        root_node->append_attribute(doc.allocate_attribute("Result", "false"));
        std::stringstream ss;
        ss << doc;
        std::string result_xml = ss.str();
        std::cout << result_xml << std::endl;
        Holder::odisea->send2(result_xml);
    }
}

void XML_handler::parse_new_Friend(char *string) {

}
