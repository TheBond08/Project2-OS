#include "copy_files.h"


int copy_files(int argc, char **argv){
    int sf, df, size=512;
    char buf[size];

    //Checking for erros
    if((sf = open(argv[1], O_RDONLY)) < 0){
        perror("Error opening source file:");
        exit(1);
    }

    if((df = open(argv[2], O_WRONLY | O_CREAT, 0600)) < 0){
        perror("Error opening destination file:");
        exit(1);
    }

    read(sf, buf, size);
    write(df, buf, size);

    close(sf);
    close(df);

    return sf;
}