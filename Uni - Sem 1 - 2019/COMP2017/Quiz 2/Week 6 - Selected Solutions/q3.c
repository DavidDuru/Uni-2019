#include <stdlib.h>
#include <string.h>

/*
 * Our comparator function for integers
 */
int int_cmp(void* a, void* b) {
	int* a_ptr = (int*) a;
	int* b_ptr = (int*) b;

	return (*a_ptr) - (*b_ptr);
}

/*
 * Bubble sort implementation, we use memcpy and a void* buffer for temporary storage
 * We then throw int_cmp (this would be passed in main) to the function to be executed
 */
void bubble_sort(void* elements, size_t n, size_t sz, int (*cmp)(void*, void*)) {
	int keep_repeating = 1;
	void* buff = malloc(sz);
	for(int i = 0; i < n && keep_repeating; i++) {
		keep_repeating = 0;
		for(int j = 0; j < (n-1); j++) {
			if(cmp(elements+(j*sz), elements+((j+1)*sz)) > 0) {

				memcpy(buff, elements+(j*sz), sz);
				memcpy(elements+(j*sz), elements+((j+1)*sz), sz);
				memcpy(elements+((j+1)*sz), buff, sz);
				keep_repeating = 1;
			}
		}
	}
	free(buff);
}
