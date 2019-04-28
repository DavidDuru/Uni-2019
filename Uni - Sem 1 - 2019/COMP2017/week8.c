//Writing programs to call other programs

//usin exec and fork functions

//fork creates a new process, creates a new memory space, has a copy of all the information in the first procfess
//original process is parent, forked process is child

//now you can have a program that does multiple tasks at once

//since fork copys all the memory over to a new memory space, if you had a big program sittig in memory
//it would take forever to copy across right? no because the os does this thing called copy on write
//where it only copies the information when it needs it

//we dont pay for what we dont use - with memory - copy on write

//fork only ever splits into 2, 

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int q1(void);
int q2(void);

int main(void) {

    //q1();
    q2();
}

int q1(void){
        int n = 4;
    puts("about to fork");
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("unable to fork");
        return 1;
    }
    
    //fork returns pid of child when called in the parent
    //fork returns 0 when in the child
    if (pid == 0) {
        puts("child");
        n++;
        sleep(1);
    } else {
        puts("parent");
        n *= 2;
        wait(NULL);
    }

    printf("fork returned %d, n is %d\n", pid, n);
    return 0;
}


int q2(void) {
    puts("about to launch sort");

    if (execl("/usr/bin/sort", "sort", "forkdemo.c", NULL) == -1) {
        perror("exec failed");
        return 1;
    }

    puts("finished sort");
    return 0;
}

// we also have the wait() function, which tells the parent to wait for the child process to 
//to finish before moving on with it's execution

//we can use inter process communiation to sending information between the two processess
//

//we can use getpid() to get the current process id
//getppid will get the pid of the current processes parent

//fork actually returns the pid of the child

//we always always always want to check which process we are after we fork

//exec , execl says, "go and excuse this process right now"