#include "make_report.h"

void make_report(speed){
    FILE *report;

    report = fopen("report.out", "w");
    fprintf(report, "The copy speed is: %f Bytes/sec\n", speed); 
    fclose(report);

}