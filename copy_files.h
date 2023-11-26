#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define SUCCESS 0
#define UNABLE_TO_ALLOCATE_MEMORY 3

int copy_files(FILE *sf, FILE *df, int size);