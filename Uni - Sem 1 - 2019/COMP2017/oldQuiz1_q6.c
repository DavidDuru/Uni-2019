#include <stdlib.h>
#include <stdio.h>

int check_sevens(unsigned int a[]);

int main(){
    printf("in main\n");
    unsigned int a[7] = {1,2,3,4,5,6,7};
    int result = check_sevens(a);
    printf("num sevens: %d", result);

}

int check_sevens(unsigned int a[]){
    if(a == NULL) return -1;
    int count = 0;
    while(a != NULL){
        count++;
        a = a + 1;
    }

    printf("array length: %d\n", count);
    return 0;
}