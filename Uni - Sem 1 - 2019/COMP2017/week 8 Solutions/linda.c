#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv){

   

}


void read_file(const char* filename, char*** data, int* len) {

    //read in file
    //Calculate your number of lines
    //blah blah blah

    FILE * fp;
    int num_lines = 40;
    char buf[500];

    //malloc enough memory to hold a pointer to every string we have in our
    //string array -- yeah i didnt do this part...
    char ** string_array = (char **)malloc((sizeof(char *) * num_lines));
	
    //for each string pointer in our string array
    //allocate enough space for a 500 char string
	for(int i = 0; i < num_lines; i ++){
		char * string = (char *)calloc(1, sizeof(char) * 500);
		string_array[i] = string;
	}
	
    //open our file
	fp = fopen(filename,"r");
	
	for(int i = 0; i < num_lines; i++){
		//if the string is empty stop reading
        if(strlen(buf) == 0) break;
		//otherwise read until \n or EOF, store in buffer
        fscanf(fp,"%s",buf);
        //copy contents to ith index of string array
		strcpy(string_array[i], buf);
	}
    
    //give the string array to our pointer that holds string arrays
	*data = string_array;
    
    

    





}