#include <stdlib.h>
#include <stdio.h>

#define CUST_LEN (100)
#define BUF_LEN (300)

struct customer {
    char name[100];
    char object[100];
    int age;
};

int main() {

    struct customer customers[CUST_LEN];
    char buf[BUF_LEN];
    int i = -1;
    int stream_cont = 1;
    while(stream_cont && i < CUST_LEN) {
        i++;
        printf("Welcome to ShopaMocha\n");
        printf("Could you please tell me your name, age and what you are looking for?\n");
        stream_cont = fgets(buf, BUF_LEN, stdin) != NULL;
        sscanf(buf, "%s %d %s", customers[i].name, &customers[i].age, customers[i].object);
       
        printf("Hrmm, I think you should talk to a ShopaMocha assistant to find \"%s\"\n", 
            customers[i].object);
        printf("Have a good day!\n");
        
    }

    for(int j = 0; j < i; j++) {
        printf("Customer %d, Name: %s, Age: %d, Looking for: %s\n", 
            j, 
            customers[j].name,
            customers[j].age,
            customers[j].object);
    }

}