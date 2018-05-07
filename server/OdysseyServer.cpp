//
// Created by dario1227 on 05/05/18.
//

#include <sys/socket.h>
#include "OdysseyServer.h"
#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include "Server.h"

#include <json-c/json_tokener.h>
#include <bits/signum.h>
#include <signal.h>
using namespace std;
void OdysseyServer::start() {
    /* SOCKET VARIABLES */
    int sock;
    struct sockaddr_in server;
     mysock;
    char buff[1024];
    int rval;


    /*CREATE SOCKET*/
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("*FAILED TO CREATE SOCKET*");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5700);

    /*CALL BIND*/
    if (bind(sock, (struct sockaddr *) &server, sizeof(server))) {
        perror("BIND FAILED");
        exit(1);
    }


    /*LISTEN*/
    listen(sock, 5);


    /*ACCEPT*/
    do {

        mysock = accept(sock, (struct sockaddr *) 0, 0);
        if (mysock == -1) {

            perror("ACCEPT FAILED");
        } else {
            memset(buff, 0, sizeof(buff));
            if ((rval = recv(mysock, buff, sizeof(buff), 0)) < 0)
                perror("READING STREAM MESSAGE ERROR");
            else if (rval == 0)
                printf("Ending connection");
            else
                printf("MSG: %s\n", buff);

            printf("GOT THE MESSAGE (rval = %d)\n", rval);
            string to_send = "MEME meme MEME";
            send(mysock,to_send.c_str(), to_send.length(),0);


        }

    } while (1);
}
void OdysseyServer::send2(string to_send) {

    send(mysock,to_send.c_str(), to_send.length(),0);
}
