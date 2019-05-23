#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

pid_t pid = 0;

void child_handler(int _) {
	printf("pid %d so in handler A\n", pid);
};

void parent_handler(int _) {
	printf("pid %d so in parent handler B\n", pid);
	kill(pid, SIGINT);
}

int main() {

    puts("1 Start\n");
	
	pid = fork();
	
	if(pid == 0) {
		//child
		signal(SIGINT,child_handler);
		printf("\t4 pid %d so in child\n", pid);
		pid_t ppid = getppid();
		kill(ppid, SIGINT);
	}
	else {
        printf("2 pid %d so in parent, which continues first\n", pid);
		signal(SIGINT, parent_handler);
        kill(pid, SIGINT);
		wait(NULL);
	}

    if(pid == 0) puts("\t 5 child End\n");
    else{
        puts("3 parent End\n");
    }

}

//What does kill