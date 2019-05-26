#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>

// main parent
int main_parent(int input, int output){
    puts("PARENT: just doing nothing, but happy about it");

    //We also need to open our input fd by using fdopen in read
    //NOTE ITS FDOPEN THIS IS A BIG GOTCHA
    FILE * fp = fdopen(input, "r");

    //Lets also make a buffer to store what we get from our input
    char buf[1024];

    //pretty sure memset works like this lmao probs gonna break
    memset(buf, 0, 1024);

    //We need a loop to check for input

    // //okay so in this case we have to repoen our output fd
    // //as stdout, I don't think you would do this in every case but we'll see
    // //will have to check that I can use any number for my file descriptor
    // //close stdout, which is normally described as 1
    // close(1);
    // //reopen our pipe output as stdout
    // dup(output);

    //input_text = fgets(buf, 10, fp);
    fread(buf,1024, 1,fp);
    // printf("initial input: %s\n", buf);
    char prev_buf[1024] = {'\0'};

    int i = 0;

    while(1){
        puts("PARENT: Waiting to read\n");
        if(i == 3) return 0;
        if(strlen(buf) == 0){
            sleep(2);
            i++;
            continue;
        }
        if(strcmp(prev_buf, buf) == 0){
            sleep(2);
            i++;
            continue;
        }
        printf("PARENT: Reading from child\n");
        fread(buf,1024, 1,fp);
        printf("buf: %s\n", buf);
        strcpy(prev_buf, buf);
        i++;
        sleep(2);
    }    
    //Generate random number to decide if we want to play
    time_t t;
    srand((unsigned) time(&t));
    int randnum = (rand() % 3) + 1;
    printf("%d\n",randnum);

    return 0;
}

//main child
int main_child(int input, int output){
    puts("CHILD: I'm bored and want to do something");

    //We also need to open our input fd by using fdopen in read
    //NOTE ITS FDOPEN THIS IS A BIG GOTCHA
   //FILE * fp = fdopen(input, "r");

    puts("CHILD: I want to play scissors paper rock!");
    //Ask parent to play a game
    char game[1024] = "game";
    write(output, game, strlen(game) + 1);

    //Lets also make a buffer to store what we get from our input
    char buf[1024];

    //pretty sure memset works like this lmao probs gonna break
    memset(buf, 0, 1024);

    //We need a loop to check for input
    int i = 0;

    while(1){
        int randnum = (rand() % 3);
        char choose[3][20] = {"rock", "paper", "scissors"};
        char * choice = choose[randnum];
        printf("CHILD: %s!\n", choice);
        write(output, (void *)choice, 1024);
        i++;
        if(i == 3) return 0;
        sleep(3);
    } 

    return 0;
}

int main(int argc, char** argv){

    //define file descriptors we use as input/output for our forks
    //they are just arrays of ints, size 2

    int p_to_child[2];
    int c_to_parent[2];

    //use pipe on our file descriptors, this sets them up as conduits to send data
    //also check if piping failed, check if calling pipe on each fd returns < 0

    if(pipe(p_to_child) < 0 || pipe(c_to_parent) < 0){
        puts("piping failed");
    }

    //Then we fork
    pid_t pid = fork();
    //Defensively check forking worked
    if(pid < 0){ 
        puts("fork failed");
    }

    //If pid 0 we're in the child
    if(pid == 0){
        //We want to close the file descriptors we aren't using, not sure why
        close(c_to_parent[0]);
        close(p_to_child[1]);
        return main_child(p_to_child[0], c_to_parent[1]);
    } else{
        close(p_to_child[0]);
        close(c_to_parent[1]);
        return main_parent(c_to_parent[0], p_to_child[1]);
    }

    return 0;
    }