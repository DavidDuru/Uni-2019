#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "myfilesystem.h"

//Do a design document

//max number of data structs???

//max number of directory structs?

void * init_fs(char * f1, char * f2, char * f3, int n_processors) {
	
	struct Dir_Block * directory_array = (struct Dir_Block * )malloc(sizeof(struct Dir_Block)*MAX_DIR_BLOCKS);
	struct Data * data_array = (struct Data * )malloc(sizeof(struct Data)*MAX_DATA_BLOCKS);
	struct Memory * helper = (struct Memory *)malloc(sizeof(struct Memory));
	ssize_t * disk1Size = (ssize_t *) malloc(sizeof(ssize_t));
	ssize_t * disk2Size = (ssize_t *) malloc(sizeof(ssize_t));
	ssize_t * disk3Size = (ssize_t *) malloc(sizeof(ssize_t));
	
	helper->data_array = data_array;
	helper->directory_array = directory_array;
	
	// struct Dir_Block * directory_array = (struct Dir_Block * )malloc(sizeof(struct Dir_Block));
	// struct Data * data_array = (struct Data * )malloc(sizeof(struct Data)*MAX_DATA_BLOCKS);
	// struct Memory * helper = (struct Memory *)malloc(sizeof(struct Memory));
	
	//printf("helper size: %ld, dir size: %ld\n", sizeof(helper), sizeof(directory_array));
	//printf("deref helper size: %ld, deref dir size: %ld\n", sizeof(*helper), sizeof(*directory_array));
	//printf("deref data size: %ld\n",sizeof(data_array[0]));
	
	helper->disk1 = f1;
	helper->disk2 = f2;
	helper->disk3 = f3;
	
	*disk1Size = file_size(f1, helper);
	*disk2Size = file_size(f2, helper);
	*disk3Size = file_size(f3, helper);
	
	helper->disk1Size = disk1Size;
	helper->disk2Size = disk2Size;
	helper->disk3Size = disk3Size;
		
	// free(disk1Size);
	// free(disk2Size);
	// free(disk3Size);
	// free(directory_array);
	// free(data_array);
    return helper;
}

void close_fs(void * helper) {
	struct Memory * master = (struct Memory *)helper;
	//struct Data  * data_array = master->data_array;
	//void *
	
	//printf("%p\n", master->data_array);
	//printf("%ld\n", sizeof(master->data_array[1]));
	free(master->disk1Size);
	free(master->disk2Size);
	free(master->disk3Size);
	free(master->data_array);
	free(master->directory_array);
	free(master);
    return;
}

int create_file(char * filename, size_t length, void * helper) {
	
	
	//printf("%ld\n", file_size(filename, helper));
	//printf("filename: %s\n", filename);
	struct Memory * master = (struct Memory *)helper;
	
	print_file(master->disk2);
	
	FILE * fp;
	int l = (int)length;
	int i = 256;
	char block[256] = { '\0' };
	//char blank_name[64] = { '\0' };
	
	struct Test_Struct{
		char filename[64];
		int offset;
		int length;
	};
	
	struct Test_Struct * dir = (struct Test_Struct *)malloc(sizeof(struct Test_Struct));
	
	//Writing data, just appeneding to the start
	fp = fopen(master->disk1, "r+b");
	while(l > 0){
		fwrite(block, sizeof(block), 1, fp);
		l = l - i;
	}
	fclose(fp);

	//writing directory information
	
	for(int i = 0; i < strlen(filename); i++){
		dir->filename[i] = filename[i];
	}
	
	// for(int i = 0; i < 71; i++){
	// 	printf("[%c]", dir->filename[i]);
	// }
	
	dir->offset = abs(l);
	dir->length = (int)length;
	fp = fopen(master->disk2, "r+b");
	fwrite(dir, sizeof(struct Test_Struct), 1, fp);
	fclose(fp);
	
	free(dir);
    return 0;
	
}

int resize_file(char * filename, size_t length, void * helper) {
    return 0;
};

void repack(void * helper) {
    return;
}

int delete_file(char * filename, void * helper) {
    return 0;
}

int rename_file(char * oldname, char * newname, void * helper) {
    return 0;
}

int read_file(char * filename, size_t offset, size_t count, void * buf, void * helper) {
    return 0;
}

int write_file(char * filename, size_t offset, size_t count, void * buf, void * helper) {
    
	struct Memory * master = (struct Memory *)helper;
	FILE * fp;
	
	fp = fopen(master->disk2, "w+");
	fwrite(filename, sizeof(filename)+1, 1, fp);
	fclose(fp);
	
	return 0;
}

ssize_t file_size(char * filename, void * helper) {
    FILE *fp; /*to create file*/
    long int size=0;
     
    /*Open file in Read Mode*/
    fp=fopen(filename,"r");
 
    /*Move file point at the end of file.*/
    fseek(fp,0,SEEK_END);
     
    /*Get the current position of the file pointer.*/
    size=ftell(fp);
    
    return size;
}

void fletcher(uint8_t * buf, size_t length, uint8_t * output) {
    return;
}

void compute_hash_tree(void * helper) {
    return;
}

void compute_hash_block(size_t block_offset, void * helper) {
    return;
}

void print_file(char * file_name){
	char ch;
	FILE * fp = fopen(file_name, "rb"); // read mode
 
   	if (fp == NULL)
   	{
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   	}
 
   	printf("The contents of %s file are:\n", file_name);
 
   	while((ch = fgetc(fp)) != EOF)
      printf("%d", ch);
 
   	fclose(fp);

}