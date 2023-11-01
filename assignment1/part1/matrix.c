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
	int i, j;
	double matrix[4][4];// = {};
	
	i = 0;
	j = 0; 
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			matrix[i][j] = 1/(double) (j+i+1);
			//printf("matrix[%d][%d] = %f\n", i, j, matrix[i][j]);
		}
	}
	
	//printing the matrix
	for(i=0;i<4;i++){
		printf("%f  %f  %f  %f\n",matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]);
	}
	
	/*calling the function that calculates 
    the determinant of a 3x3 matrix */
    double det4;
	det4 =  cramers(matrix);
	printf("\nthe det of the 4x4 matrix is %f\n", det4);	




	return 0;
}




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
 * the dets of which will be calculated*/
double cramers(double matrix[4][4]){
	//declaring the 4 submatricies and coeffcienets
	//this need to multiply the det of 3x3 by this so possibly
	//dont actually need these here, can call in the main
	double a = matrix[0][0];
	double b = matrix[0][1];
	double c = matrix[0][2];
	double d = matrix[0][3];
	
	double amat[3][3], bmat[3][3], cmat[3][3], dmat[3][3];
	
	int i = 0; int j = 0;
	//filling the submatricies
	//in all of these i and j correspond to the 4x4 indicies
	//these al have to map to different 3x3 indices 
	//amatrix
	for(i=1;i<4;i++){
		for(j=1;j<4;j++){		
			amat[i-1][j-1] = matrix[i][j];
		}
	}
	

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

/*now that I have the four matricies required I can 
calulate the determinatnes of them and get the final determinant
*/
double final_det;

final_det = a * det3(amat)
			- b * det3(bmat)
			+ c * det3(cmat)
			- d * det3(dmat);

return final_det;

}








