//
// Created by dario1227 on 05/05/18.
//

#ifndef PROGRA_2_DATOS_C_ODYSSEYSERVER_H
#define PROGRA_2_DATOS_C_ODYSSEYSERVER_H

#include <iostream>

using namespace std;
class OdysseyServer {
public:
    int mysock;
 void start();
 void send2(string to_send);
};


#endif //PROGRA_2_DATOS_C_ODYSSEYSERVER_H
