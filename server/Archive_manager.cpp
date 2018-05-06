//
// Created by kenneth on 5/4/18.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Archive_manager.h"
#include "../data/base64.h"

char* Archive_manager::return_archive(char *filename, int chunk) {
    std::cout<<filename<<std::endl;

    FILE * iFile, * oFile;
    long lSize;
    char * buffer;
    size_t result;

    iFile = fopen ( filename , "rb" );
    if (iFile==NULL) {fputs ("File error",stderr); }

    oFile = fopen ( "LOLA.mp3" , "wb" );
    if (oFile==NULL) {fputs ("File error",stderr); }


    fseek (iFile , 0 , SEEK_END);
    lSize = ftell (iFile);
    rewind (iFile);


    buffer = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL) {fputs ("Memory error",stderr); }
    long chunksize = lSize*0.02;

    result = fread (buffer,1,lSize,iFile);
 char* pedazo = Archive_manager::divide_chunk(buffer,chunksize,chunksize*chunk,chunksize*chunk+chunksize);
 std::string* parseado = new std::string(base64::base64_encode(reinterpret_cast<const unsigned char *>(pedazo), chunksize).c_str());
 std::cout<<"ME DIOO ESTO"<<parseado<<std::endl;
    return const_cast<char *>(parseado->c_str());
}
char* Archive_manager::divide_chunk(char *archive, long chunksize, long limit1, long limit2) {
    char* buffer = new char[chunksize];
    int x =0;
    while(x<chunksize){
        buffer[x]=archive[limit1+x];
        x++;
    }
    return buffer;
}