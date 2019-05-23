//
// Question 6 - Saving Pokemon
//

#include <stdio.h>

#define SIZE 4

typedef struct pokemon {
	char name[100];
	unsigned level;
} pokemon;

int main(void) {

	pokemon pokemons[SIZE];

	for (size_t i = 0; i < SIZE; i++) {
		if (scanf("%99s %u",
				pokemons[i].name,
				&pokemons[i].level) != 2) {
			fprintf(stderr, "unable to read input\n");
			return 1;
		}
	}

	printf("sizeof(size_t) = %zu\n", sizeof(size_t));
	printf("sizeof(unsigned) = %zu\n", sizeof(unsigned));
	printf("sizeof(char[100]) = %zu\n", sizeof(char[100]));

	printf("sizeof(pokemon) = %zu\n", sizeof(pokemon));
	printf("sizeof(pokemons) = %zu\n", sizeof(pokemons));

	// Attempt to save to file
	FILE* file = fopen("pokemon.dat", "w");
	if (file == NULL) {
		perror("unable to open file for writing");
		return 1;
	}

	// You can look at this file using the xxd program.
	//
	// Integers are stored on little endian order that is,
	// least significant bits of the integers are stored first.
	//
	// Note that the compiler has added padding into the
	// struct to align the structs to four bytes in memory.

	fwrite(pokemons, sizeof(pokemon), SIZE, file);
	fclose(file);

	return 0;
}