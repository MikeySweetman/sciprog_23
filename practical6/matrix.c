#include <stdio.h>

int main(){
	
	int i, j, k; //loop counters
	int n = 5, p = 3, q = 4;	
	double A[n][p], B[p][q], C[n][q];
	
	//intialise A. B, C
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			A[i][j] =  i + j;
		}
	}

	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			B[i][j] =  i - j;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			C[i][j] = 0.0;
		}
	}		

	//doing the matrix multiplication
	for(i=0;i<n;i++){
		for(j=0;j<q;j++){
			for(k=0;k<p;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}	
		
	//printing the matricies
	printf("Matrix A:\n");
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			printf("%0.3f ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatrix B:\n");
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			printf("%0.3f ", B[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix C:\n");
	for(i=0;i<n;i++){
		for(j=0;j<p;j++){
			printf("%0.3f ", C[i][j]);
		}
		printf("\n");
	}



  return 0;
}
