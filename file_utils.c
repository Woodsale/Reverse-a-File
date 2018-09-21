#include "file_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file( char* filename, char **buffer ){
	/**Creates a file pointer*/
	FILE *file;
	/**Opens the file to read*/
	file = fopen(filename,"r");

	/**Provided code on reading size*/
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	/**Creates memory for the buffer*/
	*buffer = malloc(size * sizeof(char));	

	/**Reads file contents to buffer*/
	fread(*buffer,size,1,file);
	/**Closes the file*/
	fclose(file);
	return 0;
}

int write_file( char* filename, char *buffer, int size){
	/** Creates a file pointer*/
	FILE *fileW;

	/** Opens the new file*/
	fileW = fopen(filename,"w");	
	
	/**Writes to the new file*/
	fwrite(buffer,size,1,fileW);
	
	return 0;
}
