#include<stdio.h>
#include<stdlib.h>

void q2();

int main(void){
    //The stack grows down from null
    //The heaps grows up

    //Stack place is very limited
    //one stack frame looks like this
    //     |local variables
    //     |return address
    //     |parameters

    //so parameters is passed first, then return address then local variables

    //unless you free memory from the heapm it stays on the heap
}
