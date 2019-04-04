// SIGNALS
//Signals are one of the 3 forms of interprocess communication

//One way is files, two programs writing and reading to shared data

//Pipes, piping information from one source to another, only go one way

//Signal, OS manages each process by sending it signals, we can write things to handle signals
//SIGTERM, please stop the program
//SIGKILL, murders the process

//signals are software level interuppts

//hardware level interupts, literally like the signal from a key press going to the os and 
//being printed on the screen
//software level interupts are the same thing but controller by signal handlers

//void * can be cast as any pointer

//FUNCTION POINTERS
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<stdbool.h>
#include<time.h>
void q1();
void q5();
void q6();
void timeHandler();
void quitProgramHandler();

void (*func)();

int main(int argc, char ** argv){
    q6();
}

void q1(){

    char * str = "Hello World\n";
    int * p = (int *)stdout;
    printf("%p\n", stdout);
    printf("%d\n", *p);
    write(1,str,12);

}

void q5(){
    signal(SIGINT, SIG_IGN);
    while(true){
        int seconds = sleep(100);
        printf("Seconds slept for %d\n", seconds);
    }

}

void q6(){
    signal(SIGINT,quitProgramHandler);
    signal(SIGUSR1,timeHandler);
    while(true){

    }

}

void timeHandler(int sig){
    time_t now;
    struct tm *ts;
    char buf[80];
    now = time(NULL);
    ts = localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m %H:%M:%S %Z", ts);
    puts(buf);
}

void quitProgramHandler(int sig){
    printf("Goodbye\n");
    exit(0);
}
