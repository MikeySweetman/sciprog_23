//Integrating tan(x) from 0 to pi/3 using the trapezoidal rule

//including packages (dunno if they're called packages rewrite this)
#include  <math.h>
#include <stdio.h>

int main(void){
	//declaring variables
	int i;
	double a, b, N, endpoints, prefac, result;
	double x, y, sum;               //variables just for calculating values in general


	//setting values of a, b, N
	a = 0;
	b = M_PI/3.0;
	N = 12;	

	//First part of the sum
	x = tan(0);
	y = tan(M_PI/3.0);
	endpoints = x + y;


	//loop to generate 11 equidistant points in (0, pi/3)
	x = 0;
	y = 0;
	sum = 0;
	for(i = 0; i < N - 1; i++){ 		//-2 need N-1 points AND count starts from 0
		x += (M_PI/3.0)/12.0;
		sum += 2*tan(x);
		
		//printf("x = %f\nsum = %f\ni = %d\n\n", x, sum, i);	//checking the outputs
	}

	sum += endpoints;	//final result of sum before prefactor multiplication

	 
	//computing prefactor
	prefac = (b - a)/(2*N);


	//computing final result
	result = prefac*sum;	
	
	printf("result of trapezoidal rule integration is %f\n",result);

	
	//comparing against log(2)
	x = 0;
	y = 0;
	
	y = log(2);
	printf("exact value of integration is %f\n", y);
	x = y - result;

	printf("the error in integration is %f\n", x);
	
	//calculating percentage error, not needed
	/*	
	x = 0;
	x = fabs(((result - y)/(y))*(100));
	printf("percentage error is %f%\n", x);	
	*/

	return 0;
}
