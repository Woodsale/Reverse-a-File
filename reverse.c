#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
Reverse Program

Takes a file and returns another file
that is reversed

@author Alex Woods 
@version 9-19-2018
*/
int main(int argc, char** argv){
	/** File pointers for reading and writing*/
	FILE *fp, *fpw;
	/** This will be used for copying a file, 
	 * reversing it, and writing back to another file*/
	char *buffer,*temp;

	/**Opens the file it will read to*/
	fpw = fopen(argv[2],"w");

	/**Provided code used to determine the size of the file*/
	struct stat st;
	stat(argv[1], &st);
	int size = st.st_size;

	/**Reads file to the buffer*/
	read_file(argv[1],&buffer);

	/**Reverses the file*/
	temp = malloc(size * sizeof(char));
	int j = -1;
	for(int i = size;i>=0;i--){
		temp[j] = buffer[i];
		j++;
	}
	
	/**Writes the reversed version to a new file*/
	write_file(argv[2],temp,size);
	free(temp);	
	return 0;
}


/***************************************
 * Resources used for the Project:
 *
 * "A Book On C" 
 * By Al Kelley and Ira Pohl 
 *
****************************************/
