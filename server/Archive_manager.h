//
// Created by kenneth on 5/4/18.
//

#ifndef PROGRA_2_DATOS_C_ARCHIVE_MANAGER_H
#define PROGRA_2_DATOS_C_ARCHIVE_MANAGER_H

using namespace std;

class Archive_manager {
public:
    static long *filesize;
/**
 * Retorna todos los bytes de un archivo
 * @param filename
 * @param chunk
 * @return
 */
    static char *return_archive(char *filename, int chunk);

    static char *divide_chunk(char *archive, long chunksize, long limit1, long limit2);
/**
 * divide el archivo en pendazos
 * @param name
 * @param chunk
 * @return
 */
    static const char *return_archive2(char *name, int chunk);

    static char *divide_chunk2(char *buffer, long chunksize, long i, long i1);
};


#endif //PROGRA_2_DATOS_C_ARCHIVE_MANAGER_H
