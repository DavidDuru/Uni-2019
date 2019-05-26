#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    printf("output 1: %d\n", getpid());
    
    while(fork() == 0){
        printf("i am the child\n");
        sleep(1);
    }
    return 0;
}