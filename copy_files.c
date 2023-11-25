#include "copy_files.h"


int copy_files(int argc, char **argv){
    int sf, df, size = 0;
    char *buf = (char *)malloc(size * sizeof(char));

    // Inputs the buffer size
    if(scanf("%d", &size) <= 0){
        perror("Error invalid buffer size");
        return 1;
    }

    if(argc >= 2){ 
        // Checking for errors
        if((sf = open(argv[1], O_RDONLY)) < 0){
            perror("Error opening source file:");
            exit(1);
        }

        if((df = open(argv[2], O_WRONLY | O_CREAT, 0600)) < 0){
            perror("Error opening destination file:");
            exit(1);
        }

    }

    // Copying the file
    read(sf, buf, size);
    write(df, buf, size);

    close(sf);
    close(df);


    return sf;
}