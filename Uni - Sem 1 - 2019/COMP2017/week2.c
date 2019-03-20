#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void segfault();
void q6();
void q3();
int my_str_len();
void testCmp();

int main(void){
    q6();
    
    return EXIT_SUCCESS;
}

void q3(){
    //Suppose the first element of char z[100] has address 0x1000.
    //What does
    char z[100];
    printf("address of z is: %p \n" , &z);
    printf("%p = address that is + 1 char byte from address of z\n", &z[1]);
    printf("%p + 5 = %p first item in the + 5 the memory size of char, where char is 1 byte\n",z, z + 5);
    printf("%p, %p, %td = three, td outputs how many sizeof(pointers) are between the two addresses : \n",&z[12], &z[9], &z[12] - &z[9]);
    printf("in the line above notice that the td formatter prints sizeof(&z[12] - sizeof(&z[9] \n interestingly it's just the differences in the array index\n");
    printf("&z[1] - 1 = address of the object one char byte back from %p = %p \n", &z[3] ,  &z[3] - 1);
    printf("&z[20] - 5 = address of the object 5 char bytes back from %p = %p \n\n",&z[20], &z[20] - 5);
    double u[100];
    printf("u is %p\n", u);
    printf("address that is one sizeof(double) greater than %p = %p\n",&u , &u[1]);
    printf("u + 5 %p\n",u + 5);
    //printf("%td\n",&u[12] - &u[9]);
}

void q6(){
    
    my_str_len("");
    my_str_len("123");
    my_str_len("abc\n");
    my_str_len("apples");
    my_str_len("lorem\0ipsum\n");
    my_str_len("lorem ipsum\n");


    //How to debug a segfault
}

void q8(){

}

void segfault(){
    int ************* tricky;
    printf("%p", **tricky);
}

void lectureCode(){

}

int my_str_len(char* s){
    char end = '\0';
    int count = 0;
    char * empty = "";


    if(strcmp(empty, s) == 0){
        printf("the input string is empty\n");
        return 0;
    }

    printf("string is \"%s\"\n", s);

    for(int i = 0; strcmp(&s[i], &end) != 0; i++){
        count ++;
    }
    
    printf("length is: %d\n\n", count);

    return count;
}

void testCmp(){
    printf("%d\n", strcmp("apples","bananas"));
    printf("%d\n", strcmp("apples","apples"));
    char * dog = "dog";
    char * cat = "cat";
    printf("%d\n", strcmp(dog,cat));
}