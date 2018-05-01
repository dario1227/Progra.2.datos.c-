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
xml_document<>* XML_generator::create_Music_list(Lista<Cancion*> *canciones) {
    xml_document<>* doc = new xml_document<>() ;

    xml_node<>* decl = doc->allocate_node(node_declaration);
    decl->append_attribute(doc->allocate_attribute("version", "1.0"));
    decl->append_attribute(doc->allocate_attribute("encoding", "utf-8"));
    doc->append_node(decl);
    xml_node<>* root = doc->allocate_node(node_element, "Root");
    root->append_attribute(doc->allocate_attribute("Operation", "Music List"));

    Nodo<Cancion*>* actual = canciones->head;
    while(actual!= nullptr){
        create_music_helper(doc,root,actual->value);
        actual=actual->next;

    }
    doc->append_node(root);
    std::stringstream ss;
    ss <<(*doc);
    std::string result_xml = ss.str();
    ofstream file;
    file.open ("LOLA.txt");
    file << result_xml;
    file.close();
    std::cout <<result_xml<<std::endl;
    return doc;
}
void XML_generator::create_music_helper(xml_document<>* doc,xml_node<> *root, Cancion* cancion) {

    xml_node<>* child = doc->allocate_node(node_element, "Cancion");
    char *letra = doc->allocate_string(cancion->letra->toLatin1().data());
    char* calificacion = doc->allocate_string(std::to_string(cancion->calificacion).c_str());
    child->append_attribute(doc->allocate_attribute("Letra", letra));
    child->append_attribute(doc->allocate_attribute("Nombre", (const char*)cancion->nombre.c_str()));
    child->append_attribute(doc->allocate_attribute("Albun", (const char*)cancion->album.c_str()));
    child->append_attribute(doc->allocate_attribute("Calificacion",calificacion ));
    child->append_attribute(doc->allocate_attribute("Artista", (const char*)cancion->artista.c_str()));
    root->append_node(child);

}