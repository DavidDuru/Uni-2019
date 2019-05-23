#ifndef MYFILESYSTEM_H
#define MYFILESYSTEM_H
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_DATA_BLOCKS 16384
#define MAX_DIR_BLOCKS 916

void * init_fs(char * f1, char * f2, char * f3, int n_processors);

void close_fs(void * helper);

int create_file(char * filename, size_t length, void * helper);

int resize_file(char * filename, size_t length, void * helper);

void repack(void * helper);

int delete_file(char * filename, void * helper);

int rename_file(char * oldname, char * newname, void * helper);

int read_file(char * filename, size_t offset, size_t count, void * buf, void * helper);

int write_file(char * filename, size_t offset, size_t count, void * buf, void * helper);

ssize_t file_size(char * filename, void * helper);

void fletcher(uint8_t * buf, size_t length, uint8_t * output);

void compute_hash_tree(void * helper);

void compute_hash_block(size_t block_offset, void * helper);

void print_file(char * file_name);

struct Data {
	uint8_t block[256];
};

struct Dir_Block{
	char filename[64];
	int offset;
	int length;
};

struct Memory{
	char * disk1;
	char * disk2;
	char * disk3;
	ssize_t * disk1Size;
	ssize_t * disk2Size;
	ssize_t * disk3Size;
	FILE * file_cursor;
	struct Dir_Block * directory_array;
	struct Data * data_array; 
};



#endif