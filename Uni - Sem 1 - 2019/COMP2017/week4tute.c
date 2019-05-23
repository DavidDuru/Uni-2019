#include <stdio.h>
#include <stdlib.h>

int var_a; //global static

int sum (const int* var_b) {
    static int var_c; // global static
    var_c += var_b;
    return var_c;
}

int main (int argc, char** argv) {
    int var_d = 0; // stack
    int* var_e = malloc(sizeof(int)); // is stored on the stack, points to the heap

    if (NULL == var_e)
    {
        perror("Malloc Failed!");
        return 1;
    }

    *var_e = 2;
    sum(&var_d);
    sum(&var_a);
    sum(var_e);

    char* var_f = calloc(sizeof(char), 100);
    if (NULL == var_f)
    {
        perror("Calloc Failed");
        return 1;
    }
    free(var_e);
    return 0;
}
//What is the lifetime of var_a,var_c, var_d and var_e?
    //var a, whole program
    //var_c, whole program
    //var_d, life time of the function
    //var_e, 
//What would happen if we did not free any malloc’d memory?
    //could get a memory leak?
//When and where might memory leaks occur in this code?
    //if the calloc fails?