#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAP (16)

int main(int argc, char** argv) {

	if(argc > 1) {
		int n = strtol(argv[1], NULL, 10);
		int* array = malloc(DEFAULT_CAP*sizeof(int));
    int size = 0;
    int capacity = DEFAULT_CAP;


		for(int i = 0; i < n; i++) {
			array[i] = i*i;
      size++;
      if(size >= capacity) {
        int* temp = realloc(array, capacity*2);
        if(temp != NULL) {
          array = temp;
          capacity = capacity * 2;
        } else {
          fprintf(stderr, "Cannot reallocate array");
        }
      }
		}

		for(int i = 0; i < size-1; i++) {
			printf("%d ", array[i]);
		}
		printf("%d\n", array[n-1]);

		free(array);
	}

	return 0;
}
