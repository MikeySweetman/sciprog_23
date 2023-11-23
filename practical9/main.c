#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magicsquare.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){
	//define our variable
	FILE *f;
	char filename[MAX_FILE_NAME];
	printf("Enter file name: ");
	scanf("%s", filename);

	// fucntion which gets the number of lines
	int n = getlines(filename);

	//open file
	f = fopen(filename, "r");
	if(f == NULL){
		printf("!! can't open file !!\n");
		exit(1);
	}

	int i;
	//allocating a matrix for storing the magic square
	//as an array of pointers where each pointer is a row
	int **magicSquare = malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		magicSquare[i] = malloc(n*sizeof(int));
	}

	//putting integer data into the matrix
	int j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(f, "%d", &magicSquare[i][j]);
			printf("%d\t", magicSquare[i][j]);
		}
		printf("\n");
	}
	printf("This square %s magic\n", isMagicSquare(magicSquare, n)?, "is":"is NOT");

	//freeing each row separatley before freeing the pointers
	for(i=0;i<n;i++){
		free(magicSquare[i]);
	}


	//close the file
	


	
	
  


  return 0;
}

int getlines(char filename[MAX_FILE_NAME]){
	FILE *fp;
	fp = fopen(filename, "r");
	
	int ch_read;
	int count = 0;

	while((ch_read = fgetc(fp)) != EOF){
		if(ch_read == "\n"){
			count++;
		}	
	}
	
	printf("No lines, %d\n", count);
	fclose(fp);
	return count;

}		
