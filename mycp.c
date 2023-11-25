#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "copy_files.h"
#include "make_report.h"

int main (){
    double fsize, speed;
    int sf;

    // Calculating the time to copy the file
    clock_t t;
    t = clock();
    // Calling the function to copy the files
    copy_files();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    // Calculating the speed
    fsize = sizeof(sf);
    speed = (float) fsize/time_taken;
    printf("The copy speed is: %f Bytes/sec\n", speed);

    // Creating the report.out file
    make_report(speed);

    return (0);
}