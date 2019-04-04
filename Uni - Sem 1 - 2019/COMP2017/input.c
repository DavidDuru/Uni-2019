#include<stdio.h>
#include<stdlib.h>

//argc number of command line arguments
//first arg is name of program
//

int main(int argc, char ** argv){
    //print arguments to program
    char name[20];
    printf("What is your name?");
    //scanf reads until whitespace
    //if you run scanf again it'll get the next string, delimetred by whitespace 
    scanf("%s", name);
    printf("Hello,%s! with scanf\n", name);
    //fgets reads until a delimter or end or buffer
    fgets(name, 20, stdin);
    printf("Hello,%s! with fgets\n", name);
    //print standard input

    return EXIT_SUCCESS;

}