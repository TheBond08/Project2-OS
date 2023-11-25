#include "copy_files.h"


int copy_files(int argc, char **argv){
    int sf, df, size = 2000;
    char *buf = (char *)malloc(size * sizeof(char));


    // Checking for errors
    if((sf = open(argv[1], O_RDONLY)) < 0){
        perror("Error opening source file:");
        exit(1);
    }

    if((df = open(argv[2], O_WRONLY | O_CREAT, 0600)) < 0){
        perror("Error opening destination file:");
        exit(1);
    }

    size_t bytesRead;
    while ((bytesRead = fread(buf, sizeof(char), size, sf)) > 0) {
        fwrite(buf, sizeof(char), bytesRead, df);
    }

    // Copying the file
    //read(sf, buf, size);
    //write(df, buf, size);

    close(sf);
    close(df);

    free(buf);

    return sf;
}