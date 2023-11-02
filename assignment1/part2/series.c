#include <math.h>
#include <stdio.h>


double prod(int n, double a, double r);
double sum(int n, double a, double r);



int main(void){
	//variables
	double sumres, prodres; //results for sum and product function
	int i;
	
	/*
	 * creating a loop that runs from 1 to 3
	 * each loop the value of i will trigger
	 * a different case in the switch block
	 * and three different Sn will be calculated 
	 * on each iteration
	 */
	for(i=0;i<3;i++){
		switch(i){
			case 0:
				sumres = sum(10000, 2.0, 0.01);
				prodres = prod(10000, 2.0, 0.01);
				printf("result for sum is %f and for product is %f\n", sumres, prodres);
				break;
			
			case 1:
				//same for diff n etc
				sumres = sum(500, 0.01, 1.1);
				prodres = prod(500, 0.01, 1.1);
				printf("result for sum is %f and for product is %f\n", sumres, prodres);
				break;

			case 2:
				//same for last n
				sumres = sum(100, 0.0001, 2.0);
				prodres = prod(100, 0.0001, 2.0);
				printf("result for sum is %f and for product is %f\n", sumres, prodres);
				break;		
		}
	}
		
	//now I am writing the analysis in a print func
 	printf("\n\nAs can be seen in the above results, the growth of a geometric series Sn\nis dominated by the value of r, rather than the values of a or n\n");	
	
    printf("\nwhen r < 1 the series is convergent, when r > 1 the series diverges\n");

  return 0;
} 
//============================================================


//functions to calculate Sn
double sum(int n, double a, double r){
	
	int i = 0;
	double Sn = 0;


	for(i=0;i<n+1;i++){
		Sn += a*pow(r,i);	
	}

  
  return Sn;
}


//product function
double prod(int n, double a, double r){
	
	double Sn = 0;

	Sn = ((a)*(1-pow(r, n+1)))/(1-r);


  return Sn;
}

