#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


//call a function that prints to 16 using forks

struct my_struct {
    char buf[1024];
};

void print_text(char * filename, void * stuff);

void signal_function(){
    printf("i got a signal");
}

int main(int argc, char ** argv){

    struct my_struct * stuff = (struct my_struct *)malloc(sizeof(struct my_struct));
    print_text("text.txt", stuff);

    //puts(" in main");
   // printf("%s\n", stuff->buf);


    free(stuff);
}

void print_text(char * filename, void * stuff){
    int p_to_child[2];
    int c_to_parent[2];
    struct my_struct * contents = (struct my_struct * )stuff;
    FILE * fp;
    fp = fopen(filename, "r");
    //size_t size = ftell(fp);
    rewind(fp);
    fread(contents->buf,1024, 1, fp);
    //fgets(buf, 1024, fp);
    //puts(" in function");
   // printf("%s\n", contents->buf);
    signal(SIGINT, signal_function);

    for(int i = 0; i < 3; i++){
        pid_t pid;
        pid = fork();
        if(pid == 0){
            printf("Letter at index %d is: %c\n", i, contents->buf[i]);
            exit(0);
        }
    }
}