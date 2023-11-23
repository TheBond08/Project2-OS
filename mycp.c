#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>


int main (int argc, char **argv){
    int sf, df, size;
    char buf[size];
    FILE *report;
    double fsize, speed;

    scanf("%lu", size);

    if (size < 0){
        perror("Reading error:");
        exit(1);
    }

    // Checking for errors in the files
    if((sf = open(argv[1], O_RDONLY)) < 0){
        perror("Error opening source file:");
        exit(1);
    }

    if((df = open(argv[2], O_WRONLY | O_CREAT, 0600)) < 0){
        perror("Error opening destination file:");
        exit(1);
    }

    // Calculating the time to copy the file
    clock_t t;
    t = clock();
    read(sf, buf, size);
    write(df, buf, size);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    // Calculating the speed
    fsize = sizeof(sf);
    speed = fsize/time_taken;
    printf("The copy speed is: %f MB/s\n", speed);

    // Creating the report.out file
    report = fopen("report.out", "w");
    fprintf(report, "The copy speed is: %f B/s\n", speed); 
    fclose(report);

    close(sf);
    close(df);
}