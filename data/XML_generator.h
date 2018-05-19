//
// Created by kenneth on 4/30/18.
//

#ifndef PROGRA_2_DATOS_C_XML_GENERATOR_H
#define PROGRA_2_DATOS_C_XML_GENERATOR_H

#include "rapidxml.hpp"
#include "../Estructuras/Lista.h"
#include "Cancion.h"

using namespace rapidxml;
using namespace std;
class XML_generator {
public:
    static int index;
    static xml_document<>* create_Music_list(Lista<Cancion*> *canciones,int co);

    static void create_music_helper(xml_document<>*,xml_node<>* root,Cancion *cancion);

    xml_document<> *create_Music_list3(Lista<Cancion *> *canciones);

    xml_document<> *create_Music_list2(Lista<Cancion *> *canciones);
};


#endif //PROGRA_2_DATOS_C_XML_GENERATOR_H
