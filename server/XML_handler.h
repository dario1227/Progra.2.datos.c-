//
// Created by kenneth on 4/30/18.
//

#ifndef PROGRA_2_DATOS_C_XML_HANDLER_H
#define PROGRA_2_DATOS_C_XML_HANDLER_H

#include "../data/rapidxml.hpp"

using namespace rapidxml;

class XML_handler {
public:
    /**
     * Recibe el archivo para hacer login
     * @param archive
     */
    static void parse_xml_request_log(char *archive);

/**
 * parsea lo que se refiere con obtener canciones
 * @param archive
 */
    static void parse_song_requests(char *archive);

/**
 * hace el register
 * @param archive
 */
    static void parse_new_user(char *archive);

/**
 * Es el que deriva las acciones a los demas
 * @param archivo
 */
    static void primary_handler(char *archivo);

/**
 * Parsea un file completo
 * @param archivo
 */
    static void parse_chunk(char *archivo);

/**
 * anade a la lista y guarda un archivo
 * @param archivo
 */
    static void parse_new_file(char *archivo);

    static void edit_songdata(char *archivo);

/**
 * Parsea por chunks
 * @param archivo
 */
    static void parse_chunk2(char *archivo);

/**
 * anade a los nuevos amigos
 * @param string
 */
    static void parse_new_Friend(char *string);
};


#endif //PROGRA_2_DATOS_C_XML_HANDLER_H
