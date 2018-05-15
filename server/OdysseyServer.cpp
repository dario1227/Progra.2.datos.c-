//
// Created by dario1227 on 05/05/18.
//

#include <sys/socket.h>
#include "OdysseyServer.h"
#include <iostream>
#include <netinet/in.h>
#include <cstring>
#include "Server.h"
#include "Archive_manager.h"
#include "XML_handler.h"

#include <json-c/json_tokener.h>
#include <bits/signum.h>
#include <signal.h>
#include <zconf.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sstream>

using namespace std;
void OdysseyServer::start() {
    /* SOCKET VARIABLES */
    int sock;
    struct sockaddr_in server;
     mysock;
    char buff[7000000];
    int rval;


    /*CREATE SOCKET*/
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("*FAILED TO CREATE SOCKET*");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5400);

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
            memset(buff, 0, 7000000);
            if ((rval = recv(mysock, buff, 7000000, 0)) < 0)
                perror("READING STREAM MESSAGE ERROR");
            else if (rval == 0)
                printf("Ending connection");
            else
                printf("MSG: %s\n", "LOL");

               // XML_handler::parse_new_file(buff);
            printf("GOT THE MESSAGE (rval = %d)\n", rval);
            string sendd=Archive_manager::return_archive("/home/kenneth/Desktop/Tool - H. w Lyrics (HD).mp3", 0) ;
            sendd.append("#");
                send(mysock,sendd.c_str(), sendd.length(), 0);
            usleep(1);
            memset(buff, 0, 7000000);
            receiveFile();
            std::cout<<"Algun buffer"<<buff<<std::endl;
        }

    } while (1);
}
void OdysseyServer::send2(string to_send) {

    send(mysock,to_send.c_str(), to_send.length(),0);

}
void OdysseyServer::receiveFile() {
    usleep(100000);
    int x = 0;
    std::stringstream to_return ;
    while(true) {
        std::cout<<"cosa"<<std::endl;
        std::cout<<((to_return).str().back())<<std::endl;
        recv(mysock, buffer, 7000000, 0);
        std::cout<<buffer<<std::endl;
        to_return<<buffer;
        std::cout<<"??????????????????????????????????"<<std::endl;
        std::cout<<(to_return.str())<<std::endl;
        memset(buffer, 0, 7000000);
        int x;
        ioctl(mysock,FIONREAD,&x);
        std::cout<<x<<std::endl;
       // std::cout<<*to_return<<std::endl;
        if(isXML((char*)to_return.str().c_str())){
            break;
        }
    }
    //std::cout<<*to_return<<std::endl;
    xml_document<> doc;
    char* cosa = doc.allocate_string(to_return.str().c_str());
    XML_handler::parse_new_file(cosa);
    return;
}
bool OdysseyServer::isXML(char *files) {
    std::cout<<files<<std::endl;
    try{

        xml_document<> doc;
        doc.parse<0>(files);
        std::cout<<"LLEVO"<<std::endl;
        return true;
    }catch(parse_error error){
        std::cout<<"ERROR AHI"<<std::endl;
        return false;
    }
}