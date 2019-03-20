#include<stdio.h>
#include<stdlib.h>
//argc: count of the number of arguments
//char ** argv pointer, char ** is a pointer to a string

int main(int argc, char ** argv){
    //stupid way, get all args
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }
    //smart way
    printf("\n");
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    return EXIT_SUCCESS;
}