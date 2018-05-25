//
// Created by kenneth on 5/4/18.
//

#ifndef PROGRA_2_DATOS_C_ARCHIVE_MANAGER_H
#define PROGRA_2_DATOS_C_ARCHIVE_MANAGER_H


class Archive_manager {
public:
    static char* return_archive(char* filename, int chunk);
    static char* divide_chunk(char* archive, long chunksize, long limit1, long limit2);

    static const char *return_archive2(char *name, int chunk);

    static char *divide_chunk2(char *buffer, long chunksize, long i, long i1);
};


#endif //PROGRA_2_DATOS_C_ARCHIVE_MANAGER_H
