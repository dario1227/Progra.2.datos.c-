//
// Created by dario1227 on 05/05/18.
//

#ifndef PROGRA_2_DATOS_C_ODYSSEYSERVER_H
#define PROGRA_2_DATOS_C_ODYSSEYSERVER_H

#include <iostream>

using namespace std;

class OdysseyServer {
public:
    char buffer[10000000];
    int mysock;

    void start();

    bool isXML(char *files);
/**
 * Envia un archivo xml
 * @param to_send
 */
    void send2(string to_send);

    void receiveFile();
};


#endif //PROGRA_2_DATOS_C_ODYSSEYSERVER_H
