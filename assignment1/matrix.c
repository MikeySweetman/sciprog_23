//Source code for part 1 of the assignment

//including packages
#include <stdio.h>
#include <math.h>

//double matrixgen(void);


int main(void){	
	/*Here is the block of code that 
    creates the intial 4x4 matrix with
    the required values */
	int i, j;
	double matrix[4][4];// = {};
	
	i = 0;
	j = 0; 
	
	for(j=0;j<4;j++){
		for(i=0;i<4;i++){
			matrix[i][j] = 1/(double) (j+i+1);
			printf("matrix[%d][%d] = %f\n", i, j, matrix[i][j]);
		}
	}

	/*calling the function that calculates 
    the determinant of a 3x3 matrix */
	




	return 0;
}

//function to calculate the determinant of a 3x3 matrix
double 3det(double matrix[3][3]){

	
	return det;
}
