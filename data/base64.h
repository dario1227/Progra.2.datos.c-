//
// Created by kenneth on 5/3/18.
//

#ifndef PROGRA_2_DATOS_C_BASE64_H
#define PROGRA_2_DATOS_C_BASE64_H

#include <string>
//
class base64 {
public:
    static std::string base64_decode(std::string const& s);


    static std::string base64_encode(unsigned char const* , unsigned int len);
};


#endif //PROGRA_2_DATOS_C_BASE64_H
