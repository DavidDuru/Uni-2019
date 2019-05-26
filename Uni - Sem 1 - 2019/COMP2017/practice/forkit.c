#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "forkit.h"

int main(int argc, char ** argv){
	char *** data = NULL;
	int * len = (int * )malloc(sizeof(int));

	puts("in main");
	
	read_file("ftest1.txt",data,len);
	
	puts("This should print");
	printf("num_malloc holds: %p\n", len);

}

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
	
// 	int * len_new = (int *)malloc(sizeof(int));
// 	//printf("len_new has %p\n", len);
// 	*len_new = num_lines;
// 	//printf("len_new holds %d\n", *len);
	
// 	len = len_new;
	
	//printf("len has %p\n", len);
	//printf("len holds %d\n", *len);
	
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
		//printf("string array: %d = %s\n", i, string_array[i]);
	}
										   
// 	//size_t size = (sizeof(char *) * num_lines) + (sizeof(char) * 500);
// 	//memcpy(data,string_array,size);
	*data = string_array;

	
	//free(len_new);
	

    return;
}


//Question 2
void create_processes(int n, char** data, int len) {
	
	// int p_to_child[2];
	// int c_to_parent[2];
	pid_t pid = -1;
	
	for(int i = 0; i < n; i++){
		pid = fork();
	}
	
	if(pid < 0){
		puts("fork failed");
	}
	
	//For child Process
	if(pid != 0){
		for(int i = 0; i < len; i++){
			printf("%d:%s\n", i, data[i]);
		}
		//For parent process
	} else{
		for(int i = 0; i < len; i++){
			printf("%d:%s\n", i, data[i]);
		}
	}
	
	for(int i = 0; i < len; i++){
		free(data[i]);
	}
	free(data);	

}
