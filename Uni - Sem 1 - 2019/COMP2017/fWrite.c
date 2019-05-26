#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//set up the file with some text
	char* text = "abcdefghijklmnopqrstuvwxyz\n";
	FILE* f1 = fopen("test.txt", "w+");
	fwrite(text, strlen(text)+1, 1, f1);
	fclose(f1);
	
	//now attempt to overwrite the first 10 bytes
	// FILE* f2 = fopen("test.txt", "r+");
	// char* text2 = "0123456789";
	
	//note that we aren't writing the null byte
	//otherwise that will terminate the resultant string early
	// fwrite(text2, strlen(text2), 1, f2);
	// fclose(f2);
	
	//now read the file to confirm the first 10 bytes were overwritten
	// FILE* f3 = fopen("test.txt", "r");
	// char buffer[100];
	// fgets(buffer, 100, f3);
	// fclose(f3);
	
	//print the contents to confirm
	// printf("%s\n", buffer);
	
	return 0;
}