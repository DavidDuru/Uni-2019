#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){

	FILE * fp;

	// char block_init[1024];
	// fp = fopen("writeTest.bin", "wb");
	// fwrite(block_init, sizeof(block_init), 1, fp);
	// fclose(fp);

	char block[64] = "now i'm changirhgreagreang it to this";
	fp = fopen("writeTest.bin", "r+b");
	//
	fwrite(block, sizeof(block), 1, fp);
	fclose(fp);
	
	return 0;
}