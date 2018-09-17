#include "file_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file( char* filename, char **buffer ){
	int c;
	FILE *file;
	file = fopen(filename,"r");

	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	*buffer = malloc(size * sizeof(char));
	
	fread(*buffer,size,1,file);
	fclose(file);
	return 0;	
	//(buffer,size,1,pointer)
}

int write_file( char* filename, char *buffer, int size){
	FILE *fileW, *fileR;
	fileR = fopen(buffer,"r");
	fileW = fopen(filename,"w");

	fwrite(fileW,size,1,fileR);
	
	return 0;
}
