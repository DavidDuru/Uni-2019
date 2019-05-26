#include <stdio.h>
#include <stdlib.h>

FILE * fd = fopen(f1, "rb");
	
	fseek(fd, 0, SEEK_END);
	filelength = ftell(fd);
	struct filedata_entry * fileentries = (struct filedata_entry *)malloc(filelength);	
	//printf("file lenght for fd: %d", filelength);
	fseek(fd, 0, SEEK_SET);

	fread(fileentries->block, 256, (filelength/256), fd);
	help_ptr->fentries = fileentries;
	fclose(fd);

////////////////////////////////////////////
	struct Data * data_array = (struct Data * )malloc(disk1Size);
	helper->data_array = data_array;	
	fp = fopen(f1, "rb");
	fseek(fp, 0, SEEK_SET);
	fread(helper->data_array, 256, (disk1Size/256), fp);
	fclose(fp);
///////////////////////////////////////////


//Dont need to do everything in the spec just change directory_table values for now
int create_file(char * filename, size_t length, void * helper) {
	
	struct Memory * master = (struct Memory *)helper;
	//make a new directory entry struct 
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

//How read file works, read and offset of an offset

read(file_data, offset, count, buf, helper)
read(file_data, 4, 6, data, helper)

	go through directory_table to find start of data_array
		match filename
		get offset of file(in this case 0)
	go to the data_block that is in range of the offset
		if the offset is at 0, go to data_block[0]; which holds offset (0-256)
		if the offset is at 700, go to data_block[0]; which holds offset (0-256)
			chunk_number = 0
			700 - 256 = 444, chunk_number++
			444 - 256 = 188, chunk_number++, would stop here because we get to negative
			//188 - 256 = -68
		
			chunk_number = 2
			give_offset = 4
			
file_data:

700: abcdefghijklmnop

data[i] = master->data_array[chunk_number].block[tmp];
data[i] = master->data_array[2].block[4];


abcdefghijklmnop
data = efghij


while(start_read != stop_read){
	data[i] = master->data_array[chunk_number].block[tmp];
	tmp++;
	start_read++;
	i++;	
}

//Just prints out the contents of some specific struct in your directory array
//args: int i, the index of the array you want to print out
void print_dir_index(int i, void * helper){
	struct Memory * master = (struct Memory *)helper;
	printf("filename: %s\n", master->directory_array[i].filename);
	printf("offset: %d\n", master->directory_array[i].offset);
	printf("length: %d\n", master->directory_array[i].length);
	printf("\n");
}

//prints out the content of your file_data struct, character by character
void print_data_content(void * helper){
	struct Data * data_array = (struct Data * )helper->data_array;
		for(int i = 0; i < num; i++){
			printf("%d: ", i);
			for(int j = 0; j < 256; j++){
				printf("%c", data_array[i].block[j]);
			}
			printf("\n");
		}
}

//reads in files and prints them as structs
////////////////////////////////////////////////////

	void print_disk_structs(int num, char * filename, int file, void * helper){
	ssize_t diskSize = my_file_size(filename, helper);
	FILE *fp;
	fp = fopen(filename, "rb");
	fseek(fp, 0, SEEK_SET);
	if(file == 1){
		struct Data* data_array = (struct Data * )malloc(diskSize);
		fread(data_array, 256, (diskSize/256), fp);
		for(int i = 0; i < num; i++){
			printf("%d: ", i);
			for(int j = 0; j < 256; j++){
				printf("%c", data_array[i].block[j]);
			}
			printf("\n");
		}
		free(data_array);
	}
	
	if(file == 2) {
		struct Dir_Block * directory_array = (struct Dir_Block * )malloc(diskSize);
		fread(directory_array, 72, (diskSize/72), fp);
		for(int i = 0; i < num; i++){
			printf("filename: %s\n", directory_array[i].filename);
			printf("offset: %d\n", directory_array[i].offset);
			printf("length: %d\n", directory_array[i].length);
			printf("\n");
		}
		free(directory_array);
	}
	fclose(fp);
	
}


int write_file(char * filename, size_t offset, size_t count, void * buf, void * helper) {
	//Truncate file name to 63 characters
	struct help * hp = (struct help *)helper;
	//print_file(hp->filedata);
	if(filename == NULL){
		return 1;
	}
	//is it possible to check for a filename thats not in the table?
	FILE * fp = fopen(hp->directorytable, "rb");
	rewind(fp);
	//Search for filename in system and find offset
	int fileoffset;
	int filelength;
	for(int i = 0; i < hp->dt_filelength; i++){
		if(strcmp(filename, hp->entries[i].fname) == 0){
			fileoffset = hp->entries[i].offset;
			filelength = hp->entries[i].len;
		}
	}
	if(offset > filelength){
		fclose(fp);
		return 2;
	}
	fclose(fp);
	FILE * fpp = fopen(hp->filedata, "rb+");
	rewind(fpp);
	char * buff = (char *)buf;


	fseek(fpp, fileoffset+offset, SEEK_SET);
	fwrite(buff, count, 1, fpp);
	//strncpy(buff, filebuffer, strlen(filebuffer));
	
	print_file(hp->filedata);
	fclose(fpp);
    return 0;
}




//////////////////////////////////
fwrite(data, strlen(data), 1, fp);
//////////////////////////////////
if(offset + count > read_this.length) return 2;


	FILE *fp;
	fp = fopen(master->disk1, "r+b");
	if(fp == NULL) return 1;
	fseek(fp, start_write, SEEK_SET);
	fwrite(data, strlen(data), 1, fp);
	fclose(fp);


//////////////////////////////////////////////////////////////
	struct help * hp = (struct help *)helper;
	
	//print_file(hp->directorytable);
	FILE * fp = fopen(hp->directorytable, "r+b");
	FILE * fpp = fopen(hp->filedata, "rb");
	if(filename == NULL){
		return 1;
	}
	//Find size of used space
	int usedspace = 0;
	for(int i = 0; i < hp->dt_filelength; i++){
		usedspace += hp->entries[i].len;
	}
	fseek(fpp, 0, SEEK_END);
	int t = ftell(fpp);
	int totalspace = t;
	if(length > totalspace){
		return 2;
	}