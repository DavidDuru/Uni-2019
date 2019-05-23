#include <stdio.h>
#include <unistd.h>

int main() {

	fprintf(stdout, "%s\n", "Hello World!"); //Using the file object part of stdio, could use fwrite
	//dprintf(STDOUT_FILENO, "%s\n", "Hello World!"); //Using the file descriptor
	write(STDOUT_FILENO, "Hello World!\n", sizeof("Hello World!\n")); // Using the file descriptor and sys call


}
