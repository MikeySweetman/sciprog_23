//Source code for part 1 of the assignment

//including packages
#include <stdio.h>
#include <math.h>

double det3(double matrix[3][3]);
double cramers(double matrix[4][4]);

int main(void){	
	/*Here is the block of code that 
    creates the intial 4x4 matrix with
    the required values */

	//in this code I use i as row index and j as colum index
	int i, j;
	double matrix[4][4];
	

	i = 0;
	j = 0; 

	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			matrix[i][j] = 1/(double) (j+i+1);
			//printf("matrix[%d][%d] = %f\n", i, j, matrix[i][j]);
		}
	}
	

	//printing the 4x4 matrix
	for(i=0;i<4;i++){
		printf("%f  %f  %f  %f\n",matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
	}

	
	/*calling the function that calculates 
    the determinant of a 3x3 matrix */
    double det4;
	det4 =  cramers(matrix);
	printf("\nthe determinant of the 4x4 matrix is %f\n", det4);	




  return 0;
}

//=====================================================================================
//functions below


//function to calculate the determinant of a 3x3 matrix
double det3(double matrix[3][3]){
	double det;

	det = matrix[0][0]*matrix[1][1]*matrix[2][2] + 
    matrix[0][1]*matrix[1][2]*matrix[2][0] +
    matrix[0][2]*matrix[1][0]*matrix[2][1] -
    matrix[0][0]*matrix[1][2]*matrix[2][1] -
    matrix[0][1]*matrix[1][0]*matrix[2][2] -
    matrix[0][2]*matrix[1][1]*matrix[2][0] ;
	
	return det;
}




/*function to split 4x4 matrix into 3x3 matricies,
 * the dets of which will be calculated
 * using the function det3
 *
 * I am creating four submatricies given in the
 * assignment document, index counters
 * i and j correspond to the position in
 * the 4x4 matrix
 * eg "g" is at i = 1, j= 2 in 4x4 matrix
 */
double cramers(double matrix[4][4]){
	//coeffecient to multiply 3x3 dets by
	double a = matrix[0][0];
	double b = matrix[0][1];
	double c = matrix[0][2];
	double d = matrix[0][3];
	
	//named 3x3s after the coefficent they're mulitplied by
	double amat[3][3], bmat[3][3], cmat[3][3], dmat[3][3];
	
	int i = 0; int j = 0;
	

	//filling the submatricies
	//amatrix
	for(i=1;i<4;i++){
		for(j=1;j<4;j++){		
			amat[i-1][j-1] = matrix[i][j];
		}
	}
	

	/*
     *loops for filling the b and c matricies are
	 * a little bit ugly as the indicies between the 
	 * 4x4 and 3x3 matricies don't map nicely
	 * 
	 * eg for cmat 4x4 colum indices 0 1 3 has 
	 * to go to 0 1 2 in the 3x3 matrix
	 * for each row
	 *
	 * bmat is 0 2 3 to 0 1 2 for
	 * j index 
     */ 
	//bmat
	for(i=1;i<4;i++){
		for(j=1;j<4;j++){
			if(j==1){
				j--;
				bmat[i-1][j] = matrix[i][j];
				j += 2;
			}	
			bmat[i-1][j-1] = matrix[i][j];			
		}
	}


	//cmat
	for(i=1;i<4;i++){
		for(j=1;j<4;j++){
			if(j!=2){
				j--;
				cmat[i-1][j] = matrix[i][j];
				j++;			
			}	
			else{j++;
				cmat[i-1][j-1] = matrix[i][j];
				break;
			}	
			cmat[i-1][j] = matrix[i][j];
		}	
	}

	//dmat
	for(i=1;i<4;i++){
		for(j=0;j<3;j++){
			dmat[i-1][j] = matrix[i][j];
		}
	}

	/*
     * now that I have the four matricies required I can 
     * calulate the determinants of them and get the final determinant
	 */
	double final_det;

	final_det = a * det3(amat)
			- b * det3(bmat)
			+ c * det3(cmat)
			- d * det3(dmat);

  return final_det;

}








