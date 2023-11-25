#include "make_report.h"

void make_report(double speed){
    FILE *report;

    // Writing the speed to the file
    report = fopen("report.out", "w");
    fprintf(report, "The copy speed is: %f Bytes/sec\n", speed); 
    fclose(report);

}