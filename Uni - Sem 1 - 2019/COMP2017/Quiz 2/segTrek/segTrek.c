#include <stdlib.h>
#include <stdio.h>

int main() {
    void* a = (int*)malloc(sizeof(int*) * (1 << 3));
    void* b = (int*)malloc(sizeof(int*) * 9);
    for (size_t i = 0; i <= 9; i++){
        ((int*)a)[10] += i >> 1;
        ((int*)b)[i] = i + ~i;
        printf("a: %d\n", ((int*)a)[10]);
        printf("b: %d\n", ((int*)b)[i]);
        if (i == 8){
                free(a);
            }
    }
    free(a);
    return ((int*)a)[0];
}
