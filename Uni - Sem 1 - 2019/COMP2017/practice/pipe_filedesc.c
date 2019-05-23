#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>
#include <string.h>

#define proc_print(...) \
    fprintf(stderr, "(%u)> ", getpid()); fprintf(stderr, __VA_ARGS__);

void print_time() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%s", asctime(timeinfo));
}

int main_child(int input_fd, int output_fd) {
    //TODO: Reopen output_fd as stdout
    //TODO: Reopen input_fd new FILE* "FILE* input"
	close(1);

    //Why call dup here?, does this replace stdout with our fd????
	dup(output_fd);
	
	FILE* input = fdopen(input_fd, "r");
    
    proc_print("Hello world from child.\n");

    char buffer[1024];

    while (1) {
        proc_print("Waiting for input\n");
        //fscanf(input, "%1023[^\n]", buffer);
        fgets(buffer, 1024, input);
        proc_print("Buffer received: %s", buffer);

        if (strcmp(buffer, "Hi! Do you know what time it is?\n") == 0) {
            printf("The time is "); 
            print_time(); fflush(stdout);
            proc_print("Printed time.\n");
        } else if (strcmp(buffer, "Thank you!\n") == 0) {
            proc_print("Received thankyou - exiting.\n");
            break;
        }
    }
    return 0;
}

int main_parent(int input_fd, int output_fd) {
    //TODO: Reopen output_fd as stdout
    //TODO: Reopen input_fd new file descriptor "FILE* input"
	close(1);
	dup(output_fd);
	
	FILE* input = fdopen(input_fd, "r");

    proc_print("Hello world from parent.\n");

    char buffer[1024];

    // Start communication
    proc_print("Sending first message\n");
    printf("Hi! Do you know what time it is?\n"); fflush(stdout);

    while (1) {
        proc_print("Waiting for input\n");
        //fscanf(input, "%1023[^\n]", buffer);
        fgets(buffer, 1024, input);
        proc_print("Buffer received: %s", buffer);
        buffer[11] = '\0'; // tricky business - make comparable

        if (strcmp(buffer, "The time is") == 0) {
            proc_print("Received time from child. Printing thanks.\n");
            printf("Thank you!\n"); fflush(stdout);
            wait(NULL);
            break;
        }
    }
    return 0;
}

int main(void) { 
    
    proc_print("=== opening pipe ===\n");
    // TODO: Open pipes
	int ptoc[2];
	int ctop[2];
	
	if(pipe(ptoc) < 0 || pipe(ctop) < 0) {
		proc_print("Pipe failed!\n");
		return 1;
	}

    proc_print("=== forking ===\n");
    pid_t pid = fork();
    if (pid < 0) {
        proc_print("Unable to fork!\n");
        return 1;
    }

    if (pid == 0) { // CHILD
		// TODO: close unused pipe ends
		close(ptoc[1]); close(ctop[0]);
        return main_child(ptoc[0], ctop[1]); //TODO: pass pipes
    } else { // PARENT
		// TODO: close unused pipe ends
		close(ptoc[0]); close(ctop[1]);
        return main_parent(ctop[0], ptoc[1]); // TODO: pass pipes
    }
}