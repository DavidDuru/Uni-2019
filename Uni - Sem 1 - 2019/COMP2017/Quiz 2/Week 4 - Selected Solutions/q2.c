//
// Question 2 - Structs
//

#include <stdio.h>

enum TYPE { FIRE, WATER, FLYING, ROCK, ELECTRIC };
struct pokemon {
	const char* name;
	enum TYPE type;
};

int main(void) {

	//
	// Part 1
	//

	// Will not compile. Needs a typedef or the struct keyword before the declaration.
	pokemon pa = { "Pikachu", ELECTRIC };

	// Will compile with warnings. Incompatible types.
	struct pokemon pb = { ELECTRIC, "Pikachu" };

	// Will compile. Sets attributes in the order they are defined.
	struct pokemon pc = { "Pikachu", ELECTRIC };

	// Will compile. Designator initalization syntax.
	struct pokemon pd = { .type = ELECTRIC, .name = "Pikachu" };

	// Will compile. Sets first attribute to zero and the rest default to zero.
	struct pokemon pe = { 0 };

	//
	// Part 2
	//

	// The size of the struct will be >= sizeof(char *) + sizeof(enum TYPE)
	// depending on whether the compiler will add any padding to the struct.
	size_t s = sizeof(struct pokemon);

	//
	// Part 3
	//

	struct pokemon pf = { "Pikachu", ELECTRIC };
	struct pokemon* pg = &pf;

	// Sets the values of the pikachu struct to { "Raichu", ELECTRIC }
	pg->name = "Raichu";
	pg->type = ELECTRIC;
}