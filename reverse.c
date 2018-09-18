#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char** argv){
	FILE *fp, *fpw;
	char *buffer,*temp;

	fpw = fopen("NewText.txt","w");

	struct stat st;
	stat("Text.txt", &st);
	int size = st.st_size;

	read_file("Text.txt",&buffer);

	temp = malloc(size * sizeof(char));
	int j = -1;
	for(int i = size;i>=0;i--){
		temp[j] = buffer[i];
		j++;
	}
	//temp[size] = '\0';
	//printf("%c",buffer[0]);
	//newtwxt,buffer,size
	write_file("NewText.txt",temp,size);
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
