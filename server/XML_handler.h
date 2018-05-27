//
// Created by kenneth on 4/30/18.
//

#ifndef PROGRA_2_DATOS_C_XML_HANDLER_H
#define PROGRA_2_DATOS_C_XML_HANDLER_H

#include "../data/rapidxml.hpp"

using namespace rapidxml;

class XML_handler {
public:
    //
    static void parse_xml_request_log(char *archive);

    static void parse_song_requests(char *archive);

    static void parse_new_user(char *archive);

    static void primary_handler(char *archivo);

    static void parse_chunk(char *archivo);

    static void parse_new_file(char *archivo);

    static void edit_songdata(char *archivo);

    static void parse_chunk2(char *archivo);
};


#endif //PROGRA_2_DATOS_C_XML_HANDLER_H
