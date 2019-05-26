#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "forkit.h"

// int main(int argc, char ** argv){
// 	char *** data = NULL;
// 	int * len = (int * )malloc(sizeof(int));
// 	puts("in main");
// 	read_file("ftest1.txt",data,len);
// 	for(int i =0; i < *len; i++){
// 		printf("%d:%s", i,*data[i]);
// 	}
// }

//Question 1
void read_file(const char* filename, char*** data, int* len) {
	
	//printf("%s", filename);
	FILE * fp;
	
	if(filename == NULL) return;
	
	char buf[500];
	
	fp = fopen(filename,"r");
	fscanf(fp,"%s",buf);
	//ssize_t size = ftell(fp);
	//printf("size of file %zd\n", size);
	
	//char ** string = NULL;
	int num_lines = 0;
	
	char s = getc(fp);
	
	while(s != EOF){
		if(s == '\n'){
			num_lines++;
		}
		s = getc(fp);
	}
	fclose(fp);
	
	*len = num_lines;
	
	char ** string_array = (char **)malloc((sizeof(char *) * num_lines));
	
	for(int i = 0; i < num_lines; i ++){
		char * string = (char *)calloc(1, sizeof(char) * 500);
		string_array[i] = string;
	}
	
	fp = fopen(filename,"r");
	
	for(int i = 0; i < num_lines; i++){
		if(strlen(buf) == 0) break;
		fscanf(fp,"%s",buf);
		strcpy(string_array[i], buf);
	}
										   
	*data = string_array;

    return;
}


//Question 2
void create_processes(int n, char** data, int len) {
	
	//fprintf(stderr, "n = %d, len = %d\n", n, len);
	//fprintf(stderr, "child work %d, parent work stars %d\n", len/n, (len) - (len/n));
	
	int child_work = len/n;
	int parent_work_start = ((len) - (len/n)) - 1;
	//pid_t pid = -1;
	
	pid_t pid = 0;
	int index = 0;
	
	for(int i = 0; i < n; i++){
		//fprintf(stderr, "i: %d\n", i);
		pid = fork();
	
		//For child Process
		if(pid != 0){
			//wait(NULL);
			//fprintf(stderr, "In child\n");
			for(int j = index; j < child_work; j++){
				//fprintf(stderr, "%d:%s",i, data[j]);
				printf("%d:%s", i, data[j]);
				index++;
			}
			exit(pid);
		}
		
		i++;
	
		//For parent process
		if(pid == 0){
			wait(NULL);
			//fprintf(stderr, "In parent\n");
			for(int j = parent_work_start + 1; j < len; j++){
				//fprintf(stderr, "%d:%s",i, data[j]);
				printf("%d:%s", i, data[j]);
			}
			
			exit(pid);
		}	
	}
	
	//freeing everything
	// for(int i = 0; i < len; i++){
	// 	free(data[i]);
	// }
	// free(data);
	//puts("Test Passed");

}
