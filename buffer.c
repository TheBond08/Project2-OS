#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;    

    printf("Enter buffer size: ");
    scanf("%d",&size);

    char *buf = (char *)malloc(size * sizeof(char));

    if (buf == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
        

}