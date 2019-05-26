#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

//call a function that prints to 16 using forks

void print_fork(int len, int num);

int main(int argc, char ** argv){

    print_fork(13, 777);

}

void print_fork(int len, int num){

    pid_t pid;

    for(int i = 0; i < num; i++){
        pid = fork();
        //0 is the child!!!!!!
        if(pid == 0){
            for(int j = (i) * len/num; j < (i + 1) * len/num; j++){
                printf("%d\n ",j);
            }
        exit(0);
        }

    }
}


