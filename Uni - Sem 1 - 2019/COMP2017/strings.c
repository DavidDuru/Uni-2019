<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv){
    printf"type your name:\n");
    char * myName;
    fgets(myName, 10, stdin);
    printf("your name is: \n");
    putchar(myName);
    return 0;

    int * ptr;
    ptr = (int *)malloc(sizeof(int)*20);
=======
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void inputFromStdin();
void copyingStrings();

int main(void){
    int * ptr;
    ptr = (int *)malloc(sizeof(int) * 20);
    ptr[0] = 123;
    printf("%p\n", ptr);
    printf("%d", ptr[0]);
    return 0;
}

void copyingStrings(){
    char * str1 = "apples";
    char * str2 = "bananas";
    puts(str1);
    puts(str2);
    strcpy(str1,str2);
    puts(str1);
    strcpy(str2,"ding");
    printf("\n");  
    puts(str2);
}

void inputFromStdin(){
    char name[3];
    fgets(name,3,stdin);
    printf("Name: ");
    puts(name);
<<<<<<< HEAD
    return 0;
>>>>>>> 7d8209434f57b2d31df2ed19fa3e7c8cbaa256b9
=======
>>>>>>> mergeMe
}