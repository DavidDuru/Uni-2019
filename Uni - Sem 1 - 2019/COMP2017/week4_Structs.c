#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void sam_code(void);
void q2();
void q3();

int main(){

    q2();
    return EXIT_SUCCESS;
    
}

void q2(){

    enum TYPE { FIRE, WATER, FLYING, ROCK, ELECTRIC };
        struct pokemon {
        const char* name;
        enum TYPE type;
    };

    //which of these will compile?

    //no
    //pokemon pikachu = { "Pikachu", ELECTRIC };

    //no
    //struct pokemon pikachu1 = { ELECTRIC, "Pikachu" };
    
    //yes
    struct pokemon pikachu2 = { "Pikachu", ELECTRIC };

    //yes
    struct pokemon pikachu3 = { .type = ELECTRIC, .name = "Pikachu" };

    //no
    struct pokemon blank4 = { 0 };

    //what assumptions can you make about sizeof(struct pokemon)
    //it is a least 12 bytes??? enum is 1 int, 4 bytes int + char * is 8 bytes

    //3. What does the following code do?
    struct pokemon pikachu = { "Pikachu", ELECTRIC };
    struct pokemon *ptr = &pikachu;
    ptr->name = "Raichu";
    ptr->type = ELECTRIC;

    //sets the name of pokemon to raichu and the type to electric


    //4. What would the following code do? 

    //void evolve(struct pokemon mon){
    //    ptr.name = "Raichu";
    //    ptr.type = ELECTRIC;
    //};

    //int main() {
    //struct pokemon pikachu = { "Pikachu", ELECTRIC };
    //evolve(pikachu);

    //answer: would set pikachu->name to "raichu"
    // and set pikachu->type to ELECTRIC

    //5 what changes would you make to the above code, ????
}

void q3(){
printf("hello, tell me your name age and what you want");
char* name;
char* age;
char* want;

}


void sam_code(){
    	union number
	{
		int i;
		float f;
		double d;
	};
	
	union number n;
	n.i = 10;
	n.f = 10.05;
	n.d = 12.02;

	
	printf("i is: %d, f is: %f, d is %f\n", n.i, n.f, n.d);

    //data type sizes
    int a;
    //4 bytes

    int* b = &a;
    //4 bytes on 32bit, 8 on 64bit

    int* c = NULL;
    //same as above

    unsigned d;
    //4 bytes

    short e;
    //2 bytes

    long f;
    //8 bytes

    size_t g;
    //8 bytes, the size of pointer

    long long h;
    //8 bytes

    uint8_t i;
    //C standard int type, 8 bits
    //number of bits it takes to represent these in memory
    //it is hardware independent
    uint32_t j;
    //C standard int type, 32 bits
    //number of bits it takes to represent these in memory
    //it is hardware independent

    struct quoll{
        char name[20];
        uint8_t age;
    };
    //sizeof(quoll) will be 21 bytes

    struct quokka 
    {
        char* name;
        struct quokka* quokka_father;
        struct quokka* quokka_mother;
    };

        union mammal 
    {
        char* name;
        struct quoll l;
        struct quokka a;
    };
    //will be 24 bytes because unions allocate the largest data type

    //if you compile with the m32 flag, your pointer values will become 4 bytes
    //uint8_t and uint32_t wont change

    //sizeof(struct >= sum of sizeof(fields))
    //sizeof(union) = max(sizeof(fields))
}