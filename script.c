#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy_file(file1, file2, buffer, count)
{
    // Copying file1 to file2
    while ((count = read(file1, buffer, sizeof(buffer))) > 0)
    {
        write(file2, buffer, count);
    }

}

int main (int argc, char* argv[])
{   
    // Defining the variables
    char buffer[1024];
    FILE *file1, *file2, *report;
    ssize_t count;

    printf("Enter the size of the buffer: \n");
    scanf("%d", &buffer);

    // Opening file1 for reading
    file1 = fopen(argv[1], "r");
    if (file1 == NULL)
    {
        printf("Error file1 cannot be opened or doesn't exist.\n");
        exit(0);
    }

    // Opening file2 for writing
    file2 = fopen(argv[2], "w");
    if (file2 == NULL)
    {
        printf("Error file2 cannot be opened or doesn't exist.\n");
        exit(0);
    }
    
    // Calculating the time of the copying process
    clock_t t;
    t = clock();
    copy_file(file1, file2, buffer, count);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("The total time is: %d\n", time_taken);

    // Creating a report file to write the time taken
    report = fopen("report.out", "w");
    fprintf(report, "The total time is: %d\n", time_taken);

    // Closing the files
    fclose(file1);
    fclose(file2);
    fclose(report);

    return 0;
}