#include "copy_files.h"




int copy_files(FILE *sf, FILE *df, int size){
    int c;

    if (size > 0 )
    {
        char *buf = (char *)malloc(size * sizeof(char));
        if (buf == NULL){
            printf("Memory allocation failed\n");
            fclose(sf);
            fclose(df);
            exit (3);
        }
        // Copying with buffer
        size_t cread;
        while ((cread = fread(buf, sizeof(char), size, sf)) > 0){
            fwrite(buf, sizeof(char), cread, df);
        }
        free(buf);
    } else if(size < 0){
        printf("Invalid buffer size\n");
        fclose(sf);
        fclose(df);
        exit (3);
    } else {
        // Copying without buffer
        while ((c = fgetc(sf)) != EOF)
        {
            fputc(c, df);
        }
        
    }

    return 0;
}