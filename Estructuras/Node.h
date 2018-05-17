//
// Created by kenneth on 4/27/18.
//

#ifndef PROGRA_2_DATOS_C_NODE_H
#define PROGRA_2_DATOS_C_NODE_H

#include <iostream>
#include "../data/User.h"

using namespace std;
class Node {
public:
    User* usuario= nullptr;
    string data;
    Node* left= nullptr;
    Node* right= nullptr;

    Node(User* usuario2,string datos){
        data=datos;
        usuario=usuario2;
        left= nullptr;
        right=nullptr;
    }
};


#endif //PROGRA_2_DATOS_C_NODE_H
