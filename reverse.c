#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char** argv){
	FILE *fp, *fpw;
	char *buffer;

	fpw = fopen("NewText.txt","w");

	struct stat st;
	stat("Text.txt", &st);
	int size = st.st_size;

	read_file("Text.txt",&buffer);
	
	fwrite(buffer,size,1,fpw);
	//write_file("NewText.txt",buffer,size);	
	return 0;
}


/***************************************
 * Resources used for the Project:
 *
 * "A Book On C" 
 * By Al Kelley and Ira Pohl 
 *
****************************************/
