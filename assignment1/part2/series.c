#include <math.h>
#include <stdio.h>


double prod(int n, double a, double r);
double sum(int n, double a, double r);



int main(void){
	//variables
	double S0s, S0p, S1s, S1p, S2s, S2p; //sum for case 1,2,3, p or s denotes sum or product
	int i;
	
	//creating a loop that runs from 1 to 3
	for(i=0;i<3;i++){
		switch(i){
			case 0:
				//set n = 10000 etc
				//calculate Sn using sum function
				//calculate Sn using product function
				//return them and their difference or some little analysis
				S0s = sum(10000, 2.0, 0.01);
				S0p = prod(10000, 2.0, 0.01);
				printf("sum is %f and prod is %f\n", S0s, S0p);
				break;
			
			case 1:
				//same for diff n etc
				S0s = sum(500, 0.01, 1.1);
				S0p = prod(500, 0.01, 1.1);
				printf("sum is %f and prod is %f\n", S0s, S0p);

				break;


			case 2:
				//same for last n
				S0s = sum(100, 0.0001, 2.0);
				S0p = prod(100, 0.0001, 2.0);
				printf("sum is %f and prod is %f\n", S0s, S0p);
				
				break;		
		}



				
	}



  return 0;
} 
//============================================================


//functions to calculate Sn
double sum(int n, double a, double r){
	
	int i;
	double Sn;


	for(i=0;i<n+1;i++){
		Sn += a*pow(r,i);	
	}

  
  return Sn;
}



//need to come up with a better name
double prod(int n, double a, double r){
	
	double Sn;

	Sn = ((a)*(1-pow(r, n+1)))/(1-r);


  return Sn;
}

