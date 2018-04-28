//
// Created by kenneth on 4/27/18.
//


#include <bits/signum.h>
#include <signal.h>
#include <netinet/in.h>
#include <cstring>
#include "iostream"
#include "exception"
#include <iostream>
#include "Server.h"
#include <bits/signum.h>
#include <signal.h>
void Server::initialize_connection() {
    int client;
    int server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    struct sockaddr_in server_addr;
    socklen_t size;
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        std::cout << "\nError establishing socket..." << std::endl;
        exit(1);
    }
    std::cout << "\n=> Socket server has been created..." << std::endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);
    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        std::cout << "=> Error binding connection, the socket has already been established..." << std::endl;
        return ;
    }
    size = sizeof(server_addr);
    std::cout << "=> Looking for clients..." << std::endl;
    listen(client, 1);
    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);
    if (server < 0)
        std::cout << "=> Error on accepting..." << std::endl;
    int counter = 0;
    while (server > 0)
    {
        counter++;
        try {
            if (counter == 0) {
                strcpy(buffer, "=> Server connected...\n");
                counter++;
//
                send(server, "Connect", bufsize, 0);
                std::cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << std::endl;
                std::cout << "\n=> Enter # to end the connection\n" << std::endl;
            }
            recv(server, buffer, bufsize, 0);
            if (buffer == nullptr || sizeof(buffer) == 0) {
                return;
            }


        }catch(std::exception e){
            return;
        }

    }
}