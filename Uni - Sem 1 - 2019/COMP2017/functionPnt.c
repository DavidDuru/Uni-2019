#include <stdio.h>
int add(int a, int b);
int subtract(int a, int b);
int mathFunction((int (*math1)(int, int),int (*math2)(int, int)));

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int (*math1)(int, int) = add;
int (*math2)(int, int) = subtract;


int main(int argc, char ** argv){
    int a = 1, b = 2;

    int (*math_func_ptr)(int (*math1)(int, int),int (*math2)(int, int));
    
    printf("result: %d\n", result);
}