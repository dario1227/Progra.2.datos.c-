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

/**
 * Metodo para parsear metodo de canciones
 * @param archive
 */
void XML_handler::parse_song_requests(char *archive) {
    xml_document<> doc;
    doc.parse<0>(archive);
    xml_node<> *root_node = doc.first_node("Root");
    char* metodo = root_node->first_attribute("Method")->value();
    if(metodo=="Autor"){
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion*>* lista = new Lista<Cancion*>();
        xml_document<>* documento = XML_generator::create_Music_list(lista);
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        char* variable =(char*) result_xml.c_str();
    }
    if(metodo=="Album"){
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion*>* lista = new Lista<Cancion*>();
        xml_document<>* documento = XML_generator::create_Music_list(lista);
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        char* variable =(char*) result_xml.c_str();
    }
    if(metodo=="Artista"){
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion*>* lista = new Lista<Cancion*>();
        xml_document<>* documento = XML_generator::create_Music_list(lista);
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        char* variable =(char*) result_xml.c_str();
    }
    if(metodo=="Letra"){
        //debe cambiar a metodos de busqueda ahi
        Lista<Cancion*>* lista = new Lista<Cancion*>();
        xml_document<>* documento = XML_generator::create_Music_list(lista);
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        char* variable =(char*) result_xml.c_str();
    }

}
void XML_handler::parse_xml_request_log(char *archive) {
    xml_document<> doc;
    doc.parse<parse_full>(archive);
    xml_node<> *root_node = doc.first_node("Root");
    xml_node<>* user = root_node->first_node("User");
    string name = user->first_attribute("Name")->value();
    char* password = user->first_attribute("Password")->value();
    User *usuario = Data_Holder::users->search("kenneth");
    std::cout<<name<<std::endl;
    if(usuario== nullptr){
        root_node->append_attribute(doc.allocate_attribute("Result","false"));
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        std::cout<<result_xml<<std::endl;
        Holder::odisea->send2(result_xml);
        return;
    }
    if(usuario->password==password){
        std::cout<<"WHY IM HERE PASSWORD"<<std::endl;

        root_node->append_attribute(doc.allocate_attribute("Result","true"));
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        Holder::odisea->send2(result_xml);

        return;
    }
    else{
        std::cout<<"WHY IM HERE NO PASSWORD"<<std::endl;
        root_node->append_attribute(doc.allocate_attribute("Result","false"));
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        Holder::odisea->send2(result_xml);

        return;
    }
}
void XML_handler::parse_new_user(char *archive) {
    xml_document<> doc;
    doc.parse<0>(archive);
    xml_node<> *root_node = doc.first_node("Root");
    xml_node<>* user = root_node->first_node("User");
    char* name = user->first_attribute("Name")->value();
    char* age = user->first_attribute("Age")->value();
    char* id = user->first_attribute("ID")->value();
    char* password = user->first_attribute("Password")->value();
    if (Data_Holder::users->search(name)!= nullptr){
        root_node->append_attribute(doc.allocate_attribute("Result","false"));
        std::stringstream ss;
        ss <<doc;
        std::string result_xml = ss.str();
        std::cout<<result_xml<<std::endl;
        Holder::odisea->send2(result_xml);
        return;
    }
    root_node->append_attribute(doc.allocate_attribute("Result","true"));
    std::stringstream ss;
    ss <<doc;
    std::string result_xml = ss.str();
    std::cout<<result_xml<<std::endl;
    Holder::odisea->send2(result_xml);
    new User(name,age,id,password);


}
void XML_handler::primary_handler(char *archivo) {
    std::stringstream to_return ;
    to_return<<archivo;
    xml_document<> doc;
    doc.parse<0>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    string operacion = root_node->first_attribute("Operation")->value();
    std::cout<<operacion<<std::endl;
    std::cout<< (operacion=="Log") <<std::endl;
    if(operacion=="Upload"){
        parse_new_file(archivo);
        return;
    }
    if(operacion=="Register"){
        parse_new_user((char*)to_return.str().c_str());
        return;
    }
    if (operacion=="Log"){
        std::cout<<"LOOOOOG"<<std::endl;

        parse_xml_request_log((char*)to_return.str().c_str());
        return;
    }
    if(operacion=="Songs"){
        parse_song_requests(archivo);
        return;
    }
    if(operacion=="Stream"){
        parse_chunk(archivo);
        return;
    }

    return;
}
void XML_handler::parse_chunk(char *archivo) {
    xml_document<> doc;
    doc.parse<0>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    char* num = root_node->first_attribute("Chunk")->value();
    string str = string(num);
    int chunk = stoi(num);
    char* name = root_node->first_attribute("Filename")->value();
    char* archive = doc.allocate_string(Archive_manager::return_archive(name,chunk));
    xml_node<>* child = doc.allocate_node(node_element, "Archive");
    child->append_attribute(doc.allocate_attribute("Data",archive));
    root_node->append_node(child);

}

void XML_handler::parse_new_file(char *archivo) {
std::cout<<"llego"<<archivo<<std::endl;
    xml_document<> doc;
    doc.parse<0>(archivo);
    xml_node<> *root_node = doc.first_node("Root");
    xml_node<>* nodo = root_node->first_node("Archive");
    char* archive = nodo->first_attribute("File")->value();
    string str = base64::base64_decode(archive);
    FILE* oFile;
    std::cout<<str<<std::endl;
    oFile = fopen ( "SALVADO.mp3" , "wb" );
    fwrite(str.c_str(), str.size(),1,oFile);

}
