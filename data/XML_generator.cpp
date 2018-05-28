//
// Created by kenneth on 4/30/18.
//

#include <sstream>
#include <fstream>
#include "XML_generator.h"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

int XML_generator::index = 0;

xml_document<> *XML_generator::create_Music_list(Lista<Cancion *> *canciones, int pagina) {
    int index = 0;
    xml_document<> *doc = new xml_document<>();
    int page = pagina * 5 - 5;
    int limite = pagina * 5;

    xml_node<> *decl = doc->allocate_node(node_declaration);
    decl->append_attribute(doc->allocate_attribute("version", "1.0"));
    decl->append_attribute(doc->allocate_attribute("encoding", "utf-8"));
    doc->append_node(decl);
    xml_node<> *root = doc->allocate_node(node_element, "Root");
    root->append_attribute(doc->allocate_attribute("Operation", "Music List"));
    root->append_attribute(doc->allocate_attribute("Result", "true"));
    Nodo<Cancion *> *actual = canciones->head;
    while (actual != nullptr && index != page) {
        actual = actual->next;
        index++;
    }
    while (actual != nullptr && index < limite) {
        index++;
        create_music_helper(doc, root, actual->value);
        actual = actual->next;
        int x = 23;
    }
    doc->append_node(root);
    std::stringstream ss;
    ss << (*doc);
    std::string result_xml = ss.str();
    ofstream file;
    file.open("LOLA.txt");
    file << result_xml;
    file.close();
    std::cout << result_xml << std::endl;
    return doc;
}

xml_document<> *XML_generator::create_Music_list2(Lista<Cancion *> *canciones) {
    xml_document<> *doc = new xml_document<>();

    xml_node<> *decl = doc->allocate_node(node_declaration);
    decl->append_attribute(doc->allocate_attribute("version", "1.0"));
    decl->append_attribute(doc->allocate_attribute("encoding", "utf-8"));
    doc->append_node(decl);
    xml_node<> *root = doc->allocate_node(node_element, "Root");
    root->append_attribute(doc->allocate_attribute("Operation", "Music List"));
    Nodo<Cancion *> *actual = canciones->head;
    while (actual != nullptr) {
        create_music_helper(doc, root, actual->value);
        actual = actual->next;

    }
    doc->append_node(root);
    std::stringstream ss;
    ss << (*doc);
    std::string result_xml = ss.str();
    ofstream file;
    file.open("LOLA.txt");
    file << result_xml;
    file.close();
    std::cout << result_xml << std::endl;
    return doc;
}

xml_document<> *XML_generator::create_Music_list3(Lista<Cancion *> *canciones) {
    xml_document<> *doc = new xml_document<>();

    xml_node<> *decl = doc->allocate_node(node_declaration);
    decl->append_attribute(doc->allocate_attribute("version", "1.0"));
    decl->append_attribute(doc->allocate_attribute("encoding", "utf-8"));
    doc->append_node(decl);
    xml_node<> *root = doc->allocate_node(node_element, "Root");
    root->append_attribute(doc->allocate_attribute("Operation", "Music List"));

    Nodo<Cancion *> *actual = canciones->head;
    while (actual != nullptr) {
        create_music_helper(doc, root, actual->value);
        actual = actual->next;

    }
    doc->append_node(root);
    std::stringstream ss;
    ss << (*doc);
    std::string result_xml = ss.str();
    ofstream file;
    file.open("LOLA.txt");
    file << result_xml;
    file.close();
    std::cout << result_xml << std::endl;
    return doc;
}

void XML_generator::create_music_helper(xml_document<> *doc, xml_node<> *root, Cancion *cancion) {

    xml_node<> *child = doc->allocate_node(node_element, "Cancion");
    char *letra = doc->allocate_string(cancion->letra->toLatin1().data());
    char *calificacion = doc->allocate_string(std::to_string(cancion->calificacion).c_str());
    char *nombre = doc->allocate_string(cancion->nombre.c_str());
    char *album = doc->allocate_string(cancion->album.c_str());
    char *artista = doc->allocate_string(cancion->artista.c_str());

    child->append_attribute(doc->allocate_attribute("Letra", letra));
    child->append_attribute(doc->allocate_attribute("Nombre", nombre));
    child->append_attribute(doc->allocate_attribute("Album", album));
    child->append_attribute(doc->allocate_attribute("Calificacion", calificacion));
    child->append_attribute(doc->allocate_attribute("Artista", artista));
    root->append_node(child);

}