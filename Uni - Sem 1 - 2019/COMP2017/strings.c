#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv){
    printf"type your name:\n");
    char * myName;
    fgets(myName, 10, stdin);
    printf("your name is: \n");
    putchar(myName);
    return 0;

    int * ptr;
    ptr = (int *)malloc(sizeof(int)*20);
}