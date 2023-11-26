#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "copy_files.h"
#include "make_report.h"

int main (int argc, char* argv[]){
    double speed;
    FILE *sf, *df;
    long fsize;
    char *src, *dest;
    int size = 0;

    get_buffer(argc, argv, &src, &dest, &size);

    // Calculating the time to copy the file
    clock_t t;
    t = clock();

    if(argc > 2){
    // open fileS
        sf = fopen(src, "rb");    
        df = fopen(dest, "wb");
    }
    // Calling the function to copy the files
    copy_files(sf, df, size);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    // Calculating the speed
    fsize = sizeof(sf);
    speed = (float) fsize/time_taken;
    printf("The copy speed is: %f Bytes/sec\n", speed);

    // Creating the report.out file
    make_report(speed);

    fclose(sf);
    fclose(df);

    return (0);
}