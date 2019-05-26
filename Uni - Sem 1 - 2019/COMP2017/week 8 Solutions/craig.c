#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "forkit.h"

#define MAX_LEN 500

//Question 1
void read_file(const char* filename, char*** data, int* len) {
	
	FILE* file = fopen(filename, "r");
	char b[MAX_LEN];
	int count = 0;
	*data = malloc(0);
	
	while (fgets(b, MAX_LEN, file)) {
		*data = realloc(*data, (count+1) * sizeof(char*));
		int length = (int) strlen(b) + 1;
		(*data)[count] = malloc(length * sizeof(char));
		memcpy((*data)[count], b, length);
		(*data)[count][length-1] = '\0';
		count++;
	}
	
	*len = count;
	fclose(file);
}


//Question 2
void create_processes(int n, char** data, int len) {
	
    //make a pid variable
	pid_t pid;
    //calculate how many strings each process will need to work on
	int interval = len/n;
	
    //for every number of processes we are given
    //increment i first so we can get the offset to start working from???
    //apparently it doesnt make a different
	for (int i = 0; i < n; ++i) {
        //we fork
		pid = fork();
        //if we're in the child
		if (pid == 0) {
			for (int j = i*interval; j < (i+1)*interval; ++j) {
				printf("%d:%s", i, data[j]);
				// free(data[j]);
			}
			exit(0);
		}
	}
}