#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int create_file(char * filename, size_t length, void * helper) {
	
	struct Memory * master = (struct Memory *)helper;
	struct Dir_Block * write_me = &master->directory_array[0];
	
	ssize_t disk2Size = my_file_size(master->disk2, helper);
	
	for(int i = 0; i < (disk2Size/72); i++){
		if(strcmp(master->directory_array[i].filename, filename) == 0){
			return 1;
		}
	}

	strcpy(master->directory_array[0].filename, filename);
	master->directory_array[0].length = (int)length;
	master->directory_array[0].offset = 0;

	FILE *fp;
	fp = fopen(master->disk2, "r+b");
	//This 0 will have to be replaced by the next free space in disk2
	fseek(fp, 0, SEEK_SET);
	//fseek(fp, free_index, SEEK_SET);
	fwrite(write_me, sizeof(*write_me), 1, fp);
	fclose(fp);
    return 0;
	
}