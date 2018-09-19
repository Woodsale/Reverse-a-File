#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char** argv){
	//argv[1] "Text.txt"
	//argv[2] "NewText.txt"
	FILE *fp, *fpw;
	char *buffer,*temp;

	fpw = fopen(argv[2],"w");

	struct stat st;
	stat(argv[1], &st);
	int size = st.st_size;

	read_file(argv[1],&buffer);

	temp = malloc(size * sizeof(char));
	int j = -1;
	for(int i = size;i>=0;i--){
		temp[j] = buffer[i];
		j++;
	}
	//temp[size] = '\0';
	//printf("%c",buffer[0]);
	//newtwxt,buffer,size
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
