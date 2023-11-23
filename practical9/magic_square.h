#include <stdio.h>

int isMagicSquare(int ** square, const int n){
	//eliminate case where n is negative
	if(n<0){
		return 0;
	}

	//M is the sum of every row, column and the main and secondary diagonals
	int M = (n * (n*n + 1))/2;
	printf("M = %d\n", M);


	int i, j;
	//checking that every row and column adds up to M
	for(i=0;i<n;i++){
		int rowSum = 0;
		int colSum = 0;
		for(j=0;j<n;j++){
			rowSum += square[i][j];
			colSum += square[j][i];
		}
		printf("i = %d, rowSum = %d, colSum = %d\n", i, rowSum, colSum);
		if(rowsum != M || colSum != M){
			return 0;
		}
	}

	
	//checking that the main and secondary diagonals add up to M
 	//if all checks pass, it is a magic square
 	int diagSum = 0;
	int secDiagSum = 0;
	
	for(i=0;i<n;i++){
		diagSum += square[i][j];
		secDiagSum += square[i][n - i - 1];
	}
	
	printf("diagSum = %d, secDiagSum = %d\n", diagSum, secDiagSum);
	if(diagSum !=M || secDiagSum != M){
		return 0;
	}

	//if all checks passed
	return 1;



}
