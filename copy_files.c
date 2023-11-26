#include "copy_files.h"


int copy_files(FILE *sf, FILE *df, int size){
    int c;

    if (size > 0)
    {
        // Copying with buffer
        char *buf = (char *)malloc(size * sizeof(char));
        size_t cread;
        while ((cread = fread(buf, sizeof(char), size, sf)) > 0){
            fwrite(buf, sizeof(char), cread, df);
        }
        free(buf);
    } else {
        // Copying without buffer
        while ((c = fgetc(sf)) != EOF)
        {
            fputc(c, df);
        }
        
    }

    return 0;
}