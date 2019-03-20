#include<stdlib.h>
#include<stdio.h>

int main(int argc, char ** argv){
    printf("hello, tell me your name age and what you want:\n");
    char name[10];
    char age[10];
    char want[10];
    scanf("%s", name);
    scanf("%s", age);
    scanf("%s", want);

    printf("go home %s, %s is old and noone likes %s\n", name,age,want);

}