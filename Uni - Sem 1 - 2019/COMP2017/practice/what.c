#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void allocate_memory(int * num2);

int main(int argc, char ** argv){
    //Mallocing in main
    int * num1 = (int *)malloc(sizeof(int));
    printf("num1 at %p\n", num1);
    *num1 = 5;
    printf("num1 holds %d\n", *num1);

    //Mallocing from another function
    int * num2 = NULL;
    allocate_memory(num2);
    printf("num2 at %p\n", num2);
    printf("num2 holds %d\n", *num2);
}

void allocate_memory(int * num2){
    int * num3 = (int *)malloc(sizeof(int));
    *num3 = 10;
    memcpy(num2,num3,sizeof(int));
}