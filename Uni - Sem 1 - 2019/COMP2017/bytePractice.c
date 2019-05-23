#include<stdio.h>
#include<stdlib.h>

void printBytes(int * num);

int main(int argv, char ** argc){

int a = 10;
printBytes(&a);

}

void printBytes(int * num){
    //printf("%d\n", *num);
    for(int i = 0; i < sizeof(int); i ++){
        printf("[%d]", ((char *)(num))[i]);
    }
    
}