#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "copy_files.h"
#include "make_report.h"
#include "get_buffer.h"

#define INCORRECT_NUMBER_OF_ARGUMENTS 1
#define UNABLE_TO_OPEN_FILE 2


int main (int argc, char* argv[]){
    double speed;
    FILE *sf, *df;
    long fsize;
    char *src, *dest;
    int size = 0;

    // Calls function to get the file paths depending on the input of buffer size
    get_buffer(argc, argv, &src, &dest, &size);


    if(argc <=1){
        perror("Usage:mycp -b[number] source_file destination_file\n");
        exit (1);
    }

    if(argc > 2){
    // Opening files
        if((sf = fopen(src, "rb")) == NULL){
            perror("Error opening source file\n");
            exit(2);
        }   
        if((df = fopen(dest, "wb")) == NULL){
            perror("Error opening destination file\n");
            exit(2);
        };
    }

    // Calculating the time to copy the file
    clock_t t;
    t = clock();

    // Calling the function to copy the files
    if(copy_files(sf, df, size) != 0){
        return EXIT_FAILURE;
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    // Getting the size of the file
    fseek(sf, 0, SEEK_END);
    fsize = ftell(sf);
    rewind(sf);

    // Calculating the speed
    speed = (float) fsize/time_taken;
    printf("The copy speed is: %f Bytes/sec\n", speed);

    // Creating the report.out file
    make_report(speed);

    fclose(sf);
    fclose(df);

    return (0);
}