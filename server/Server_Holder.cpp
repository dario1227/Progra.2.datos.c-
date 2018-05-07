//
// Created by kenneth on 5/6/18.
//

#include "Server_Holder.h"
#include "../data/JsonFactory.h"

OdysseyServer *Server_Holder::servidor = nullptr;
void Server_Holder::start() {
    JsonFactory::read();
    servidor = new OdysseyServer;
    servidor->start();
}