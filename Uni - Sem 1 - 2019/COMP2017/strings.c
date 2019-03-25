#include<stdlib.h>
#include<stdio.h>

int main(void){
    char name[3];
    fgets(name,3,stdin);
    printf("Name: ");
    puts(name);
    return 0;
}