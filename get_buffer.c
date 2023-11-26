#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_buffer.h"


int get_buffer(int argc, char *argv[], int *src, int *dst, int *size){
    
    if(argc == 4 && strncmp(argv[1], "-b", 2) == 0 ){
        *size = atoi(argv[1] + 2);
    } else if(argc > 4 ||(argc == 4 && strncmp(argv[1], "-b", 2)!= 0)){
        perror("invalid option");
        return 1;
    }

    *src = argv[argc - 2];
    *dst = argv[argc - 1];

    return 0;
}