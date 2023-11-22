#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int factorial(int n);

int main(void){
	
	int i, order;
	double e, *terms;

	//enter polynomial order
	printf("Enter the required polynomial order\n");
	if(scanf("%d", &order) !=1 ){
		printf("Didn't enter a number\n");
		return 1;
	}

	//allocate space depending on n
	terms = malloc(order*sizeof(double));
	for(i=0;i<order;i++){
		terms[i] = 1.0/(double)factorial(i+1);
		printf("e term for order %d polynomial is %1.14lf\n", i+1, terms[i]);
	}


	e = 1.0;
	for(i=0;i<order;i++){
		e += terms[i];
	} 
		
	free(terms);

	printf("e is estimated as %.10lf, with error of %e\n", e, e-exp(1.0));


  return 0;
}

//function
int factorial(int n){
	if(n<0){
		printf("Error, negative number passed into factorial.\n");
		return(-1);
	}
	
	else if(n==0) {return 1;}
	else{return(n*factorial(n-1));}
}

