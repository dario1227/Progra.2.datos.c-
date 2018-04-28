//
// Created by kenneth on 4/27/18.
//

#ifndef PROGRA_2_DATOS_C_DATA_PARSER_H
#define PROGRA_2_DATOS_C_DATA_PARSER_H


#include <json-c/json_object.h>

class Data_parser {
public:
    static void read_users();
    static void append_user(json_object* object);


};


#endif //PROGRA_2_DATOS_C_DATA_PARSER_H
