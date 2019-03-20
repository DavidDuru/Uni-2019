#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv){
    int *p;
    printf("%p\n", p);
    printf("%p\n", p + 1);
    printf();
    return EXIT_SUCCESS;
}